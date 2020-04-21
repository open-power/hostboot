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

/**
 * @brief Requests a lid file from the BMC.
 *
 * @param[in] i_fileHandle the lid id (lid number) of the file
 * @param[in/out] io_numBytesToRead the number of bytes to read from the file.
 *                When the function returns, this will contain the number of
 *                bytes that were actually read. If the input is 0, the function
 *                will keep reading the data until BMC indicates that there is
 *                no more data to read.
 * @param[out] o_file the pointer to memory where the file is to be written
 * @return nullptr on success; non-nullptr on error
 */
errlHndl_t getLidFile(uint32_t i_fileHandle,
                      uint32_t& io_numBytesToRead,
                      uint8_t* o_file);

/**
 * @brief Requests a lid file starting with the specified offset from the BMC.
 *
 * @param[in] i_fileHandle the lid id (lid number) of the file
 * @param[in] i_offset the offset at which to start reading the lid file
 * @param[in/out] io_numBytesToRead the number of bytes to read from the file.
 *                When the function returns, this will contain the number of
 *                bytes that were actually read. If the input is 0, the function
 *                will keep reading the data until BMC indicates that there is
 *                no more data to read.
 * @param[out] o_file the pointer to memory where the file is to be written
 * @return nullptr on success; non-nullptr on error
 */
errlHndl_t getLidFileFromOffset(uint32_t i_fileHandle,
                                uint32_t i_offset,
                                uint32_t& io_numBytesToRead,
                                uint8_t* o_file);

} // namespace PLDM

#endif // PLDM_FILEIO_REQUESTS_H
