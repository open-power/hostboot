/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/common/pldm_utils.C $                            */
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

/**
* @file pldm_utils.C
*
* @brief Source code for utility functions defined in pldmif.H
*/

#include <pldm/pldmif.H>
#include <cstring>

namespace PLDM
{
uint64_t pldmHdrToUint64(const pldm_msg& i_pldmMsg)
{
    uint64_t request_hdr_data = 0;
    const pldm_msg_hdr* const request_hdr = &i_pldmMsg.hdr;

    static_assert(sizeof(pldm_msg_hdr) <= sizeof(request_hdr_data),
                  "pldm_msg_hdr is too big for a 64-bit integer");

    memcpy(&request_hdr_data, request_hdr, sizeof(pldm_msg_hdr));
    return request_hdr_data;
}
}
