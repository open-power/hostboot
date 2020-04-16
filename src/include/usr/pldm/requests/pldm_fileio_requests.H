/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/requests/pldm_fileio_requests.H $        */
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
/* @file pldm_fileio_requests.H
 *
 * This file defines the APIs/wrappers for PLDM File IO operations
 */

#ifndef PLDM_FILEIO_REQUESTS_H
#define PLDM_FILEIO_REQUESTS_H

#include <errl/errlentry.H>
#include <vector>

namespace PLDM {

/**
 * @brief Requests a File Table containing the list of files available and
 *        their attributes from the BMC via a PLDM request.
 *
 * @param[out] o_table the file table in binary format; will be cleared before
 *             populating with output data.
 * @return nullptr on success; non-nullptr on error. Other outputs are
 *         invalidated on error.
 */
errlHndl_t getFileTable(std::vector<uint8_t>& o_table);

} // namespace PLDM

#endif // PLDM_FILEIO_REQUESTS_H
