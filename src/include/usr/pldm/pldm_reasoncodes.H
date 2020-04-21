/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/pldm_reasoncodes.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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
#ifndef __PLDM_REASONCODES_H
#define __PLDM_REASONCODES_H

/**
 * @file pldm_reasoncodes.H
 *
 * @brief Reason codes and module ids for PLDM functionality
 *
 */

#include <hbotcompid.H>

namespace PLDM
{
    enum PLDMModuleId
    {
        MOD_PLDM_INVALID              = 0x00, /**< Zero is an invalid module id */
        MOD_GET_FRU_METADATA          = 0x01, // getFruRecordTableMetaData
        MOD_GET_FRU_TABLE             = 0x02, // getFruRecordTable
        MOD_GET_PDR_REPO              = 0x03, // getRemotePdrRepository
        MOD_ROUTE_MESSAGES            = 0x04, // routeInboundMsg
        MOD_PLDM_REQUESTER            = 0x05, // handle_outbound_req_messages
        MOD_DECODE_RESPONSE           = 0x06, // decode_pldm_response
        MOD_MAKE_PLDM_REQUEST         = 0x07, // make_pldm_request
        MOD_HANDLE_GET_PDR            = 0x08, // handleGetPdrRequest
        MOD_SEND_PLDM_RESPONSE        = 0x09, // send_pldm_response
        MOD_HANDLE_INBOUND_REQ        = 0x0A, // handle_inbound_req
        MOD_SEND_REPO_CHANGED_EVENT   = 0x0B, // sendRepositoryChangedEvent
        MOD_GET_FILE_TABLE            = 0x0C, // getFileTable
        MOD_GET_LID_FILE              = 0x0D, // getLidFile
    };

    enum PLDMReasonCode
    {
        RC_MSG_DECODE_FAIL      = PLDM_COMP_ID | 0x01,
        RC_MSG_ENCODE_FAIL      = PLDM_COMP_ID | 0x02,
        RC_UNSUPPORTED_VERSION  = PLDM_COMP_ID | 0x03,
        RC_BAD_COMPLETION_CODE  = PLDM_COMP_ID | 0x04,
        RC_INVALID_LENGTH       = PLDM_COMP_ID | 0x05,
        RC_MCTP_FAIL            = PLDM_COMP_ID | 0x06,
        RC_SENDRECV_FAIL        = PLDM_COMP_ID | 0x07,
        RC_SEND_FAIL            = PLDM_COMP_ID | 0x08,
        RC_INVALID_MSG_CATEGORY = PLDM_COMP_ID | 0x09,
        RC_INVALID_COMMAND      = PLDM_COMP_ID | 0x0A,
        RC_INVALID_MSG_TYPE     = PLDM_COMP_ID | 0x0B,
        RC_INVALID_HEADER       = PLDM_COMP_ID | 0x0C,
        RC_BAD_TRANSFER_FLAG    = PLDM_COMP_ID | 0x0D,
    };
}
#endif
