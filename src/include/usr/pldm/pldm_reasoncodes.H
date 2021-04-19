/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/pldm_reasoncodes.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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
        MOD_PLDM_INVALID                             = 0x00, /**< Zero is an invalid module id */
        MOD_GET_FRU_METADATA                         = 0x01, // getFruRecordTableMetaData
        MOD_GET_FRU_TABLE                            = 0x02, // getFruRecordTable
        MOD_GET_PDR_REPO                             = 0x03, // getRemotePdrRepository
        MOD_ROUTE_MESSAGES                           = 0x04, // routeInboundMsg
        MOD_PLDM_REQUESTER                           = 0x05, // handle_outbound_req_messages
        MOD_DECODE_RESPONSE                          = 0x06, // decode_pldm_response
        MOD_MAKE_PLDM_REQUEST                        = 0x07, // make_pldm_request
        MOD_HANDLE_GET_PDR                           = 0x08, // handleGetPdrRequest
        MOD_SEND_PLDM_RESPONSE                       = 0x09, // send_pldm_response, decode_pldm_request
        MOD_HANDLE_INBOUND_REQ                       = 0x0A, // handle_inbound_req
        MOD_SEND_REPO_CHANGED_EVENT                  = 0x0B, // sendRepositoryChangedEvent
        MOD_GET_FILE_TABLE                           = 0x0C, // getFileTable
        MOD_GET_LID_FILE                             = 0x0D, // getLidFile
        MOD_HANDLE_REPO_CHANGED_EVENT                = 0x0E, // handlePdrRepoChangeEventRequest
        MOD_PDR_MANAGER                              = 0x0F, // pdr_manager.C
        MOD_PLDM_FRU_TO_IPZ                          = 0x10, // generate_ipz_formatted_vpd
        MOD_GENERATE_VTOC_RECORD                     = 0x11, // generate_vtoc_record
        MOD_GENERATE_PT_ENTRIES                      = 0x12, // generate_pt_entries
        MOD_CACHE_REMOTE_FRU_VPD                     = 0x13, // get fru records and add to eecache
        MOD_GET_LOCATION_CODE                        = 0x14, // getRecordSetLocationCode
        MOD_SEND_SENSOR_STATE_CHANGED_EVENT          = 0x15, // sendSensorStateChangedEvent
        MOD_HANDLE_SET_STATE_EFFECTER_STATES_REQUEST = 0x16, // handleSetStateEffecterStatesRequest
        MOD_PLDM_ENTITY_IDS                          = 0x17, // pldm_entity_ids.C
        MOD_ADD_OCC_PDRS                             = 0x18, // addOccStateControlPdrs
        MOD_SEND_SET_STATE_EFFECTER_STATES_REQUEST   = 0x19, // sendSetStateEffecterStatesRequest
        MOD_GET_BIOS_ATTR_FROM_HANDLE                = 0x1A, // getBiosAttrFromHandle
        MOD_GET_BIOS_TABLE                           = 0x1B, // getBiosTable
        MOD_GET_CURRENT_VALUE                        = 0x1C, // getCurrentAttrValue
        MOD_GET_HYPERVISOR_MODE                      = 0x1D, // getHypervisorMode
        MOD_GET_DEBUG_CONSOLE_ENABLED                = 0x1E, // getDebugConsoleEnabled
        MOD_LOOKUP_VALUE_IN_STRING_TABLE             = 0x1F, // lookupEnumAttrValuesInStringTable
        MOD_SYSTEM_ENUM_ATTR_LOOKUP                  = 0x20, // systemEnumAttrLookup
        MOD_WRITE_LID_FILE                           = 0x21, // writeLidFileFromOffset
        MOD_GET_MFG_FLAGS                            = 0x22, // getMfgFlags
        MOD_GET_TID                                  = 0x23, // getTID
        MOD_ADD_INVENTORY_PDRS                       = 0x24, // addFruInventoryPdrs
        MOD_HANDLE_SET_OCC_STATE                     = 0x25, // handleOccSetStateEffecterRequest
        MOD_GET_LMB_SIZE                             = 0x26, // getLmbSize
        MOD_FIND_TERMINATION_STATUS_ID               = 0x27, // findTerminationStatusEffecterId
        MOD_GET_POWER_LIMIT                          = 0x28, // getPowerLimit
        MOD_HANDLE_OCC_STATE_SENSOR_GET_REQUEST      = 0x29, // handleOccStateSensorGetRequest
        MOD_HANDLE_SET_EVENT_RECEIVER                = 0x2a, // handleSetEventReceiverRequest
        MOD_RESET_WATCHDOG_TIMER                     = 0x2b, // resetWatchdogTimer
    };

    enum PLDMReasonCode
    {
        RC_MSG_DECODE_FAIL          = PLDM_COMP_ID | 0x01,
        RC_MSG_ENCODE_FAIL          = PLDM_COMP_ID | 0x02,
        RC_UNSUPPORTED_VERSION      = PLDM_COMP_ID | 0x03,
        RC_BAD_COMPLETION_CODE      = PLDM_COMP_ID | 0x04,
        RC_INVALID_LENGTH           = PLDM_COMP_ID | 0x05,
        RC_MCTP_FAIL                = PLDM_COMP_ID | 0x06,
        RC_SENDRECV_FAIL            = PLDM_COMP_ID | 0x07,
        RC_SEND_FAIL                = PLDM_COMP_ID | 0x08,
        RC_INVALID_MSG_CATEGORY     = PLDM_COMP_ID | 0x09,
        RC_INVALID_COMMAND          = PLDM_COMP_ID | 0x0A,
        RC_INVALID_MSG_TYPE         = PLDM_COMP_ID | 0x0B,
        RC_INVALID_HEADER           = PLDM_COMP_ID | 0x0C,
        RC_BAD_TRANSFER_FLAG        = PLDM_COMP_ID | 0x0D,
        RC_UNSUPPORTED_TYPE         = PLDM_COMP_ID | 0x0E,
        RC_INVALID_IPZ_FORMAT       = PLDM_COMP_ID | 0x0F,
        RC_INVALID_RSI_COUNT        = PLDM_COMP_ID | 0x10,
        RC_UNSUPPORTED_RECORD       = PLDM_COMP_ID | 0x11,
        RC_UNSUPPORTED_FIELD        = PLDM_COMP_ID | 0x12,
        RC_INVALID_RECORD_COUNT     = PLDM_COMP_ID | 0x13,
        RC_INVALID_LOCATION_CODE    = PLDM_COMP_ID | 0x14,
        RC_NO_LOCATION_CODE         = PLDM_COMP_ID | 0x15,
        RC_EXPECTED_UNIQUE_ENTITY   = PLDM_COMP_ID | 0x16,
        RC_NO_TARGET_FROM_RSID      = PLDM_COMP_ID | 0x17,
        RC_NO_ENTITY_FROM_RSID      = PLDM_COMP_ID | 0x18,
        RC_EXPECTED_UNIQUE_TARGET   = PLDM_COMP_ID | 0x19,
        RC_INVALID_EFFECTER_ID      = PLDM_COMP_ID | 0x1A,
        RC_INVALID_EFFECTER_STATE   = PLDM_COMP_ID | 0x1B,
        RC_MISSING_ENTITY_ID        = PLDM_COMP_ID | 0x1C,
        RC_OCC_RESET_TOO_SOON       = PLDM_COMP_ID | 0x1D,
        RC_OVERLONG_LOCATION_CODE   = PLDM_COMP_ID | 0x1E,
        RC_RECV_FAIL                = PLDM_COMP_ID | 0x1F,
        RC_MULTIPLE_AWAIT           = PLDM_COMP_ID | 0x20,
        RC_UNSUPPORTED_ATTRIBUTE    = PLDM_COMP_ID | 0x21,
        RC_NO_ATTRIBUTE_MATCH       = PLDM_COMP_ID | 0x22,
        RC_OUT_OF_RANGE             = PLDM_COMP_ID | 0x23,
        RC_NO_MATCH_IN_TABLE        = PLDM_COMP_ID | 0x24,
        RC_NOT_READY                = PLDM_COMP_ID | 0x25,
        RC_UNSUPPORTED_STRING_TYPE  = PLDM_COMP_ID | 0x26,
        RC_UNEXPECTED_STRING_SIZE   = PLDM_COMP_ID | 0x27,
        RC_TERM_LOCATOR_NOT_FOUND   = PLDM_COMP_ID | 0x28,
        RC_INVALID_STATE_QUERY_ID   = PLDM_COMP_ID | 0x29,
        RC_NO_STATE_QUERY_HANDLER   = PLDM_COMP_ID | 0x2A,
        RC_OCC_STATUS_NOT_AVAILABLE = PLDM_COMP_ID | 0x2B,
        RC_BAD_GLOBAL_ENABLE        = PLDM_COMP_ID | 0x2C,
        RC_BAD_WATCHDOG_VALUE       = PLDM_COMP_ID | 0x2D,
    };
}
#endif
