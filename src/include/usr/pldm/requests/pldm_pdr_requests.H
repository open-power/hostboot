/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/requests/pldm_pdr_requests.H $           */
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

/* @file pldm_pdr_requests.H
 *
 * Defines the interface for retrieving the BMC's list of PDRs.
 */

#ifndef PLDM_PDR_REQUESTS_H
#define PLDM_PDR_REQUESTS_H

#include <errl/errlentry.H>
#include <pldm/pldmif.H>

// Struct representing PDR repository (see DSP0248 v1.2.0, section 8)
struct pldm_pdr;

namespace TARGETING
{
class Target;
}

namespace PLDM
{

using pdr_handle_t = uint32_t;

static constexpr pdr_handle_t FIRST_PDR_HANDLE = 0,
                              NO_MORE_PDR_HANDLES = 0;

/* @brief Retrieves the PDRs from the BMC and adds them to the given
 *        repository.
 *
 * @param[io/out] io_repo     Pointer to a PDR repository to store the BMC PDRs in.
 *                            Must not be nullptr.
 * @return        errlHndl_t  Error if any, otherwise nullptr.
 */
errlHndl_t getRemotePdrRepository(pldm_pdr* io_repo);

/* @brief Send a "PDR Repository Changed Event" to the BMC.
 *
 * @param[in] i_repo        PDR Repository containing the changed PDRs
 *                          (must not be nullptr)
 * @param[in] i_handles     The set of PDRs which have been added to the repository.
 * @return errlHndl_t       Error if any, otherwise nullptr.
 */
errlHndl_t sendRepositoryChangedEvent(const pldm_pdr* i_repo,
                                      const std::vector<pdr_handle_t>& i_handles);

using sensor_state_t = uint8_t;
using sensor_id_t = uint16_t;
using effector_id_t = uint16_t;
using state_query_id_t = uint16_t; // Either a state sensor or effecter ID
using state_set_id_t = uint16_t;

/* @brief Send a Platform Event Message indicating a "Sensor State Changed"
 *        event to the BMC.
 *
 * @param[in] i_sensor_id      ID of the aggregate sensor that changed
 * @param[in] i_sensor_offset  Offset of the sensor within the aggregate sensor
 *                             that changed
 * @param[in] i_sensor_state   New state of the sensor
 * @return errlHndl_t          Error if any, otherwise nullptr.
 */
errlHndl_t sendSensorStateChangedEvent(sensor_id_t i_sensor_id,
                                       uint8_t i_sensor_offset,
                                       sensor_state_t i_sensor_state);

enum occ_state : sensor_state_t
{
    occ_state_stopped,
    occ_state_in_service
};

/* @brief Send a platform event indicating that the state of the OCC has changed
 *
 * @param[in] i_proc_target  The PROC target containing the relevant OCC
 * @param[in] i_new_state    The new state of the OCC
 * @return errlHndl_t        Error if any, otherwise nullptr
 */
errlHndl_t sendOccStateChangedEvent(const TARGETING::Target* i_proc_target,
                                    occ_state i_new_state);

/* @brief Send a platform event indicating the FRU's current functional state.
 *
 * @param[in] i_target      The FRU target.
 * @param[in] i_sensor_id   The FRU target's PLDM_STATE_SET_HEALTH_STATE sensor ID.
 * @param[in] i_functional  Whether the target is functional or not.
 * @return errlHndl_t       Error if any, otherwise nullptr.
 */
errlHndl_t sendFruFunctionalStateChangedEvent(const TARGETING::Target* i_target,
                                              state_query_id_t i_sensor_id,
                                              bool i_functional);

/* @brief Send a PLDM command notifying the BMC that Hostboot wants to be restarted
 *
 * @return errlHndl_t          Error if any, otherwise nullptr.
 */
errlHndl_t sendGracefulRestartRequest();
}

#endif
