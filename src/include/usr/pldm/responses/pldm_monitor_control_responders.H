/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/responses/pldm_monitor_control_responders.H $ */
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

/* @file  pldm_monitor_control_responders.H
 *
 * @brief Contains definitions for PLDM message handlers for requests in the
 *        Platform Monitor & Control category (see DSP0248 v1.0.1 for details).
 */

#ifndef PLDM_MONITOR_CONTROL_RESPONDERS_H__
#define PLDM_MONITOR_CONTROL_RESPONDERS_H__

#include <sys/msg.h>
#include <errl/errlentry.H>

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
 * @param[in] i_payload_len  Length of PLDM message payload
 * @return    errlHndl_t     Error if any, otherwise nullptr.
 */
errlHndl_t handleGetPdrRequest(msg_q_t i_msgQ, const pldm_msg* i_msg, size_t i_payload_len);

/* @brief handlePdrRepoChangeEventRequest
 *
 *        Handler for PDR Repository Change Event requests. (See DSP0248 v1.2.0
 *        section 16.14 for details.)
 *
 * @param[in] i_msgQ         Handle to MCTP outbound request message queue
 * @param[in] i_msg          The PLDM message received
 * @param[in] i_payload_len  Length of PLDM message payload
 * @return errlHndl_t        Error if any, otherwise nullptr.
 */
errlHndl_t handlePdrRepoChangeEventRequest(msg_q_t i_msgQ,
                                           const pldm_msg* i_msg,
                                           size_t i_payload_len);

/* @brief handleSetStateEffecterStatesRequest
 *
 *        Handler for Set State Effecter States requests. (See DSP0248 v1.2.0
 *        section 22.5 for details.)
 *
 * @param[in] i_msgQ         Handle to MCTP outbound request message queue
 * @param[in] i_msg          The PLDM message received
 * @param[in] i_payload_len  Length of PLDM message payload
 * @return errlHndl_t        Error if any, otherwise nullptr.
 */
errlHndl_t handleSetStateEffecterStatesRequest(msg_q_t i_msgQ,
                                               const pldm_msg* i_msg,
                                               size_t i_payload_len);

/* @brief Handler for Get State Sensor Readings requests. (See DSP0248 v1.2.0
 *        section 20.2 for details.)
 *
 * @param[in] i_msgQ         Handle to MCTP outbound request message queue
 * @param[in] i_msg          The PLDM message received
 * @param[in] i_payload_len  Length of PLDM message payload
 * @return errlHndl_t        Error if any, otherwise nullptr.
 */
errlHndl_t handleGetStateSensorReadingsRequest(msg_q_t i_msgQ,
                                               const pldm_msg* i_msg,
                                               size_t i_payload_len);

/* @brief Handler for Set State Effecter requests for OCC state effecters.
 *
 * @param[in] i_occ          The OCC target.
 * @param[in] i_msgQ         Handle to MCTP outbound request message queue
 * @param[in] i_msg          PLDM message received
 * @param[in] i_payload_len  Length of PLDM message payload
 * @param[in] i_req          Decoded PLDM request.
 * @return errlHndl_t        Error if any, otherwise nullptr.
 */
errlHndl_t handleOccSetStateEffecterRequest(TARGETING::Target* i_occ,
                                            msg_q_t i_msgQ,
                                            const pldm_msg* i_msg,
                                            size_t i_payload_len,
                                            const pldm_set_state_effecter_states_req& i_req);

/* @brief Handler for Set State Effecter requests for graceful shutdown.
 *
 * @param[in] i_sys          System target
 * @param[in] i_msgQ         Handle to MCTP outbound request message queue
 * @param[in] i_msg          PLDM message received
 * @param[in] i_payload_len  Length of PLDM message payload
 * @param[in] i_req          Decoded PLDM request.
 * @return errlHndl_t        Error if any, otherwise nullptr.
 */
errlHndl_t handleGracefulShutdownRequest(TARGETING::Target* i_sys,
                                         msg_q_t i_msgQ,
                                         const pldm_msg* i_msg,
                                         size_t i_payload_len,
                                         const pldm_set_state_effecter_states_req& i_req);

/* @brief Handler for Get State Sensor Readings requests for FRU functional state sensors.
 *
 * @param[in] i_target       The FRU target for the sensor.
 * @param[in] i_msgQ         Handle to MCTP outbound request message queue
 * @param[in] i_msg          PLDM message received
 * @param[in] i_payload_len  Length of PLDM message payload
 * @param[in] i_req          Decoded PLDM request.
 * @return errlHndl_t        Error if any, otherwise nullptr.
 */
errlHndl_t handleFunctionalStateSensorGetRequest(TARGETING::Target* i_target,
                                                 msg_q_t i_msgQ,
                                                 const pldm_msg* i_msg,
                                                 size_t i_payload_len,
                                                 const pldm_get_state_sensor_readings_req& i_req);

/* @brief Handler for Get State Sensor Readings requests for OCC state sensor.
 *
 * See handleFunctionalStateSensorGetRequest for parameter documentation.
 */
errlHndl_t handleOccStateSensorGetRequest(TARGETING::Target* i_occ,
                                          msg_q_t i_msgQ,
                                          const pldm_msg* i_msg,
                                          size_t i_payload_len,
                                          const pldm_get_state_sensor_readings_req& i_req);

/* @brief Handler for Get State Sensor Readings requests for graceful shutdown.
 *
 * See handleFunctionalStateSensorGetRequest for parameter documentation.
 */
errlHndl_t handleGracefulShutdownSensorGetRequest(TARGETING::Target* i_target,
                                                  msg_q_t i_msgQ,
                                                  const pldm_msg* i_msg,
                                                  size_t i_payload_len,
                                                  const pldm_get_state_sensor_readings_req& i_req);

/* @brief handleSetEventReceiverRequest
 *
 *        Handler for Set Event Receiver request. (See DSP0248 v1.2.0a
 *        section 16.4 for details.)
 *
 * @param[in] i_msgQ         Handle to MCTP outbound request message queue
 * @param[in] i_msg          The PLDM message received
 * @param[in] i_payload_len  Length of PLDM message payload
 * @return errlHndl_t        Error if any, otherwise nullptr.
 */
errlHndl_t handleSetEventReceiverRequest(msg_q_t i_msgQ,
                                         const pldm_msg* i_msg,
                                         size_t i_payload_len);
}

#endif
