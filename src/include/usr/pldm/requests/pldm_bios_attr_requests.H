/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/requests/pldm_bios_attr_requests.H $     */
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
#ifndef PLDM_BIOS_ATTR_REQUESTS_H
#define PLDM_BIOS_ATTR_REQUESTS_H

/** @file  pldm_bios_attr_requests.H
 *  @brief This file contains the declaration(s) of the function(s) that
 *         are used to perform PLDM BIOS requests to the BMC
 */

#include <errl/errlentry.H>
#include <openbmc/pldm/libpldm/bios_table.h>

namespace PLDM {

typedef uint16_t bios_handle_t;

/** @brief Retrieves one of the Bios Attribute Tables from the BMC
 *
 * @param[in] i_type
 *                Type of table to request. See bios.h for options
 * @param[out] o_table
  *                Expected to be empty on input, will be cleared
 *                 during the function. If no error then will
 *                 contain bios attribute table value when
 *                 function completes.
 * @return Error if any, otherwise nullptr.
 */
errlHndl_t getBiosTable(const pldm_bios_table_types i_type,
                        std::vector<uint8_t>& o_table);

/** @brief Given a pldm bios attribute handle, retrieves the BIOS Attribute
 *         Table Entry associated with it from the BMC.
 *
 * @param[in] i_bios_attr_handle
 *                The handle for the BIOS Attr to retrieve.
 * @param[out] o_attrVal
 *                 Expected to be empty on input, will be cleared
 *                 during the function. If no error then will
 *                 contain bios attribute table entry value when
 *                 function completes.
 * @return Error if any, otherwise nullptr.
 */
errlHndl_t getBiosAttrFromHandle(const bios_handle_t i_bios_attr_handle,
                                 std::vector<uint8_t>& o_attrVal);

}

#endif