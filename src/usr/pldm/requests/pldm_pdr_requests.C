/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/requests/pldm_pdr_requests.C $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2022                        */
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
#include <map>

// Error logs
#include <errl/errlentry.H>
#include <errl/errlmanager.H>

// Console display
#include <console/consoleif.H>

// Targeting
#include <targeting/targplatutil.H>
#include <targeting/common/targetservice.H>

// IPC
#include <sys/msg.h>

// VFS_ROOT_MSG_PLDM_REQ_OUT
#include <sys/vfs.h>

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
#include <pldm/pldm_trace.H>
#include <pldm/pldm_util.H>
#include "pldm_request_utils.H"

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
 * @param[in/out] io_pdr_usage_map
 *                A usage map to keep track of the PDR's seen.
 *                If, during the life cycle of the map, a duplicate PDR is seen,
 *                an error log will be made and returned to caller for
 *                proper handling.
 * @return Error if any, otherwise nullptr.
 */
errlHndl_t getPDR(const msg_q_t i_msgQ,
                  pdr_handle_t& io_pdr_record_handle,
                  pdr& o_pdr,
                  std::map< pdr_handle_t, uint32_t > &io_pdr_usage_map)
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

        /*@
          * @moduleid   MOD_GET_PDR
          * @reasoncode RC_BAD_COMPLETION_CODE
          * @userdata1  Actual Completion Code
          * @userdata2  Expected Completion Code
          * @devdesc    Software problem, bad PLDM response from BMC
          * @custdesc   A software error occurred during system boot
          */
        errl = validate_resp(response.completion_code, PLDM_SUCCESS,
                             MOD_GET_PDR, RC_BAD_COMPLETION_CODE,
                             response_bytes);
        if(errl)
        {
            break;
        }

        /*@
          * @moduleid   MOD_GET_PDR
          * @reasoncode RC_BAD_NEXT_TRANSFER_HANDLE
          * @userdata1  Actual Next Transfer Handle
          * @userdata2  Expected Next Transfer Handle
          * @devdesc    Software problem, bad PLDM response from BMC
          * @custdesc   A software error occurred during system boot
          */
        /* HB does not support multipart transfers */
        errl = validate_resp(response.next_data_transfer_hndl, static_cast<pdr_handle_t>(0),
                             MOD_GET_PDR, RC_BAD_NEXT_TRANSFER_HANDLE,
                             response_bytes);
        if(errl)
        {
            break;
        }

        /*@
          * @moduleid   MOD_GET_PDR
          * @reasoncode RC_BAD_TRANSFER_FLAG
          * @userdata1  Actual Transfer Flag
          * @userdata2  Expected Transfer Flag
          * @devdesc    Software problem, bad PLDM response from BMC
          * @custdesc   A software error occurred during system boot
          */
        errl = validate_resp(response.transfer_flag, PLDM_START_AND_END,
                             MOD_GET_PDR, RC_BAD_TRANSFER_FLAG,
                             response_bytes);
        if(errl)
        {
            break;
        }

        /* Once we decode the message, then we can add the PDR to the caller's
         * PDR byte buffer and return. */
        o_pdr.data.assign(begin(response.record_data),
                          begin(response.record_data) + response.resp_cnt);

        const auto pdr_hdr = reinterpret_cast<pldm_pdr_hdr*>(o_pdr.data.data());
        o_pdr.record_handle = le32toh(pdr_hdr->record_handle);
        if ((io_pdr_record_handle != o_pdr.record_handle) && (io_pdr_record_handle != FIRST_PDR_HANDLE))
        {
            /*@
             * @moduleid   MOD_GET_PDR_REPO
             * @reasoncode RC_INVALID_RECORD_HANDLE
             * @userdata1  Requested record handle
             * @userdata2  Response record handle
             * @devdesc    Bad data in PLDM message decode, response record handle not as expected
             * @custdesc   Host firmware detected BMC communication error during system boot
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 MOD_GET_PDR_REPO,
                                 RC_INVALID_RECORD_HANDLE,
                                 io_pdr_record_handle,
                                 o_pdr.record_handle,
                                 ErrlEntry::NO_SW_CALLOUT);
            addBmcErrorCallouts(errl);
            break;
        }

        // Used to abort the IPL if PLDM PDRs are marked as having
        // already been seen (integrity check the getPDR flow)
        // If in the future any caller desires to -NOT- do a uniqueness check here
        // the io_pdr_usage_map provided as input would need to be cleared prior to invocation.
        bool pdr_abort = false;

        if (io_pdr_usage_map.count(o_pdr.record_handle))
        {
            // Problem observed has been an infinite PDR loop where we -NEVER- receive
            // the null terminator which causes Hostboot to hang/crash when resources
            // are depleted
            PLDM_ERR("PDR ENCOUNTERED already been seen -> io_pdr_usage_map[0x%08x]=%d",
                o_pdr.record_handle, io_pdr_usage_map[o_pdr.record_handle]);
            pdr_abort = true;
        }
        else
        {
            // first invocation will pass io_pdr_record_handle as FIRST_PDR_HANDLE
            // so we need to get the REAL record_handle to log the usage properly
            io_pdr_usage_map[o_pdr.record_handle] = 1;
        }

        io_pdr_record_handle = response.next_record_hndl;

        if (pdr_abort)
        {
            /*@
             * @moduleid   MOD_GET_PDR_REPO
             * @reasoncode RC_DEFENSIVE_LIMIT
             * @userdata1  Duplicate Record Handle that has already been seen
             * @userdata2  Unused
             * @devdesc    Duplicate PLDM Record Handle from PLDM getPDR
             * @custdesc   Host firmware detected BMC communication error during system boot
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 MOD_GET_PDR_REPO,
                                 RC_DEFENSIVE_LIMIT,
                                 o_pdr.record_handle,
                                 0,
                                 ErrlEntry::NO_SW_CALLOUT);
            addBmcErrorCallouts(errl);
        }
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
    std::map< pdr_handle_t, uint32_t > pdr_usage_map;

    do
    {
        pdr result_pdr { };

        // Current implementation uses the same pdr_usage_map to track uniqueness.
        // If in the future callers of getPDR do -NOT- wish to abort on duplicates,
        // the pdr_usage_map should be cleared prior to invocation.
        errl = getPDR(msgQ, pdr_handle, result_pdr, pdr_usage_map);

        if (errl)
        {
            PLDM_ERR("getAllPdrs encountered a problem in getPDR, look for an errlog");
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

struct event_msg_response
{
    uint8_t completion_code = 0;
    uint8_t status = 0; // Don't really care about this status, it
                        // just tells us what happened with the
                        // logging (see DSP0248 1.2.0 section 16.6
                        // for details)
};

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

                event_msg_response response { };

                errl =
                    decode_pldm_response(decode_platform_event_message_resp,
                                         response_bytes,
                                         &response.completion_code,
                                         &response.status);

                if (errl)
                {
                    PLDM_INF("Failed to decode repository change event");
                    break;
                }

              /*@
                * @moduleid   MOD_SEND_REPO_CHANGED_EVENT
                * @reasoncode RC_BAD_COMPLETION_CODE
                * @userdata1  Actual Completion Code
                * @userdata2  Expected Completion Code
                * @devdesc    Software problem, bad PLDM response from BMC
                * @custdesc   A software error occurred during system boot
                */
                errl = validate_resp(response.completion_code, PLDM_SUCCESS,
                                     MOD_SEND_REPO_CHANGED_EVENT, RC_BAD_COMPLETION_CODE,
                                     response_bytes);
                if(errl)
                {
                    break;
                }

                PLDM_INF("Sent PDR Repository Changed Event successfully");
            }
        } while (false);
    }

    PLDM_EXIT("sendRepositoryChangedEvent");

    return errl;
}

errlHndl_t sendSensorStateChangedEvent(const TARGETING::Target* const i_target,
                                       const uint16_t i_state_set_id,
                                       const sensor_id_t i_sensor_id,
                                       const uint8_t i_sensor_offset,
                                       const sensor_state_t i_sensor_state)
{
    return sendSensorStateChangedEvent(i_target, i_state_set_id, i_sensor_id, i_sensor_offset,
                                       i_sensor_state, thePdrManager().hostbootTerminusId());
}

errlHndl_t sendSensorStateChangedEvent(const TARGETING::Target* const i_target,
                                       const uint16_t i_state_set_id,
                                       const sensor_id_t i_sensor_id,
                                       const uint8_t i_sensor_offset,
                                       const sensor_state_t i_sensor_state,
                                       const terminus_id_t i_terminus_id)
{
    PLDM_ENTER("sendSensorStateChangedEvent (target = 0x%08x, state set = %d, sensor id = %d, offset = %d, state = %d)",
               get_huid(i_target), i_state_set_id, i_sensor_id, i_sensor_offset, i_sensor_state);

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
             i_terminus_id,
             PLDM_SENSOR_EVENT,
             event_data_bytes.data(),
             event_data_bytes.size());

        if (errl)
        {
            PLDM_INF("Failed to send/recv sensor state change event");
            break;
        }

        event_msg_response response { };
        errl = decode_pldm_response(decode_platform_event_message_resp,
                                    response_bytes,
                                    &response.completion_code,
                                    &response.status);

        if (errl)
        {
            PLDM_INF("Failed to decode sensor state change response");
            break;
        }

        /*@
          * @moduleid   MOD_SEND_SENSOR_STATE_CHANGED_EVENT
          * @reasoncode RC_BAD_COMPLETION_CODE
          * @userdata1  Actual Completion Code
          * @userdata2  Expected Completion Code
          * @devdesc    Software problem, bad PLDM response from BMC
          * @custdesc   A software error occurred during system boot
          */
        errl = validate_resp(response.completion_code, PLDM_SUCCESS,
                             MOD_SEND_SENSOR_STATE_CHANGED_EVENT, RC_BAD_COMPLETION_CODE,
                             response_bytes);
        if(errl)
        {
            break;
        }
        PLDM_INF("Sent Sensor State Changed Event successfully");
    } while (false);

    PLDM_EXIT("sendSensorStateChangedEvent");

    return errl;
}

void sendProgressStateChangeEvent(const pldm_state_set_boot_progress_state_values i_boot_state)
{
    using namespace TARGETING;
    PLDM_ENTER("sendProgressStateChangeEvent (boot_state = %d)", i_boot_state);
    errlHndl_t l_errl = nullptr;
    Target * l_node = nullptr;

#ifndef __HOSTBOOT_RUNTIME
    l_node = UTIL::getCurrentNodeTarget();
#else
    UTIL::getMasterNodeTarget(l_node);
#endif

    // Search for the BOOT_PROGRESS state sensor ID
    const sensor_id_t sensor_id
        = thePdrManager().getHostStateQueryIdForStateSet(PdrManager::STATE_QUERY_SENSOR,
                                                         PLDM_STATE_SET_BOOT_PROGRESS,
                                                         l_node);

    assert(sensor_id != 0,
           "Sensor ID for node target HUID=0x%08x has not been assigned",
           get_huid(l_node));

    constexpr int BOOT_STATE_SENSOR_INDEX = 0;

    l_node->setAttr<ATTR_BOOT_PROGRESS_STATE>(static_cast<uint16_t>(i_boot_state));

    l_errl = sendSensorStateChangedEvent(l_node, PLDM_STATE_SET_BOOT_PROGRESS,
                              sensor_id, BOOT_STATE_SENSOR_INDEX, i_boot_state);
    if (l_errl != nullptr)
    {
        PLDM_ERR("Sending boot state %d failed for node 0x%.8X",
            i_boot_state, get_huid(l_node));
        l_errl->collectTrace(PLDM_COMP_NAME);
        l_errl->collectTrace(ISTEP_COMP_NAME);
        ERRORLOG::errlCommit(l_errl, PLDM_COMP_ID);
    }

  PLDM_EXIT("sendProgressStateChangeEvent (boot_state = %d)", i_boot_state);

}


errlHndl_t sendOccStateChangedEvent(const TARGETING::Target* const i_occ_target,
                                    const occ_state i_new_state)
{
    using namespace TARGETING;

    assert(i_occ_target->getAttr<ATTR_TYPE>() == TYPE_OCC,
           "Invalid target type passed to sendOccStateChangedEvent: Expected TYPE_OCC (0x%x), "
           "got %s (0x%x), HUID 0x%08x",
           TYPE_OCC,
           attrToString<ATTR_TYPE>(i_occ_target->getAttr<ATTR_TYPE>()),
           i_occ_target->getAttr<ATTR_TYPE>(),
           get_huid(i_occ_target));

    // Search for the OCC state sensor ID
    const sensor_id_t sensor_id
        = thePdrManager().getHostStateQueryIdForStateSet(PdrManager::STATE_QUERY_SENSOR,
                                                         PLDM_STATE_SET_OPERATIONAL_RUNNING_STATUS,
                                                         i_occ_target);

    assert(sensor_id != 0,
           "Sensor ID for OCC target HUID=0x%08x has not been assigned",
           get_huid(i_occ_target));

    // The OCC sensors only have one state associated with them, and it is at
    // index 0.
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
    case system_in_safe_mode:
        new_occ_state = PLDM_STATE_SET_OPERATIONAL_RUNNING_STATUS_DORMANT;
        break;
    default:
        assert(false, "Invalid state %d given to sendOccStateChangedEvent",
               i_new_state);
    }

    return sendSensorStateChangedEvent(i_occ_target, PLDM_STATE_SET_OPERATIONAL_RUNNING_STATUS,
                                       sensor_id, OCC_STATE_SENSOR_INDEX, new_occ_state);
}

errlHndl_t sendFruFunctionalStateChangedEvent(const TARGETING::Target* const i_target,
                                              const state_query_id_t i_sensor_id,
                                              const bool i_functional)
{
    // The functional state sensors only have one value associated with them,
    // and it is at index 0.
    constexpr int FUNCTIONAL_STATE_SENSOR_INDEX = 0;

    const sensor_state_t functional_state = (i_functional
                                             ? PLDM_STATE_SET_HEALTH_STATE_NORMAL
                                             : PLDM_STATE_SET_HEALTH_STATE_CRITICAL);

    return sendSensorStateChangedEvent(i_target,
                                       PLDM_STATE_SET_HEALTH_STATE,
                                       i_sensor_id,
                                       FUNCTIONAL_STATE_SENSOR_INDEX,
                                       functional_state);
}

struct cc_only_response
{
    uint8_t completion_code = 0;
};

errlHndl_t sendSetNumericEffecterValueRequest(const effecter_id_t i_effecter_id,
                                              const uint32_t i_effecter_value,
                                              const uint8_t i_value_size)
{
    PLDM_ENTER("sendSetNumericEffecterValueRequest");

    errlHndl_t errl = nullptr;

    do
    {

    const msg_q_t msgQ = MSG_Q_RESOLVE("sendSetNumericEffecterValueRequest",
                                       VFS_ROOT_MSG_PLDM_REQ_OUT);

    void* effecter_value_ptr = nullptr;

    uint8_t effecter_value_8 = i_effecter_value;
    uint16_t effecter_value_16 = i_effecter_value;
    uint32_t effecter_value_32 = i_effecter_value;

    if (i_value_size == 1)
    {
        effecter_value_ptr = &effecter_value_8;
    }
    else if (i_value_size == 2)
    {
        effecter_value_ptr = &effecter_value_16;
    }
    else if (i_value_size == 4)
    {
        effecter_value_ptr = &effecter_value_32;
    }
    else
    {
        assert(false, "sendSetNumericEffecterValueRequest: Invalid effecter size %d; expected 1, 2 or 4",
               i_value_size);
    }

    std::vector<uint8_t> response_bytes;

    errl = sendrecv_pldm_request<PLDM_SET_NUMERIC_EFFECTER_VALUE_MIN_REQ_BYTES>
        (response_bytes,
         i_value_size - 1, // PLDM_SET_NUMERIC_EFFECTER_VALUE_MIN_REQ_BYTES already includes space for 1 byte, so subtract 1 here
         msgQ,
         encode_set_numeric_effecter_value_req,
         DEFAULT_INSTANCE_ID, // let the PLDM service fill this in
         i_effecter_id,
         i_value_size,
         static_cast<uint8_t*>(effecter_value_ptr));

    if (errl)
    {
        PLDM_ERR("sendSetNumericEffecterValueRequest: failed to send/recv PLDM request; "
                 TRACE_ERR_FMT,
                 TRACE_ERR_ARGS(errl));
        break;
    }

    cc_only_response response { };
    errl = decode_pldm_response(decode_set_numeric_effecter_value_resp,
                                response_bytes,
                                &response.completion_code);
    if (errl)
    {
        PLDM_ERR("sendSetNumericEffecterValueRequest: failed to decode PLDM response; "
                 TRACE_ERR_FMT,
                 TRACE_ERR_ARGS(errl));
        break;
    }

    /*@
      * @moduleid   MOD_SEND_SET_NUMERIC_EFFECTER_VALUE_REQUEST
      * @reasoncode RC_BAD_COMPLETION_CODE
      * @userdata1  Actual Completion Code
      * @userdata2  Expected Completion Code
      * @devdesc    Software problem, bad PLDM response from BMC
      * @custdesc   A software error occurred during system boot
      */
    errl = validate_resp(response.completion_code, PLDM_SUCCESS,
                         MOD_SEND_SET_NUMERIC_EFFECTER_VALUE_REQUEST,
                         RC_BAD_COMPLETION_CODE, response_bytes);
    if(errl)
    {
        break;
    }

    } while (false);

    PLDM_EXIT("sendSetNumericEffecterValueRequest");

    return errl;
}

errlHndl_t sendSetStateEffecterStatesRequest(
                                    const effecter_id_t i_effecter_id,
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

        cc_only_response response { };
        errl = decode_pldm_response(decode_set_state_effecter_states_resp,
                                    response_bytes,
                                    &response.completion_code);
        if (errl)
        {
            PLDM_ERR("sendSetNumericEffecterValueRequest: failed to decode PLDM response; "
                    TRACE_ERR_FMT,
                    TRACE_ERR_ARGS(errl));
            break;
        }

        /*@
          * @moduleid   MOD_SEND_SET_STATE_EFFECTER_STATES_REQUEST
          * @reasoncode RC_BAD_COMPLETION_CODE
          * @userdata1  Actual Completion Code
          * @userdata2  Expected Completion Code
          * @devdesc    Software problem, bad PLDM response from BMC
          * @custdesc   A software error occurred during system boot
          */
        errl = validate_resp(response.completion_code, PLDM_SUCCESS,
                             MOD_SEND_SET_STATE_EFFECTER_STATES_REQUEST,
                             RC_BAD_COMPLETION_CODE, response_bytes);
        if(errl)
        {
            break;
        }
    } while (false);

    PLDM_EXIT("sendSetStateEffecterStatesRequest");

    return errl;
}

errlHndl_t sendResetRebootCountRequest()
{
    PLDM_ENTER("sendResetRebootCountRequest()");
    errlHndl_t errl = nullptr;
    do {

    TARGETING::Target* system = TARGETING::UTIL::assertGetToplevelTarget();

    // The effecter attached to the Logical System pldm entity
    pldm_entity chassis_entity =
        targeting_to_pldm_entity_id(system->getAttr<TARGETING::ATTR_SYSTEM_PLDM_ENTITY_ID_INFO>());

    // This is effectively the unique id for this PDR. Since other PDRs aren't allowed to have this base unit
    const uint8_t PLDM_BASE_UNIT_RETRIES = 72;
    const effecter_id_t reboot_count_effecter =
        thePdrManager().findNumericEffecterId(chassis_entity,
                                              [](pldm_numeric_effecter_value_pdr const * const numeric_effecter)
                                              {
                                                  return numeric_effecter->base_unit == PLDM_BASE_UNIT_RETRIES;
                                              });

    if (reboot_count_effecter == 0)
    {
            /*@
             * @moduleid   MOD_RESET_REBOOT_COUNT
             * @reasoncode RC_INVALID_EFFECTER_ID
             * @userdata1  The total number of PDRs that PDR Manager is aware of.
             * @devdesc    Software problem, could not find reboot count effecter PDR.
             * @custdesc   A software error occurred during system boot.
             */
            errl = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                                 MOD_RESET_REBOOT_COUNT,
                                 RC_INVALID_EFFECTER_ID,
                                 PLDM::thePdrManager().pdrCount(),
                                 0,
                                 ErrlEntry::ADD_SW_CALLOUT);
            addBmcErrorCallouts(errl);
            break;
    }

    // BMC reboot counter defaults to three and regardless of value sent BMC will treat it as three. So just send three.
    const uint8_t MAX_REBOOT_COUNT = 3;
    errl = sendSetNumericEffecterValueRequest(reboot_count_effecter, MAX_REBOOT_COUNT, sizeof(MAX_REBOOT_COUNT));

    if (errl)
    {
        PLDM_ERR("sendResetRebootCountRequest(): Failed to send numeric effecter value set request for system target.");
        break;
    }

    } while(0);

    PLDM_EXIT("sendResetRebootCountRequest()");
    return errl;
}

errlHndl_t sendGracefulRestartRequest()
{
    errlHndl_t errl = nullptr;

    do
    {
        errl = sendResetRebootCountRequest();
        if (errl)
        {
            // Commit the log and continue to give the system a chance at recovery.
            ERRORLOG::errlCommit(errl, PLDM_COMP_ID);
        }

        const effecter_id_t sw_term_effecter_id
            = thePdrManager().findStateEffecterId(PLDM_STATE_SET_SW_TERMINATION_STATUS,
                                                  { .entity_type = ENTITY_SYS_FIRMWARE,
                                                    .entity_instance_num = 0,
                                                    .entity_container_id = PdrManager::ENTITY_ID_DONTCARE });

        if (sw_term_effecter_id == 0)
        {
            /*@
             * @moduleid   MOD_FIND_TERMINATION_STATUS_ID
             * @reasoncode RC_INVALID_EFFECTER_ID
             * @userdata1  The total number of PDRs that PDR Manager is aware of.
             * @userdata2[0:31]  PLDM_STATE_EFFECTER_PDR enum value
             * @userdata2[32:63] State set being searched for
             * @devdesc    Software problem, could not find SW Termination PDR.
             * @custdesc   A software error occurred during system boot.
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 MOD_FIND_TERMINATION_STATUS_ID,
                                 RC_INVALID_EFFECTER_ID,
                                 PLDM::thePdrManager().pdrCount(),
                                 TWO_UINT32_TO_UINT64(PLDM_STATE_EFFECTER_PDR,
                                                      PLDM_STATE_SET_SW_TERMINATION_STATUS),
                                 ErrlEntry::ADD_SW_CALLOUT);
            addBmcErrorCallouts(errl);
            break;
        }

        std::vector<set_effecter_state_field> fields_to_set;
        fields_to_set.push_back({ set_request::PLDM_REQUEST_SET, PLDM_SW_TERM_GRACEFUL_RESTART_REQUESTED });
        errl = sendSetStateEffecterStatesRequest(sw_term_effecter_id, fields_to_set);
    } while (false);

    return errl;
}

}
