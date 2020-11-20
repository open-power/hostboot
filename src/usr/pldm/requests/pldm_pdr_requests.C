/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/requests/pldm_pdr_requests.C $                   */
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

/* @file pldm_pdr_requests.C
 *
 * @brief Implementation of PLDM PDR-related requester functions.
 */

// Standard library
#include <vector>
#include <cstdint>
#include <memory>

// Error logs
#include <errl/errlentry.H>

// Console display
#include <console/consoleif.H>

// IPC
#include <sys/msg.h>

// libpldm headers from pldm subtree
#include <openbmc/pldm/libpldm/platform.h>
#include <openbmc/pldm/libpldm/pdr.h>
#include <openbmc/pldm/libpldm/state_set.h>

// Hostboot PLDM/MCTP
#include <mctp/mctp_message_types.H>
#include <pldm/pldm_const.H>
#include <pldm/pldmif.H>
#include <pldm/pldm_errl.H>
#include <pldm/requests/pldm_pdr_requests.H>
#include <pldm/pldm_reasoncodes.H>
#include <pldm/pldm_request.H>
#include <pldm/extended/pdr_manager.H>
#include "../common/pldmtrace.H"
#include <pldm/pldm_util.H>

// This is the name of the outgoing PLDM message queue.
extern const char* VFS_ROOT_MSG_PLDM_REQ_OUT;

namespace
{

using namespace PLDM;
using namespace ERRORLOG;

// (see DSP0248 v1.2.0, section 8 for general information about PDRs)
struct pdr
{
    pdr_handle_t record_handle;
    std::vector<uint8_t> data;
};

/* @brief Retrieves one PDR from the BMC.
 *
 * @param[in] i_msgQ
 *            A handle to the PLDM message queue
 * @param[in/out] io_pdr_record_handle
 *                The record handle for the PDR to retrieve. Set to the next PDR
 *                in the repository as an output parameter.  Output not valid if
 *                error returned.
 * @param[out] o_pdr
 *             The PDR from the BMC. Output not valid if error returned.
 *             Pre-existing data will be cleared from the container.
 * @return Error if any, otherwise nullptr.
 */
errlHndl_t getPDR(const msg_q_t i_msgQ,
                  pdr_handle_t& io_pdr_record_handle,
                  pdr& o_pdr)
{
    PLDM_ENTER("getPDR");

    PLDM_INF("Making request for PDR 0x%08x from the BMC", io_pdr_record_handle);

    struct get_pdr_response
    {
        uint8_t completion_code = 0;
        pdr_handle_t next_record_hndl = 0;
        pdr_handle_t next_data_transfer_hndl = 0;
        uint8_t transfer_flag = 0;
        uint16_t resp_cnt = 0;
        std::vector<uint8_t> record_data;
        uint8_t transfer_crc = 0;
    };

    o_pdr.data.clear();

    pldm_get_pdr_req pdr_req
    {
        .record_handle = io_pdr_record_handle,
        .data_transfer_handle = 0, // (0 if transfer op is FIRSTPART)
        .transfer_op_flag = PLDM_GET_FIRSTPART, // transfer op flag
        .request_count = SHRT_MAX, // Don't limit the size of the PDR
        .record_change_number = 0 // record change number (0 for first request)
    };

    errlHndl_t errl = nullptr;

    do
    {
        /* Make the getPDR request and get the response message bytes */

        std::vector<uint8_t> response_bytes;

        {
            errl =
              sendrecv_pldm_request<PLDM_GET_PDR_REQ_BYTES> (
                  response_bytes,
                  i_msgQ,
                  encode_get_pdr_req,
                  DEFAULT_INSTANCE_ID,
                  pdr_req.record_handle,
                  pdr_req.data_transfer_handle,
                  pdr_req.transfer_op_flag,
                  pdr_req.request_count,
                  pdr_req.record_change_number);

            if (errl)
            {
                PLDM_ERR("getPDR: Error occurred trying to send pldm request.");
                break;
            }
        }

        /* Decode the message twice; the first time, the payload buffer will be
         * null so that the decoder will simply tell us how big the buffer
         * should be. Then we create a suitable payload buffer and call the
         * decoder again, this time with the real buffer so that it can fill it
         * with data from the message. */

        get_pdr_response response { };
        uint8_t* payload_buffer = nullptr;

        for (int i = 0; i < 2; ++i)
        {
            errl =
                decode_pldm_response(decode_get_pdr_resp,
                                     response_bytes,
                                     &response.completion_code,
                                     &response.next_record_hndl,
                                     &response.next_data_transfer_hndl,
                                     &response.transfer_flag,
                                     &response.resp_cnt,
                                     payload_buffer,
                                     response.record_data.size(),
                                     &response.transfer_crc);

            if (errl)
            {
                PLDM_ERR("getPDR: Error occurred trying to decode pldm response on pass %i", i);
                break;
            }

            response.record_data.resize(response.resp_cnt);
            payload_buffer = response.record_data.data();
        }

        if (errl)
        {
            // Message decoding failed; break out of the block;
            break;
        }

        /* Once we decode the message, then we can add the PDR to the caller's
         * PDR byte buffer and return. */

        if (response.completion_code != PLDM_SUCCESS)
        {
            // @TODO RTC 251835: libpldm does not have an enumeration for the
            // REPOSITORY_UPDATE_IN_PROGRESS completion code, but if it adds
            // that, we can retry the transfer here.

            pldm_msg* const pldm_response =
              reinterpret_cast<pldm_msg*>(response_bytes.data());
            const uint64_t response_hdr_data = pldmHdrToUint64(*pldm_response);

            /*
             * @errortype  ERRL_SEV_UNRECOVERABLE
             * @moduleid   MOD_GET_PDR_REPO
             * @reasoncode RC_BAD_COMPLETION_CODE
             * @userdata1  Completion code
             * @userdata2  Response Header Data
             * @devdesc    Software problem, PLDM transaction failed
             * @custdesc   A software error occurred during system boot
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 MOD_GET_PDR_REPO,
                                 RC_BAD_COMPLETION_CODE,
                                 response.completion_code,
                                 response_hdr_data,
                                 ErrlEntry::NO_SW_CALLOUT);

            // Call out service processor / BMC firmware as high priority
            errl->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                      HWAS::SRCI_PRIORITY_HIGH);

            // Call out Hostboot firmware as medium priority
            errl->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                       HWAS::SRCI_PRIORITY_MED );

            errl->collectTrace(PLDM_COMP_NAME);

            break;
        }

        /* If these assertions fail, then the other end is trying to do a
         * multipart transfer, which we do not support. */

        assert(response.transfer_flag == PLDM_START_AND_END,
               "Expected PLDM response transfer flag to be PLDM_START_AND_END "
               "got %d",
               response.transfer_flag);

        assert(response.next_data_transfer_hndl == 0,
               "Expected PLDM next data transfer handle to be 0, got %d",
               response.next_data_transfer_hndl);

        o_pdr.data.assign(begin(response.record_data),
                          begin(response.record_data) + response.resp_cnt);

        const auto pdr_hdr = reinterpret_cast<pldm_pdr_hdr*>(o_pdr.data.data());
        o_pdr.record_handle = le32toh(pdr_hdr->record_handle);

        io_pdr_record_handle = response.next_record_hndl;
    } while (false);

    PLDM_EXIT("getPDR");

    return errl;
}

/* @brief Retrieves all the BMC PDRs.
 *
 * @param[out] o_pdrs  The list of PDRs from the BMC
 * @return errlHndl_t  Error if any, otherwise nullptr.
 */
errlHndl_t getAllPdrs(std::vector<pdr>& o_pdrs)
{
    const msg_q_t msgQ = MSG_Q_RESOLVE("getAllPdrs", VFS_ROOT_MSG_PLDM_REQ_OUT);

    pdr_handle_t pdr_handle = FIRST_PDR_HANDLE; // getPDR updates this for us
    errlHndl_t errl = nullptr;

    do
    {
        pdr result_pdr { };

        errl = getPDR(msgQ, pdr_handle, result_pdr);

        if (errl)
        {
            break;
        }

        o_pdrs.push_back(result_pdr);
    } while (pdr_handle != NO_MORE_PDR_HANDLES);

    return errl;
}

}

namespace PLDM
{

errlHndl_t getRemotePdrRepository(pldm_pdr* const io_repo)
{
    std::vector<pdr> pdrs;

    const errlHndl_t errl = getAllPdrs(pdrs);

    if (!errl)
    {
        for (const auto& pdr : pdrs)
        {
            pldm_pdr_add(io_repo,
                         pdr.data.data(),
                         pdr.data.size(),
                         pdr.record_handle,
                         false);
        }
    }

    return errl;
}

errlHndl_t sendRepositoryChangedEvent(const pldm_pdr* const i_repo,
                                      const std::vector<pdr_handle_t>& i_handles)
{
    PLDM_ENTER("sendRepositoryChangedEvent");

    assert(i_repo != nullptr,
           "i_repo is nullptr in sendRepositoryChangedEvent");

    errlHndl_t errl = nullptr;

    if (i_handles.empty())
    {
        PLDM_INF("No PDRs have changed, not sending Repository Changed Event to BMC");
    }
    else
    {
        /* Encode the platform change event data */

        std::vector<uint8_t> event_data_bytes;

        {
            const uint8_t event_data_operation = PLDM_RECORDS_ADDED;
            const size_t num_changed_pdrs = i_handles.size();

            assert(num_changed_pdrs <= UINT8_MAX,
                   "Too many changed PDRs; max supported %d, got %d",
                   UINT8_MAX, static_cast<int>(num_changed_pdrs));

            const uint8_t number_of_change_entries = num_changed_pdrs;
            const uint32_t* const change_entries = i_handles.data();

            size_t actual_change_records_size = 0;
            pldm_pdr_repository_chg_event_data* event_data = nullptr;

            /** The first time around this loop, event_data is nullptr which
             * instructs the encoder to not actually do the encoding, but rather
             * fill out actual_change_records_size with the correct size, stop and
             * return PLDM_SUCCESS. Then we allocate the proper amount of memory and
             * call the encoder again, which will cause it to actually encode the
             * message. **/
            for (int i = 0; i < 2; ++i)
            {
                const int rc
                    = encode_pldm_pdr_repository_chg_event_data(FORMAT_IS_PDR_HANDLES,
                                                                1, // only one change record (RECORDS_ADDED)
                                                                &event_data_operation,
                                                                &number_of_change_entries,
                                                                &change_entries,
                                                                event_data,
                                                                &actual_change_records_size,
                                                                event_data_bytes.size());

                assert(rc == PLDM_SUCCESS,
                       "encode_pldm_pdr_repository_chg_event_data failed in "
                       " sendRepositoryChangedEvent, rc is %d",
                       rc);

                event_data_bytes.resize(actual_change_records_size);
                event_data
                    = reinterpret_cast<pldm_pdr_repository_chg_event_data*>(event_data_bytes.data());
            }
        }

        /* Send the event request */

        do
        {
            {
                const msg_q_t msgQ = MSG_Q_RESOLVE("sendRepositoryChangedEvent", VFS_ROOT_MSG_PLDM_REQ_OUT);

                std::vector<uint8_t> response_bytes;

                // Value from DSP0248 section 16.6
                const uint8_t DSP0248_V1_2_0_PLATFORM_EVENT_FORMAT_VERSION = 1;

                errl = sendrecv_pldm_request<PLDM_PLATFORM_EVENT_MESSAGE_MIN_REQ_BYTES>
                    (response_bytes,
                     event_data_bytes,
                     msgQ,
                     encode_platform_event_message_req,
                     DEFAULT_INSTANCE_ID,
                     DSP0248_V1_2_0_PLATFORM_EVENT_FORMAT_VERSION,
                     thePdrManager().hostbootTerminusId(),
                     PLDM_PDR_REPOSITORY_CHG_EVENT,
                     event_data_bytes.data(),
                     event_data_bytes.size());

                if (errl)
                {
                    PLDM_INF("Failed to send/recv repository change event");
                    break;
                }

                uint8_t completion_code = PLDM_SUCCESS;
                uint8_t status = 0; // Don't really care about this status, it
                                    // just tells us what happened with the
                                    // logging (see DSP0248 1.2.0 section 16.6
                                    // for details)

                errl =
                    decode_pldm_response(decode_platform_event_message_resp,
                                         response_bytes,
                                         &completion_code,
                                         &status);

                if (errl)
                {
                    PLDM_INF("Failed to decode repository change event");
                    break;
                }

                if (completion_code != PLDM_SUCCESS)
                {
                    PLDM_INF("Event completion code is not PLDM_SUCCESS, is %d (status = %d)",
                             completion_code,
                             status);

                    /*
                     * @errortype  ERRL_SEV_UNRECOVERABLE
                     * @moduleid   MOD_SEND_REPO_CHANGED_EVENT
                     * @reasoncode RC_BAD_COMPLETION_CODE
                     * @userdata1  Completion code returned from BMC
                     * @userdata2  Status code returned from BMC
                     * @devdesc    Software problem, PLDM Repo Changed notification unsuccessful
                     * @custdesc   A software error occurred during system boot
                     */
                    errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                         MOD_SEND_REPO_CHANGED_EVENT,
                                         RC_BAD_COMPLETION_CODE,
                                         completion_code,
                                         status,
                                         ErrlEntry::NO_SW_CALLOUT);
                    errl->collectTrace(PLDM_COMP_NAME);
                    addBmcErrorCallouts(errl);
                    break;
                }

                PLDM_INF("Sent PDR Repository Changed Event successfully (code is %d, status is %d)",
                         completion_code, status);
            }
        } while (false);
    }

    PLDM_EXIT("sendRepositoryChangedEvent");

    return errl;
}

errlHndl_t sendSensorStateChangedEvent(const sensor_id_t i_sensor_id,
                                       const uint8_t i_sensor_offset,
                                       const sensor_state_t i_sensor_state)
{
    PLDM_ENTER("sendSensorStateChangedEvent (sensor id = %d, offset = %d, state = %d)",
               i_sensor_id, i_sensor_offset, i_sensor_state);

    errlHndl_t errl = nullptr;

    /* Encode the platform change event data */

    std::vector<uint8_t> event_data_bytes;

    {
        size_t actual_event_data_size = 0;
        pldm_sensor_event_data* event_data = nullptr;

        for (int i = 0; i < 2; ++i)
        {
            const int rc
                = encode_sensor_event_data(event_data,
                                                event_data_bytes.size(),
                                                i_sensor_id,
                                                PLDM_STATE_SENSOR_STATE,
                                                i_sensor_offset,
                                                i_sensor_state,
                                                i_sensor_state,
                                                &actual_event_data_size);

            assert(rc == PLDM_SUCCESS,
                   "encode_sensor_event_data failed in "
                   " sendSensorStateChangedEvent, rc is %d",
                   rc);

            event_data_bytes.resize(actual_event_data_size);
            event_data
                = reinterpret_cast<pldm_sensor_event_data*>(event_data_bytes.data());
        }
    }

    /* Send the event request */

    do
    {
        {
            const msg_q_t msgQ = MSG_Q_RESOLVE("sendSensorStateChangedEvent",
                                               VFS_ROOT_MSG_PLDM_REQ_OUT);

            std::vector<uint8_t> response_bytes;

            // Value from DSP0248 section 16.6
            const uint8_t DSP0248_V1_2_0_PLATFORM_EVENT_FORMAT_VERSION = 1;

            errl = sendrecv_pldm_request<PLDM_PLATFORM_EVENT_MESSAGE_MIN_REQ_BYTES>
                (response_bytes,
                 event_data_bytes,
                 msgQ,
                 encode_platform_event_message_req,
                 DEFAULT_INSTANCE_ID,
                 DSP0248_V1_2_0_PLATFORM_EVENT_FORMAT_VERSION,
                 thePdrManager().hostbootTerminusId(),
                 PLDM_SENSOR_EVENT,
                 event_data_bytes.data(),
                 event_data_bytes.size());

            if (errl)
            {
                PLDM_INF("Failed to send/recv sensor state change event");
                break;
            }

            uint8_t completion_code = PLDM_SUCCESS;
            uint8_t status = 0;

            errl =
                decode_pldm_response(decode_platform_event_message_resp,
                                     response_bytes,
                                     &completion_code,
                                     &status);

            if (errl)
            {
                PLDM_INF("Failed to decode sensor state change response");
                break;
            }

            if (completion_code != PLDM_SUCCESS)
            {
                PLDM_INF("Event completion code is not PLDM_SUCCESS, is %d (status = %d)",
                         completion_code,
                         status);

                /*
                 * @errortype  ERRL_SEV_UNRECOVERABLE
                 * @moduleid   MOD_SEND_SENSOR_STATE_CHANGED_EVENT
                 * @reasoncode RC_BAD_COMPLETION_CODE
                 * @userdata1  Completion code returned from BMC
                 * @userdata2  Status code returned from BMC
                 * @devdesc    Software problem, Sensor State Changed notification unsuccessful
                 * @custdesc   A software error occurred during system boot
                 */
                errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                     MOD_SEND_SENSOR_STATE_CHANGED_EVENT,
                                     RC_BAD_COMPLETION_CODE,
                                     completion_code,
                                     status,
                                     ErrlEntry::NO_SW_CALLOUT);
                errl->collectTrace(PLDM_COMP_NAME);
                addBmcErrorCallouts(errl);
                break;
            }

            PLDM_INF("Sent Sensor State Changed Event successfully (code is %d, status is %d)",
                     completion_code, status);
        }
    } while (false);

    PLDM_EXIT("sendSensorStateChangedEvent");

    return errl;
}

errlHndl_t sendOccStateChangedEvent(const TARGETING::Target* const i_proc_target,
                                    const occ_state i_new_state)
{
    // The Processor entities only have one sensor associated with them, and it
    // is at index 0.
    constexpr int OCC_STATE_SENSOR_INDEX = 0;

    sensor_state_t new_occ_state = 0;

    switch (i_new_state)
    {
    case occ_state_stopped:
        new_occ_state = PLDM_STATE_SET_OPERATIONAL_RUNNING_STATUS_STOPPED;
        break;
    case occ_state_in_service:
        new_occ_state = PLDM_STATE_SET_OPERATIONAL_RUNNING_STATUS_IN_SERVICE;
        break;
    default:
        assert(false, "Invalid state %d given to sendOccStateChangedEvent",
               i_new_state);
    }

    return sendSensorStateChangedEvent(i_proc_target->getAttr<TARGETING::ATTR_ORDINAL_ID>(),
                                       OCC_STATE_SENSOR_INDEX,
                                       new_occ_state);
}

errlHndl_t sendSetStateEffecterStatesRequest(
                                    const effector_id_t i_effecter_id,
                                    const std::vector<set_effecter_state_field>& i_state_fields)
{
    PLDM_ENTER("sendSetStateEffecterStatesRequest");

    struct set_effecter_state_response
    {
        uint8_t completion_code = 0;
    };

    std::vector<uint8_t> response_bytes;

    assert(!i_state_fields.empty(),
           "Trying to write empty state fields list to pldm state effecter");
    constexpr uint8_t max_fields = 8;
    assert(i_state_fields.size() <= max_fields,
           "Trying to write more than max fields allowed to pldm state effecter");

    pldm_set_state_effecter_states_req effecter_req
    {
        .effecter_id = i_effecter_id,
        .comp_effecter_count = static_cast<uint8_t>(i_state_fields.size()),
        .field = {0}
    };

    memcpy(effecter_req.field,
           i_state_fields.data(),
           sizeof(i_state_fields[0]) * i_state_fields.size());

    PLDM_DBG_BIN("effecter req:" , static_cast<void*>(&effecter_req), sizeof(pldm_set_state_effecter_states_req));


    errlHndl_t errl = nullptr;

    do
    {
        /* Make the effecter state request */
        const msg_q_t msgQ = MSG_Q_RESOLVE("sendSetStateEffecterStatesRequest",
                                          VFS_ROOT_MSG_PLDM_REQ_OUT);
        std::vector<uint8_t> response_bytes;

        errl =
            sendrecv_pldm_request<PLDM_SET_STATE_EFFECTER_STATES_REQ_BYTES> (
              response_bytes,
              msgQ,
              encode_set_state_effecter_states_req,
              DEFAULT_INSTANCE_ID, // 0x00
              effecter_req.effecter_id,
              effecter_req.comp_effecter_count,
              effecter_req.field);

        if (errl)
        {
            PLDM_ERR("setEffecter: Error occurred trying to send pldm request.");
            break;
        }

        // pack the PLDM header of the response into a uint64_t which can
        // be used for error logging / debugging
        uint64_t response_hdr_data =
          pldmHdrToUint64(*reinterpret_cast<pldm_msg*>(response_bytes.data()));

        set_effecter_state_response response { };

        errl =
            decode_pldm_response(decode_set_state_effecter_states_resp,
                                 response_bytes,
                                 &response.completion_code);

        if (errl)
        {
            // Message decoding failed; break out of the block;
            PLDM_ERR("getEffecter: Error occurred trying to decode pldm response.");
            break;
        }

        if (response.completion_code != PLDM_SUCCESS)
        {

            PLDM_ERR("decode_set_state_effecter_states_resp failed with rc 0x%.02x",
                    response.completion_code);

            /*
            * @errortype  ERRL_SEV_UNRECOVERABLE
            * @moduleid   MOD_SEND_SET_STATE_EFFECTER_STATES_REQUEST
            * @reasoncode RC_BAD_COMPLETION_CODE
            * @userdata1  Complete code returned
            * @userdata2  Response header data (see pldm_msg_hdr struct)
            * @devdesc    Software problem, BMC returned bad PLDM response code
            * @custdesc   A software error occurred during system boot
            */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                   PLDM::MOD_SEND_SET_STATE_EFFECTER_STATES_REQUEST ,
                                   PLDM::RC_BAD_COMPLETION_CODE,
                                   response.completion_code,
                                   response_hdr_data,
                                   ErrlEntry::NO_SW_CALLOUT);
            addBmcErrorCallouts(errl);

            break;
        }

    } while (false);

    PLDM_EXIT("sendSetStateEffecterStatesRequest");

    return errl;
}

errlHndl_t sendGracefulRebootRequest( const char* i_reason )
{
    // TODO RTC: 259581 Dynamically fetch this effecter from BMC instead of
    // assuming its value.
    const effector_id_t SOFTWARE_TERMINATION_STATUS_EFFECTER_ID = 0x0003;
    std::vector<set_effecter_state_field> fields_to_set;
    constexpr uint8_t graceful_reboot =
            pldm_effecter_state_fields::PLDM_GRACEFUL_REBOOT;
    fields_to_set.push_back({set_request::PLDM_REQUEST_SET, graceful_reboot});

    CONSOLE::displayf(CONSOLE::DEFAULT, nullptr,
                      "Triggering graceful reboot for %s", i_reason);

    return sendSetStateEffecterStatesRequest(SOFTWARE_TERMINATION_STATUS_EFFECTER_ID,
                                             fields_to_set);
}

}
