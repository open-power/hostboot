/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/requests/pldm_datetime_requests.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2022                        */
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
#include <pldm/requests/pldm_datetime_requests.H>
#include <bios.h>
#include <pldm/pldm_util.H>
#include <sys/vfs.h>
#include <pldm/pldm_trace.H>
#include <pldm/pldm_request.H>
#include "pldm_request_utils.H"

/* @file pldm_datetime_requests.C
 *
 * This file contains the implementations of the functions involved in getting
 * the timestamp (current date/time) from the BMC.
 */

namespace PLDM
{

/*
 * @brief A wrapper around encode_get_date_time_req that takes in an additional
 * size parameter to accommodate Hostboot PLDM APIs. The size parameter is
 * actually unused, since the command doesn't have a message payload.
 *
 * @param[in] i_instance_id the PLDM instance ID
 * @param[out] o_msg the encoded PLDM message
 * @param[in] i_unused_payload_size payload size (unused)
 * @return The RC from encoder
 */
int encode_get_datetime_req_hb(const uint8_t i_instance_id,
                               pldm_msg* const o_msg,
                               const size_t i_unused_payload_size)
{
    return encode_get_date_time_req(i_instance_id, o_msg);
}

errlHndl_t getDateTime(date_time_t& o_dateTime)
{
    errlHndl_t l_errl = nullptr;
    o_dateTime.value = 0;

    do {
    std::vector<uint8_t>l_responseBytes;

    l_errl = sendrecv_pldm_request<0>(l_responseBytes,
                                      g_outboundPldmReqMsgQ,
                                      encode_get_datetime_req_hb,
                                      DEFAULT_INSTANCE_ID);
    if(l_errl)
    {
        PLDM_ERR("getDateTime: Could not send the message to get date/time to BMC");
        break;
    }

    pldm_get_date_time_resp l_resp{};
    l_errl = decode_pldm_response(decode_get_date_time_resp,
                                  l_responseBytes,
                                  &l_resp.completion_code,
                                  &l_resp.seconds,
                                  &l_resp.minutes,
                                  &l_resp.hours,
                                  &l_resp.day,
                                  &l_resp.month,
                                  &l_resp.year);
    if(l_errl)
    {
        PLDM_ERR("getDateTime: Could not decode PLDM response");
        break;
    }


    /*@
     * @errortype
     * @moduleid   MOD_GET_DATE_TIME
     * @reasoncode RC_BAD_COMPLETION_CODE
     * @userdata1  Completion code
     * @devdesc    Bad completion code received for get date/time PLDM operation
     * @custdesc   A firmware failure occurred
     */
    l_errl = validate_resp(l_resp.completion_code, PLDM_SUCCESS,
                           MOD_GET_DATE_TIME, RC_BAD_COMPLETION_CODE,
                           l_responseBytes);
    if(l_errl)
    {
        break;
    }

    // The data arrives from BMC in BCD format. Convert it to decimal for
    // processing.
    o_dateTime.format.year = bcd2dec16(l_resp.year);
    o_dateTime.format.month = bcd2dec8(l_resp.month);
    o_dateTime.format.day = bcd2dec8(l_resp.day);
    o_dateTime.format.hour = bcd2dec8(l_resp.hours);
    o_dateTime.format.minute = bcd2dec8(l_resp.minutes);
    o_dateTime.format.second = bcd2dec8(l_resp.seconds);


    }while(0);

    return l_errl;
}

} // namespace PLDM
