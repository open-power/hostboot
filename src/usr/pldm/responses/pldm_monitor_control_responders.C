/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/responses/pldm_monitor_control_responders.C $    */
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

/* @file  pldm_monitor_control_responders.C
 *
 * @brief Contains definitions for the PLDM Platform Monitor & Control message
 *        handlers.
 */

#include <pldm/responses/pldm_monitor_control_responders.H>

// PLDM
#include <pldm/pldm_errl.H>
#include <pldm/pldm_const.H>
#include <pldm/pldm_reasoncodes.H>
#include <pldm/pldm_response.H>
#include "../common/pldmtrace.H"

// Targeting
#include <targeting/common/utilFilter.H>

// libpldm headers from pldm subtree
#include <openbmc/pldm/libpldm/platform.h>
#include <openbmc/pldm/libpldm/base.h>
#include <openbmc/pldm/libpldm/state_set.h>

// PdrManager
#include <pldm/extended/pdr_manager.H>

// Misc
#include <errl/errlmanager.H>
#include <runtime/interface.h>
#include <htmgt/htmgt.H>

using namespace ERRORLOG;
using namespace TARGETING;

namespace
{

/* @brief find_proc_by_ordinal_id
 *
 * Find a present processor with the given ordinal ID.
 *
 * @param[in] i_ordinal_id  Ordinal ID of processor to search for
 * @return Target*          Pointer to the present processor
 *                          target with the given ordinal,
 *                          or nullptr if none found.
 */
Target* find_proc_by_ordinal_id(const ATTR_ORDINAL_ID_type i_ordinal_id)
{
    Target* result = nullptr;

    TargetHandleList procs;
    getClassResources(procs, CLASS_CHIP, TYPE_PROC, UTIL_FILTER_PRESENT);

    for (const auto proc : procs)
    {
        if (proc->getAttr<ATTR_ORDINAL_ID>() == i_ordinal_id)
        {
            result = proc;
            break;
        }
    }

    return result;
}

}

namespace PLDM
{

errlHndl_t handleGetPdrRequest(const msg_q_t i_msgQ,
                               const pldm_msg* const i_msg,
                               const size_t i_payload_len)
{
    PLDM_ENTER("handleGetPdrRequest");

    pldm_get_pdr_req pdr_req { };
    errlHndl_t errl = nullptr;
    std::vector<uint8_t> pdr_data;
    pdr_handle_t next_record_handle = 0;
    uint8_t pldm_response_code = PLDM_SUCCESS;

    do
    {
        {
            const int rc =
                decode_get_pdr_req(i_msg,
                                   i_payload_len,
                                   &pdr_req.record_handle,
                                   &pdr_req.data_transfer_handle,
                                   &pdr_req.transfer_op_flag,
                                   &pdr_req.request_count,
                                   &pdr_req.record_change_number);

            if (rc != PLDM_SUCCESS)
            {
                PLDM_ERR("Failed to decode getPDR request, rc = %d",
                         rc);

                /*
                 * @errortype  ERRL_SEV_UNRECOVERABLE
                 * @moduleid   MOD_HANDLE_GET_PDR
                 * @reasoncode RC_MSG_DECODE_FAIL
                 * @userdata1  RC returned from decode function
                 * @devdesc    Software problem, failed to decode PLDM getPDR request
                 * @custdesc   A software error occurred during system boot
                 */
                errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                     MOD_HANDLE_GET_PDR,
                                     RC_MSG_DECODE_FAIL,
                                     rc,
                                     0,
                                     ErrlEntry::NO_SW_CALLOUT);

                addBmcErrorCallouts(errl);
                errlCommit(errl, PLDM_COMP_ID);

                pldm_response_code = PLDM_ERROR_INVALID_DATA;
                break;
            }
        }

        if (pdr_req.data_transfer_handle != 0)
        {
            // We don't support multipart transfers
            PLDM_ERR("Got invalid data transfer handle 0x%x in getPDR request",
                     pdr_req.data_transfer_handle);
            pldm_response_code = PLDM_PLATFORM_INVALID_DATA_TRANSFER_HANDLE;
            break;
        }

        if (pdr_req.transfer_op_flag != PLDM_GET_FIRSTPART)
        {
            PLDM_ERR("Got invalid transfer op flag 0x%x in getPDR request",
                     pdr_req.transfer_op_flag);
            pldm_response_code = PLDM_PLATFORM_INVALID_TRANSFER_OPERATION_FLAG;
            break;
        }

        if (pdr_req.record_change_number != 0)
        {
            PLDM_ERR("Got invalid record change number 0x%x in getPDR request",
                     pdr_req.record_change_number);
            pldm_response_code = PLDM_PLATFORM_INVALID_RECORD_CHANGE_NUMBER;
            break;
        }

        pdr_handle_t record_handle = pdr_req.record_handle;

        const bool record_found
            = PLDM::thePdrManager().findPdr(record_handle,
                                            &pdr_data,
                                            next_record_handle);

        PLDM_INF("BMC requesting PDR handle 0x%08x, returning 0x%08x",
                 pdr_req.record_handle,
                 record_handle);

        if (!record_found)
        {
            PLDM_ERR("Got invalid record handle 0x%x in getPDR request",
                     pdr_req.record_handle);
            pldm_response_code = PLDM_PLATFORM_INVALID_RECORD_HANDLE;
            break;
        }
    } while (false);

    const size_t max_request_count = pdr_req.request_count;

    // If we found the PDR with the given record handle, we send back at
    // most the number of bytes that the client asked for.
    const uint32_t response_pdr_size
        = (pldm_response_code == PLDM_SUCCESS
           ? std::min(pdr_data.size(), max_request_count)
           : 0);

    errl =
        send_pldm_response<PLDM_GET_PDR_MIN_RESP_BYTES>
        (i_msgQ,
         encode_get_pdr_resp,
         response_pdr_size,
         i_msg->hdr.instance_id,
         pldm_response_code,
         next_record_handle,
         0, // No remaining data
         PLDM_START_AND_END,
         payload_length_placeholder_t(),
         pdr_data.data(),
         0); // CRC, not used for START_AND_END

    if (errl)
    {
        PLDM_ERR("Failed to encode and/or send getPDR response "
                 "(response size = %d, response code = 0x%x, "
                 "next record handle = 0x%08x)",
                 response_pdr_size, pldm_response_code,
                 next_record_handle);

        errl->collectTrace(PLDM_COMP_NAME);
    }

    PLDM_EXIT("handleGetPdrRequest");

    return errl;
}

errlHndl_t handlePdrRepoChangeEventRequest(const msg_q_t i_msgQ,
                                           const pldm_msg* const i_msg,
                                           const size_t i_payload_len)
{
    PLDM_ENTER("handlePdrRepoChangeEventRequest");

    errlHndl_t errl = nullptr;
    uint8_t response_code = PLDM_SUCCESS;

    // This do/while block is for decoding and verifying the request
    do
    {
        // All these variables except event_class are ignored, because we don't
        // support any other event than the PDR Repo Changed event, and even in
        // that case we don't need to read the event data (because we drop and
        // refresh the entire repo).

        uint8_t format_version = 0,
                tid = 0,
                event_class = 0;

        size_t event_data_offset = 0;

        errl = decode_pldm_request
            (decode_platform_event_message_req,
             i_msg,
             i_payload_len,
             &format_version,
             &tid,
             &event_class,
             &event_data_offset);

        if (errl)
        {
            PLDM_ERR("Failed to decode PLDM PDR Repository Changed Event request");
            errlCommit(errl, PLDM_COMP_ID);
            response_code = PLDM_ERROR;
            break;
        }

        if (event_class != PLDM_PDR_REPOSITORY_CHG_EVENT)
        {
            PLDM_ERR("Invalid event class %d in platform event handler",
                     event_class);

            /*
             * @errortype  ERRL_SEV_INFORMATIONAL
             * @moduleid   MOD_HANDLE_REPO_CHANGED_EVENT
             * @reasoncode RC_INVALID_MSG_TYPE
             * @userdata1  Expected event class
             * @userdata2  Actual event class
             * @devdesc    Software problem, invalid event class received from BMC
             * @custdesc   A software error occurred during system boot
             */
            errl = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                 MOD_HANDLE_REPO_CHANGED_EVENT,
                                 RC_INVALID_MSG_TYPE,
                                 PLDM_PDR_REPOSITORY_CHG_EVENT,
                                 event_class,
                                 ErrlEntry::NO_SW_CALLOUT);

            addBmcErrorCallouts(errl);
            errlCommit(errl, PLDM_COMP_ID);
            response_code = PLDM_ERROR;
            break;
        }
    } while (false);

    // This do/while is for sending a response
    do
    {
        errl =
            send_pldm_response<PLDM_PLATFORM_EVENT_MESSAGE_RESP_BYTES>
            (i_msgQ,
             encode_platform_event_message_resp,
             0, // No payload after the header
             i_msg->hdr.instance_id,
             response_code,
             PLDM_EVENT_NO_LOGGING);

        if (errl)
        {
            PLDM_ERR("Failed to send PLDM PDR Repository Changed event response");
            errl->collectTrace(PLDM_COMP_NAME);
            break;
        }
#ifndef __HOSTBOOT_RUNTIME
        if (response_code == PLDM_SUCCESS)
        {
            errl = thePdrManager().notifyBmcPdrRepoChanged();

            if (errl)
            {
                PLDM_ERR("Failed to notify PDR manager that BMC PDR repository changed");
                errl->collectTrace(PLDM_COMP_NAME);
                break;
            }
        }
#endif
    } while (false);

    PLDM_EXIT("handlePdrRepoChangeEventRequest");

    return errl;
}

errlHndl_t handleSetStateEffecterStatesRequest(const msg_q_t i_msgQ,
                                               const pldm_msg* const i_msg,
                                               const size_t i_payload_len)
{
    PLDM_ENTER("handleSetStateEffecterStatesRequest");

    errlHndl_t errl = nullptr;
    uint8_t response_code = PLDM_SUCCESS;

    /* Decode and verify the request */

    Target* occ_proc = nullptr;
    pldm_set_state_effecter_states_req req = { };

    do
    {
        errl = decode_pldm_request(decode_set_state_effecter_states_req,
                                   i_msg,
                                   i_payload_len,
                                   &req.effecter_id,
                                   &req.comp_effecter_count,
                                   req.field);

        if (errl)
        {
            PLDM_ERR("Failed to decode PLDM Set State Effecter States request");
            errlCommit(errl, PLDM_COMP_ID);
            response_code = PLDM_ERROR;
            break;
        }

        // We use the ordinal ID of the processor as the sensor ID for the state
        // sensor.
        const ATTR_ORDINAL_ID_type proc_ordinal_id = req.effecter_id;

        occ_proc = find_proc_by_ordinal_id(proc_ordinal_id);

        if (!occ_proc)
        {
            PLDM_ERR("Received invalid state effecter ID 0x%x",
                     req.effecter_id);

            /*
             * @errortype  ERRL_SEV_PREDICTIVE
             * @moduleid   MOD_HANDLE_SET_STATE_EFFECTER_STATES_REQUEST
             * @reasoncode RC_INVALID_EFFECTER_ID
             * @userdata1  Invalid effecter ID
             * @devdesc    Software problem, invalid effecter ID from BMC
             * @custdesc   A software error occurred during system boot
             */
            errl = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                                 MOD_HANDLE_SET_STATE_EFFECTER_STATES_REQUEST,
                                 RC_INVALID_EFFECTER_ID,
                                 req.effecter_id,
                                 0,
                                 ErrlEntry::NO_SW_CALLOUT);

            addBmcErrorCallouts(errl);
            errlCommit(errl, PLDM_COMP_ID);
            response_code = PLDM_PLATFORM_INVALID_EFFECTER_ID;
            break;
        }

        if (req.comp_effecter_count != 1
            || !req.field[0].set_request
            || (req.field[0].effecter_state != PLDM_STATE_SET_BOOT_RESTART_CAUSE_WARM_RESET
                && req.field[0].effecter_state != PLDM_STATE_SET_BOOT_RESTART_CAUSE_HARD_RESET))
        {
            PLDM_ERR("Received invalid state effecter set request "
                     "(effecter 0x%x, PROC = 0x%08x, effecter count = %d, "
                     "set_request = %d, effecter_state = %d)",
                     req.effecter_id,
                     get_huid(occ_proc),
                     req.comp_effecter_count,
                     req.field[0].set_request,
                     req.field[0].effecter_state);

            /*
             * @errortype  ERRL_SEV_PREDICTIVE
             * @moduleid   MOD_HANDLE_SET_STATE_EFFECTER_STATES_REQUEST
             * @reasoncode RC_INVALID_EFFECTER_STATE
             * @userdata1  HUID of the PROC with the OCC that was being reset
             * @userdata2[0:15]  Set request field of first effecter
             * @userdata2[16:31] Effecter state of first effecter
             * @userdata2[32:63] Effecter count
             * @devdesc    Software problem, invalid effecter state from BMC
             * @custdesc   A software error occurred during system boot
             */
            errl = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                                 MOD_HANDLE_SET_STATE_EFFECTER_STATES_REQUEST,
                                 RC_INVALID_EFFECTER_STATE,
                                 get_huid(occ_proc),
                                 TWO_UINT16_ONE_UINT32_TO_UINT64(req.field[0].set_request,
                                                                 req.field[0].effecter_state,
                                                                 req.comp_effecter_count),
                                 ErrlEntry::NO_SW_CALLOUT);

            addBmcErrorCallouts(errl);
            errlCommit(errl, PLDM_COMP_ID);
            response_code = PLDM_PLATFORM_INVALID_STATE_VALUE;
            break;
        }

        /* Act on the request if the request was valid */

        if (occ_proc->getAttr<ATTR_HOMER_PHYS_ADDR>() == 0)
        {
            PLDM_ERR("handleSetStateEffecterStatesRequest: Failed to restart the OCC "
                     "on PROC HUID = 0x%08x at IPL time "
                     "(request too early - HOMER_PHYS_ADDR is 0)",
                     get_huid(occ_proc));

            /*
             * @errortype  ERRL_SEV_PREDICTIVE
             * @moduleid   MOD_HANDLE_SET_STATE_EFFECTER_STATES_REQUEST
             * @reasoncode RC_OCC_RESET_TOO_SOON
             * @userdata1  HUID of the PROC with the OCC that was being reset
             * @devdesc    Software problem, BMC requested OCC reset too soon
             * @custdesc   A software error occurred during system boot
             */
            errl = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                                 MOD_HANDLE_SET_STATE_EFFECTER_STATES_REQUEST,
                                 RC_OCC_RESET_TOO_SOON,
                                 get_huid(occ_proc),
                                 0,
                                 ErrlEntry::NO_SW_CALLOUT);

            addBmcErrorCallouts(errl);
            errlCommit(errl, PLDM_COMP_ID);
            response_code = PLDM_ERROR_NOT_READY;
            break;
        }

    } while (false);

    /* Respond to the request notifying the BMC that we are going to attempt the OCC reset */
    if (!errl) {
        errl =
            send_pldm_response<PLDM_SET_STATE_EFFECTER_STATES_RESP_BYTES>
            (i_msgQ,
             encode_set_state_effecter_states_resp,
             0, // No payload after the header
             i_msg->hdr.instance_id,
             response_code);

        if (errl)
        {
            PLDM_ERR("Failed to send PLDM PDR Repository Changed event response");
            errl->collectTrace(PLDM_COMP_NAME);
        }
    }

    PLDM_INF("Restarting OCC on PROC HUID = 0x%08x...", get_huid(occ_proc));

    HTMGT::processOccReset(occ_proc);

    PLDM_INF("Restarted OCC on PROC HUID = 0x%08x", get_huid(occ_proc));

    PLDM_EXIT("handleSetStateEffecterStatesRequest");

    return errl;
}

}
