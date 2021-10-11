/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mctp/runtime/hbrt_mctp.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
 *  @file  hbrt_mctp.C
 *  @brief Source code for functions we will bind to the hbrt virtual
 *         mctp binding.
 */

// system headers
#include <memory>
// local headers
#include "hbrt_mctp.H"
// libmctp headers
#include <libmctp.h>
// runtime interface headers
#include <runtime/interface.h>
// error handling
#include <errl/errlentry.H>
#include <errl/errlmanager.H>

extern trace_desc_t* g_trac_mctp;

/* See hbrt_mctp.H for details */
int __mctp_hbrtvirt_hostboot_mctp_send(const uint32_t i_len,
                                       const void * const i_val)
{
    size_t fw_msg_req_size = hostInterfaces::HBRT_FW_MSG_BASE_SIZE + i_len;
    std::unique_ptr<hostInterfaces::hbrt_fw_msg, decltype(&free)> fw_msg_req(
      static_cast<hostInterfaces::hbrt_fw_msg *>(malloc(fw_msg_req_size)),free);

    fw_msg_req->io_type = hostInterfaces::HBRT_FW_MSG_TYPE_MCTP_SEND;
    memcpy(fw_msg_req->mctp_send.send_data,
           i_val,
           i_len);

    size_t fw_msg_resp_size = hostInterfaces::HBRT_FW_GENERIC_RSP_SIZE;

    // because phyp will uses the same buffer for processing,
    // the rsp buffer must be >= request buffer
    if(fw_msg_resp_size < fw_msg_req_size)
    {
        fw_msg_resp_size = fw_msg_req_size;
    }
    std::unique_ptr<hostInterfaces::hbrt_fw_msg, decltype(&free)> fw_msg_resp(
      static_cast<hostInterfaces::hbrt_fw_msg *>(malloc(fw_msg_resp_size)),free);

    int rc = g_hostInterfaces->firmware_request(fw_msg_req_size,
                                                fw_msg_req.get(),
                                                &fw_msg_resp_size,
                                                fw_msg_resp.get());

    if(rc)
    {
        TRACFBIN(g_trac_mctp, "mctp send of this fw req msg failed: ",
                 fw_msg_req.get(), fw_msg_resp_size);
    }

    return rc;
}

/* See hbrt_mctp.H for details */
int __mctp_hbrtvirt_hostboot_mctp_receive(uint64_t * const io_len,
                                          void * const o_val)
{
    size_t fw_msg_req_size = hostInterfaces::HBRT_FW_MSG_BASE_SIZE;
    assert(*io_len > fw_msg_req_size, "MCTP_RECEIVE response buffer is too small");

    uint8_t req_buf[fw_msg_req_size] = {0};
    hostInterfaces::hbrt_fw_msg * fw_msg_req =
      reinterpret_cast<hostInterfaces::hbrt_fw_msg *>(req_buf);
    fw_msg_req->io_type = hostInterfaces::HBRT_FW_MSG_TYPE_MCTP_RECEIVE;

    hostInterfaces::hbrt_fw_msg * fw_msg_resp =
      reinterpret_cast<hostInterfaces::hbrt_fw_msg *>(o_val);

    TRACDBIN(g_trac_mctp, "__mctp_hbrtvirt_hostboot_mctp_receive: mctp receive request: ", fw_msg_req, fw_msg_req_size);

    int rc =  g_hostInterfaces->firmware_request(fw_msg_req_size,
                                                 fw_msg_req,
                                                 io_len,
                                                 fw_msg_resp);
    if(!rc)
    {
        // strip firmware request size
        *io_len -= sizeof(fw_msg_req->io_type);

        // copy data to ptr provided to us
        memmove(o_val,
                &fw_msg_resp->mctp_receive.receive_data,
                (*io_len));

        TRACDBIN(g_trac_mctp, "__mctp_hbrtvirt_hostboot_mctp_receive: mctp receive: ", o_val, *io_len);
    }
    else if (rc != HBRT_RC_NO_MCTP_PACKET)
    {
        TRACFCOMP(g_trac_mctp, "__mctp_hbrtvirt_hostboot_mctp_receive: ERRROR: mctp receive got rc 0x%.08X printing 0x%.016llx bytes",
                  rc, *io_len);
        TRACFBIN(g_trac_mctp, "__mctp_hbrtvirt_hostboot_mctp_receive: mctp receive: ", o_val, *io_len);
    }

    return rc;
}
