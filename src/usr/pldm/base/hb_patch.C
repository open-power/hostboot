/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/base/hb_patch.C $                                */
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

/** @file  hb_patch.C
 *  @brief This file contains deprecated APIs from the libpldm subtree
 * that are critical for Hostboot code. Eventually the pldm code should be
 * refactored to not use these APIs
 */

#include <vector>
#include <sys/msg.h>
// VFS_ROOT_MSG_PLDM_REQ_OUT
#include <sys/vfs.h>


#include <openbmc/pldm/libpldm/include/libpldm/base.h>
#include <openbmc/pldm/libpldm/include/libpldm/platform.h>
#include <openbmc/pldm/libpldm/include/libpldm/pdr.h>
#include <openbmc/pldm/libpldm/include/libpldm/oem/ibm/file_io.h>
// #include <pldm/pldm_request.H>
#include <pldm/pldm_trace.H>
#include "../common/pldm_utils.H"

#include <pldm/pldmif.H>
#include <hbotcompid.H>
#include <hwas/common/hwasCallout.H>
#include <pldm/pldm_errl.H>
#include <pldm/base/hb_patch.H>
#include <limits.h>
#include <util/misc.H>
#include <targeting/common/targetservice.H>

int hb_encode_write_file_by_type_req(uint8_t instance_id, uint8_t command,
          uint16_t file_type, uint32_t file_handle,
          uint32_t offset, uint32_t length,
          const uint8_t * write_file_data,
          struct pldm_msg *msg, size_t payload_length)
{
    if(write_file_data == NULL) {
        return PLDM_ERROR_INVALID_DATA;
    }

    int rc = encode_rw_file_by_type_req(instance_id, command,
                                        file_type, file_handle,
                                        offset, length,
                                        msg);

    if(rc != PLDM_SUCCESS){
        return rc;
    }

    struct pldm_write_file_by_type_req *req =
      (struct pldm_write_file_by_type_req *)msg->payload;

    memcpy(req->write_data, write_file_data,length);
    return rc;
}

void pldm_delete_by_record_handle(pldm_pdr *repo, uint32_t record_handle,
          bool is_remote)
{
  assert(repo != NULL);

  pldm_pdr_record *record = repo->first;
  pldm_pdr_record *prev = NULL;
  while (record != NULL) {
    pldm_pdr_record *next = record->next;
    struct pldm_pdr_hdr *hdr = (struct pldm_pdr_hdr *)record->data;
    if ((record->is_remote == is_remote) &&
  (hdr->record_handle == record_handle)) {
      if (repo->first == record) {
  repo->first = next;
      } else {
  prev->next = next;
      }
      if (repo->last == record) {
  repo->last = prev;
      }
      if (record->data) {
  free(record->data);
      }
      --repo->record_count;
      repo->size -= record->size;
      free(record);
      break;
    } else {
      prev = record;
    }
    record = next;
  }
}
