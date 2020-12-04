/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/requests/pldm_bios_attr_requests.C $             */
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

/** @file  pldm_bios_attr_requests.C
 *  @brief This file contains the implementations of the APIs/wrappers for
 *         PLDM BIOS Attribute request operations.
 */

// system headers
#include <vector>
#include <sys/msg.h>

// non-pldm /include headers
#include <mctp/mctp_message_types.H>

// pldm /include/ headers
#include <pldm/pldm_const.H>
#include <pldm/pldmif.H>
#include <pldm/pldm_errl.H>
#include <pldm/pldm_reasoncodes.H>
#include <pldm/pldm_request.H>
#include <pldm/requests/pldm_bios_attr_requests.H>

// pldm /src/ headers
#include "../common/pldmtrace.H"

// This is the name of the outgoing PLDM message queue.
extern const char* VFS_ROOT_MSG_PLDM_REQ_OUT;

namespace PLDM
{

errlHndl_t getBiosTable(const pldm_bios_table_types i_type,
                        std::vector<uint8_t>& o_table)
{
    PLDM_ENTER("getBiosTable type = 0x%08x", i_type);

#ifndef __HOSTBOOT_RUNTIME
    msg_q_t msgQ = msg_q_resolve(VFS_ROOT_MSG_PLDM_REQ_OUT);
    assert(msgQ != nullptr,
            "Bug! PLDM Req Out Message queue did not resolve properly!");
#else
    msg_q_t msgQ = nullptr;
#endif

    pldm_get_bios_table_req  bios_table_req
    {
        .transfer_handle = 0, // (0 if transfer op is FIRSTPART)
        .transfer_op_flag = PLDM_GET_FIRSTPART, // transfer op flag
        .table_type= i_type // attribute handle
    };

    errlHndl_t errl = nullptr;

    // start with clean output vector
    o_table.clear();

    do
    {
        /* Make the getBiosTable request and get the response message bytes */
        std::vector<uint8_t> response_bytes;

        {
            errl =
              sendrecv_pldm_request<PLDM_GET_BIOS_TABLE_REQ_BYTES> (
                  response_bytes,
                  msgQ,
                  encode_get_bios_table_req,
                  DEFAULT_INSTANCE_ID,
                  bios_table_req.transfer_handle,
                  bios_table_req.transfer_op_flag,
                  bios_table_req.table_type);

            if (errl)
            {
                PLDM_ERR("getBiosTable: Error occurred trying to send pldm request.");
                break;
            }
        }
        pldm_get_bios_table_resp  response { };
        size_t table_data_offset = 0;

        errl =
            decode_pldm_response(decode_get_bios_table_resp,
                                  response_bytes,
                                  &response.completion_code,
                                  &response.next_transfer_handle,
                                  &response.transfer_flag,
                                  &table_data_offset);

        if (errl)
        {
            PLDM_ERR("getBiosTable: Error occurred trying to decode pldm response on pass");
            break;
        }

        if (response.completion_code != PLDM_SUCCESS)
        {
            pldm_msg* const pldm_response =
              reinterpret_cast<pldm_msg*>(response_bytes.data());
            const uint64_t response_hdr_data = pldmHdrToUint64(*pldm_response);

            /*
             * @errortype  ERRL_SEV_UNRECOVERABLE
             * @moduleid   MOD_GET_BIOS_TABLE
             * @reasoncode RC_BAD_COMPLETION_CODE
             * @userdata1  Completion code
             * @userdata2  Response Header Data
             * @devdesc    Software problem, PLDM transaction failed
             * @custdesc   A software error occurred during system boot
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 MOD_GET_BIOS_TABLE,
                                 RC_BAD_COMPLETION_CODE,
                                 response.completion_code,
                                 response_hdr_data,
                                 ErrlEntry::NO_SW_CALLOUT);
            addBmcErrorCallouts(errl);

            break;
        }

        /* If these assertions fail, then the other end is trying to do a
         * multipart transfer, which we do not support. */
        assert(response.transfer_flag == PLDM_START_AND_END,
               "Expected PLDM response transfer flag to be PLDM_START_AND_END "
               "got %d",
               response.transfer_flag);

        assert(response.next_transfer_handle == 0,
               "Expected PLDM next data transfer handle to be 0, got %d",
               response.next_transfer_handle);

        o_table.insert(o_table.begin(),
                        (response_bytes.data() + sizeof(pldm_msg_hdr) + table_data_offset),
                        response_bytes.end());

        PLDM_DBG_BIN("Bios Table Found : ",
                     o_table.data() ,
                     o_table.size());

    } while(false);

        PLDM_EXIT("getBiosTable");

    return errl;
}

/** @brief Retrieves one BIOS Attribute from the BMC.
 *
 * @param[in] i_bios_attr_handle
 *                The handle for the BIOS Attr to retrieve.
 * @param[out] o_attrVal
 *             Pointer to attribute value
 * @param[out] o_attrLen
 *             Length of the attribute value
 * @return Error if any, otherwise nullptr.
 */
errlHndl_t getBiosAttrFromHandle(const bios_handle_t i_bios_attr_handle,
                                 std::vector<uint8_t>& o_attrVal)
{
    PLDM_ENTER("getBiosAttrFromHandle");
    PLDM_DBG("Making request for Bios Attr 0x%08x from the BMC", i_bios_attr_handle);

#ifndef __HOSTBOOT_RUNTIME
    msg_q_t msgQ = msg_q_resolve(VFS_ROOT_MSG_PLDM_REQ_OUT);
    assert(msgQ != nullptr,
            "Bug! PLDM Req Out Message queue did not resolve properly!");
#else
    msg_q_t msgQ = nullptr;
#endif

    variable_field attribute_data { };
    errlHndl_t errl = nullptr;

    pldm_get_bios_attribute_current_value_by_handle_req  bios_attr_req
    {
        .transfer_handle = 0, // (0 if transfer op is FIRSTPART)
        .transfer_op_flag = PLDM_GET_FIRSTPART, // transfer op flag
        .attribute_handle= i_bios_attr_handle // attribute handle
    };

    // start with clean output vector
    o_attrVal.clear();

    do
    {
        /* Make the getBiosAttrFromHandle request and get the response message bytes */
        std::vector<uint8_t> response_bytes;

        {
            errl =
              sendrecv_pldm_request<PLDM_GET_BIOS_ATTR_CURR_VAL_BY_HANDLE_REQ_BYTES> (
                  response_bytes,
                  msgQ,
                  encode_get_bios_attribute_current_value_by_handle_req,
                  DEFAULT_INSTANCE_ID,
                  bios_attr_req.transfer_handle,
                  bios_attr_req.transfer_op_flag,
                  bios_attr_req.attribute_handle);

            if (errl)
            {
                PLDM_ERR("getBiosAttrFromHandle: Error occurred trying to send pldm request.");
                break;
            }
        }

        pldm_get_bios_attribute_current_value_by_handle_resp  response { };

        errl =
            decode_pldm_response(decode_get_bios_attribute_current_value_by_handle_resp,
                                  response_bytes,
                                  &response.completion_code,
                                  &response.next_transfer_handle,
                                  &response.transfer_flag,
                                  &attribute_data);

        if (errl)
        {
            PLDM_ERR("getBiosAttrFromHandle: Error occurred trying to decode pldm response on pass");
            break;
        }

        if (response.completion_code != PLDM_SUCCESS)
        {
            pldm_msg* const pldm_response =
              reinterpret_cast<pldm_msg*>(response_bytes.data());
            const uint64_t response_hdr_data = pldmHdrToUint64(*pldm_response);

            /*
             * @errortype  ERRL_SEV_UNRECOVERABLE
             * @moduleid   MOD_GET_BIOS_ATTR_FROM_HANDLE
             * @reasoncode RC_BAD_COMPLETION_CODE
             * @userdata1  Completion code
             * @userdata2  Response Header Data
             * @devdesc    Software problem, PLDM transaction failed
             * @custdesc   A software error occurred during system boot
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 MOD_GET_BIOS_ATTR_FROM_HANDLE,
                                 RC_BAD_COMPLETION_CODE,
                                 response.completion_code,
                                 response_hdr_data,
                                 ErrlEntry::NO_SW_CALLOUT);
            addBmcErrorCallouts(errl);

            break;
        }

        if(attribute_data.length == 0)
        {
            PLDM_ERR("getBiosAttrFromHandle: We were given attribute data of length zero from the BMC");
            pldm_msg* const pldm_response =
              reinterpret_cast<pldm_msg*>(response_bytes.data());
            const uint64_t response_hdr_data = pldmHdrToUint64(*pldm_response);
            /*
             * @errortype  ERRL_SEV_UNRECOVERABLE
             * @moduleid   MOD_GET_BIOS_ATTR_FROM_HANDLE
             * @reasoncode RC_INVALID_LENGTH
             * @userdata1  Attribute Handle
             * @userdata2  Response Header Data
             * @devdesc    Software problem, PLDM transaction failed
             * @custdesc   A software error occurred during system boot
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 MOD_GET_BIOS_ATTR_FROM_HANDLE,
                                 RC_INVALID_LENGTH,
                                 i_bios_attr_handle,
                                 response_hdr_data,
                                 ErrlEntry::NO_SW_CALLOUT);
            addBmcErrorCallouts(errl);
            break;
        }

        /* If these assertions fail, then the other end is trying to do a
         * multipart transfer, which we do not support. */
        assert(response.transfer_flag == PLDM_START_AND_END,
               "Expected PLDM response transfer flag to be PLDM_START_AND_END "
               "got %d",
               response.transfer_flag);

        assert(response.next_transfer_handle == 0,
               "Expected PLDM next data transfer handle to be 0, got %d",
               response.next_transfer_handle);

        o_attrVal.insert(o_attrVal.begin(),
                         attribute_data.ptr,
                         attribute_data.ptr + attribute_data.length);
        PLDM_DBG_BIN("Attribute Data Found : ",
                     o_attrVal.data(),
                     o_attrVal.size());
    } while (false);

    PLDM_EXIT("getBiosAttrFromHandle");

    return errl;
}
}