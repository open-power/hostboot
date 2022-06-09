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

} // namespace PLDM
