/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/base/hb_patch.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2024                             */
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

/**
 *  @file hb_patch.H
 *  @brief Header for utility functions that have been removed in recent updates
 *   to the libpldm repo but if removed would require intensive rewriting for our current code.
 *   Code here should be evaluated in the future, this is meant to be a temporary fix.
 */

#ifndef HB_PLDM_PATCH_H
#define HB_PLDM_PATCH_H

#include <errl/errlentry.H>
#include <pldm/pldm_const.H>
#include <openbmc/pldm/libpldm/include/libpldm/pdr.h>
#include <openbmc/pldm/libpldm/include/libpldm/oem/ibm/file_io.h>
#include <targeting/common/utilFilter.H>

typedef struct pldm_pdr_record {
    uint32_t record_handle;
    uint32_t size;
    uint8_t *data;
    struct pldm_pdr_record *next;
    bool is_remote;
    uint16_t terminus_handle;
} pldm_pdr_record;

typedef struct pldm_pdr {
    uint32_t record_count;
    uint32_t size;
    pldm_pdr_record *first;
    pldm_pdr_record *last;
} pldm_pdr;

struct pldm_write_file_by_type_req {
        struct pldm_read_write_file_by_type_req common_req;
        uint8_t write_data[1];
} __attribute__((packed));

/** @brief Encode WriteFileByType commands request data
 *
 *  @param[in] instance_id - Message's instance id
 *  @param[in] command - PLDM command
 *  @param[in] file_type - Type of the file
 *  @param[in] file_handle - A handle to the file
 *  @param[in] offset -  Offset to the file at which the write should begin
 *  @param[in] length -  Number of bytes to be written
 *  @param[in] write_file_data - Ptr to buffer with length equal to length param
 *  @param[out] msg - Message will be written to this
 *  @return pldm_completion_codes
 */
int hb_encode_write_file_by_type_req(uint8_t instance_id, uint8_t command,
				  uint16_t file_type, uint32_t file_handle,
				  uint32_t offset, uint32_t length,
				  const uint8_t * write_file_data,
				  struct pldm_msg *msg, size_t payload_length);

/** @brief Delete record using its record handle
 *
 *  @param[in] repo - opaque pointer acting as a PDR repo handle
 *  @param[in] record_handle - record handle of input PDR record
 *  @param[in] is_remote - if true, then the PDR is not from this terminus
 */
void pldm_delete_by_record_handle(pldm_pdr *repo, uint32_t record_handle,
                  bool is_remote);

#endif