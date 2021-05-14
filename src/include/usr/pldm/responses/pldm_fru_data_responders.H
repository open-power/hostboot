/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/responses/pldm_fru_data_responders.H $   */
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

/* @file  pldm_fru_data_responders.H
 *
 * @brief Contains definitions for PLDM message handlers for requests in the
 *        Fru Data category (see DSP0257 v1.0.0 for details).
 */

#ifndef PLDM_FRU_DATA_RESPONDERS_H__
#define PLDM_FRU_DATA_RESPONDERS_H__

// Standard library
#include <map>
#include <vector>

// PLDM
#include <pldm/extended/hb_pdrs.H>
#include <pldm/requests/pldm_fru_requests.H>

// Targeting
#include <targeting/common/target.H>

// Miscellaneous
#include <sys/msg.h>
#include <errl/errlentry.H>

struct pldm_msg;

namespace PLDM
{

/* @brief handleGetFruRecordTableMetadataRequest
 *
 *        Handler for getFruRecordTableMetadata requests. (See DSP0257 v1.0.0
 *        section 9.2.2 for details.)
 *
 * @param[in] i_msgQ          Handle to the MCTP outbound message queue
 * @param[in] i_msg           getFruRecordTableMetadata request message object
 * @param[in] i_payload_len   Length of payload in i_msg
 * @return    errlHndl_t      Error if any, otherwise nullptr.
 */
errlHndl_t handleGetFruRecordTableMetadataRequest(msg_q_t i_msgQ,
                                                  const pldm_msg* i_msg,
                                                  size_t i_payload_len);

/* @brief handleGetFruRecordTableRequest
 *
 *        Handler for getFruRecordTable requests. (See DSP0257 v1.0.0
 *        section 9.2.3 for details.)
 *
 * @param[in] i_msgQ          Handle to the MCTP outbound message queue
 * @param[in] i_msg           getFruRecordTable request message object
 * @param[in] i_payload_len   Length of payload in i_msg
 * @return    errlHndl_t      Error if any, otherwise nullptr.
 */
errlHndl_t handleGetFruRecordTableRequest(msg_q_t i_msgQ,
                                          const pldm_msg* i_msg,
                                          size_t i_payload_len);

}

#endif
