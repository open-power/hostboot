/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/requests/pldm_pdr_requests.H $           */
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

/* @file pldm_pdr_requests.H
 *
 * Defines the interface for retrieving the BMC's list of PDRs.
 */

#ifndef PLDM_PDR_REQEUSTS_H
#define PLDM_PDR_REQUESTS_H

#include <memory>
#include <errl/errlentry.H>

// Struct representing PDR repository (see DSP0248 v1.2.0, section 8)
struct pldm_pdr;

namespace PLDM
{

using pldm_pdr_free_t = void(*)(pldm_pdr*);
using pldm_pdr_ptr = std::unique_ptr<pldm_pdr, pldm_pdr_free_t>;

/* @brief Retrieves the PDRs from the BMC and returns the repository containing
 *        them.
 *
 * @param[out] o_repo  Pointer to a new PDR repository containing the BMC PDRs.
 * @return errlHndl_t  Error if any, otherwise nullptr.
 */
errlHndl_t getRemotePdrRepository(pldm_pdr_ptr& o_repo);

}

#endif
