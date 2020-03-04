/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/requests/pldm_fru_requests.H $           */
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
#ifndef PLDM_FRU_REQEUSTS_H
#define PLDM_FRU_REQUESTS_H

/**
 * @file pldm_fru_requests.H
 *
 * @brief This header provides the interfaces required for FRU related PLDM requests to the BMC
 *
 */

#include <errl/errlentry.H>

namespace PLDM
{

struct pldm_fru_record_table_metadata_t
{
    // Major Version of Fru Record Table format
    uint8_t  fruDataVerMajor = 0xFF;
    // Minor Version of Fru Record Table format
    uint8_t  fruDataVerMinor = 0xFF;
    // Max allowed size for Fru Record Table in bytes
    // (needed if we intend to send setFruTable cmds)
    uint32_t fruTableMaxSize = 0x00000000;
    // Current length of Fru Record Table in bytes
    uint32_t fruTableSize    = 0x00000000;
    // Total number of Record Set Identifiers in table
    uint16_t rsiCount        = 0x0000;
    // Total number of Fru Records in table
    uint16_t recordCount     = 0x0000;
    // CRC-32 checksum of fru data type (excludes pad bytes)
    uint32_t checksum        = 0x00000000;

    pldm_fru_record_table_metadata_t() {};
} __attribute__((packed));

/**
  * @brief Make PLDM request to get the Fru Record Table meta data
  *        from the BMC
  *
  * @param[out] o_table_metadata Meta Data returned from
  *             getFruRecordTableMetaData request
  *
  * @note Caller is responsible for allocating pldm_fru_record_table_metadata
  *       and freeing the space. This function is just filling out fields
  *
  * @return returns error log if error occurs, otherwise returns nullptr
  */
errlHndl_t getFruRecordTableMetaData(
                  pldm_fru_record_table_metadata_t&  o_table_metadata);

/**
  * @brief Make PLDM request to get the Fru Record Table
  *
  * @param[in] i_tableBufferLen Expected length of the Fru Record Table in
  *                             bytes. It is expected that o_tableBuffer has
  *                             been allocated to store this many bytes. This
  *                             number is used to verify the resp we get from the
  *                             getFruRecordTable request matches what we expect
  * @param[out] o_tableBuffer   Pointer to a buffer of at least i_tableBufferLen.
  *                             this buffer will be filled w/ data defined in
  *                              Table 7 of DSP0257 v1.0.0
  *
  * @return returns error log if error occurs, otherwise returns nullptr
  */
errlHndl_t getFruRecordTable(size_t i_tableBufferLen,
                             uint8_t* o_tableBuffer);
}
#endif