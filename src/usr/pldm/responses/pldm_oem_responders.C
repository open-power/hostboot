/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/responses/pldm_oem_responders.C $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
/* @file pldm_oem_responders.C
 *
 * This file contains the definitions for PLDM responders for the OEM message category
 *
 */

#include <pldm/responses/pldm_oem_responders.H>
#include <targeting/attrrp.H> // TARGETING::AttrRP::dumpAttrs
#include <pldm/pldm_response.H> // send_cc_only_response
#include <pldm/pldm_trace.H>    // PLDM_INF
#include <htmgt/htmgt.H>

namespace PLDM
{

errlHndl_t handleGetPldmAttrDumpRequest(const MCTP::mctp_outbound_msgq_t i_msgQ,
                                        const pldm_mctp_message& i_msg)
{
    errlHndl_t l_errl = nullptr;

    PLDM_INF("Received a getAttrDump Request message");

    // Respond with success right away so that BMC doesn't wait for us to
    // complete dumping the attributes
    send_cc_only_response(i_msgQ, i_msg, PLDM_SUCCESS);

    l_errl = TARGETING::AttrRP::dumpAttrs();
    if(l_errl)
    {
        PLDM_ERR("handleGetPldmAttrDumpRequest: Could not dump HB attributes");
    }

    return l_errl;
}

const size_t MAX_HTMGT_CMD_SIZE = 0x64;
const size_t MAX_HTMGT_RSP_SIZE = 4096;
errlHndl_t handleHtmgtRequest(const MCTP::mctp_outbound_msgq_t i_msgQ,
                              const pldm_mctp_message& i_msg)
{
    errlHndl_t l_errl = nullptr;
    uint16_t htmgtCmdLen = 0;
    uint8_t htmgtCmdData[MAX_HTMGT_CMD_SIZE] = { 0x01 };

    PLDM_INF("Received a HTMGT Request message (payload size 0x%04X)", i_msg.payload_size());
    if (i_msg.payload_size() == 0)
    {
        PLDM_ERR("No HTMGT command specified");
        send_cc_only_response(i_msgQ, i_msg, PLDM_ERROR_INVALID_DATA);
        return l_errl;
    }

    // Copy payload locally for HTMGT passthru command
    const size_t dataOffset = sizeof(pldm_msg_hdr);
    htmgtCmdLen = std::min(i_msg.payload_size(), MAX_HTMGT_CMD_SIZE);
    for(size_t ii = 0; ii < htmgtCmdLen; ++ii)
    {
        htmgtCmdData[ii] = i_msg.pldm_data[dataOffset+ii];
    }

#ifdef CONFIG_HTMGT
    uint16_t rspLen = 0;
    uint8_t rspData[MAX_HTMGT_RSP_SIZE] = { 0 };
    PLDM_INF_BIN("HTMGT Command:", htmgtCmdData, i_msg.payload_size());
    l_errl = HTMGT::passThruCommand(htmgtCmdLen, htmgtCmdData, rspLen, rspData);
    if(l_errl)
    {
        PLDM_ERR("handleHtmgtRequest: HTMGT:passThruCommand(0x%02X) failed with rc=0x%04X",
                 htmgtCmdData[0], l_errl->reasonCode());
        send_cc_only_response(i_msgQ, i_msg, PLDM_ERROR);
    }
    else
    {
        PLDM_INF("handleHtmgtRequest: HTMGT::passThruCommand(0x%02X) returned %d bytes of data",
                 htmgtCmdData[0], rspLen);
        // Response succes, but data will not get returned to the BMC
        send_cc_only_response(i_msgQ, i_msg, PLDM_SUCCESS);
        if (rspLen > 0)
        {
            PLDM_INF_BIN("HTMGT Response:", rspData, rspLen);
        }
    }
#else
    send_cc_only_response(i_msgQ, i_msg, PLDM_ERROR_UNSUPPORTED_PLDM_CMD);
#endif

    return l_errl;
}

} // namespace PLDM
