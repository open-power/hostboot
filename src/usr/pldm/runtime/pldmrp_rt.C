/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/runtime/pldmrp_rt.C $                            */
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

/** @file  pldmrp_rt.C
 *  @brief Source code for hbrt's PLDM resource provider.
 */
#include "pldmrp_rt.H"
#include <pldm/pldmif.H>
#include <pldm/pldm_trace.H>
#include <runtime/interface.h>
#include <pldm/extended/pdr_manager.H>
#include <pldm/extended/sbe_dump.H>

using namespace PLDM;

pldmrp_rt_rc PLDM::cache_next_pldm_msg(pldm_mctp_message i_next_msg)
{
    return Singleton<PldmRP>::instance().cache_next_pldm_msg(std::move(i_next_msg));
}

void PLDM::set_waiting_for_response(const bool i_waitingForResponse)
{
    Singleton<PldmRP>::instance().iv_waitingForResponse = i_waitingForResponse;
}

const pldm_mctp_message& PLDM::get_next_response()
{
    return Singleton<PldmRP>::instance().iv_next_response;
}

void PLDM::clear_next_response()
{
    Singleton<PldmRP>::instance().iv_next_response.pldm_data.clear();
}

const pldm_mctp_message& PLDM::get_next_request()
{
    return Singleton<PldmRP>::instance().iv_next_request;
}

void PLDM::clear_next_request()
{
    Singleton<PldmRP>::instance().iv_next_request.pldm_data.clear();
}

pldm_mctp_message PLDM::get_and_clear_next_request()
{
    return Singleton<PldmRP>::instance().get_and_clear_next_request();
}

pldm_mctp_message PLDM::get_and_clear_next_response()
{
    return Singleton<PldmRP>::instance().get_and_clear_next_response();
}

pldm_mctp_message PldmRP::get_and_clear_next_request()
{
    return std::move(iv_next_request);
}

pldm_mctp_message PldmRP::get_and_clear_next_response()
{
    return std::move(iv_next_response);
}

pldmrp_rt_rc PldmRP::cache_next_pldm_msg(pldm_mctp_message i_next_msg)
{
    pldmrp_rt_rc rc = RC_PLDMRP_RT_SUCCESS;

    do
    {

    if (i_next_msg.pldm_data.size() < sizeof(pldm_msg_hdr))
    {
        rc = RC_INVALID_MESSAGE_LEN;
        break;
    }

    const pldm_msg_hdr* pldm_hdr = &i_next_msg.pldm()->hdr;

    // Update our cached request/response appropriately if they
    // are empty, otherwise return a RC indicating we are full.
    if (pldm_hdr->request)
    {
        if (iv_next_request.empty())
        {
            iv_next_request = std::move(i_next_msg);
        }
        else if (iv_waitingForResponse)
        {
            PLDM_INF("cache_next_pldm_msg: discarding queued PLDM request "
                     "as new one arrived while waiting for a PLDM response.");
            PLDM_INF_BIN("Discarded PLDM message header",
                         pldm_hdr,
                         std::min(i_next_msg.pldm_data.size(), sizeof(pldm_msg_hdr)));

            // Already have a request pending while waiting for a response
            // and a new request came in.  That should only happen if BMC
            // timed out a previous request and issued a new one.  In that case,
            // throw away the existing request and replace it.
            iv_next_request = std::move(i_next_msg);
        }
        else
        {
            rc = RC_NEXT_REQUEST_FULL;
        }
    }
    else
    {
        if (iv_next_response.empty())
        {
            iv_next_response = std::move(i_next_msg);
        }
        else
        {
            rc = RC_NEXT_RESPONSE_FULL;
        }
    }

    } while (0);

    return rc;
}

void init_pldm()
{
    PLDM_ENTER("init_pldm");

    // Tell the BMC that we are now ready to handle HRESET requests.
    PLDM::notifySbeHresetsReady(true);

    PLDM_EXIT("init_pldm");
}

struct registerinitPldm
{
    registerinitPldm()
    {
        // Register interface for Host to call
        postInitCalls_t * rt_post = getPostInitCalls();
        rt_post->callInitPldm = &init_pldm;
    }
};

registerinitPldm g_registerinitPldm;
