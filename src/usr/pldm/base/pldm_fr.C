/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/base/pldm_fr.C $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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

#include <debugpointers.H>
#include <pldm/pldmif.H>
#include "pldm_fr.H"

void PLDM::logPldmMsg(const pldm_msg_hdr* const i_hdr, PLDM::traffic_direction i_dir)
{
    Singleton<pldmFR>::instance().logMsg(i_hdr, i_dir);
}

pldmFR::pldmFR(void)
{
    iv_frMax = FLIGHT_RECORDER_MAX;
    for(size_t i = 0; i < iv_frMax; i++)
    {
        iv_outReq_fr[i] = {0};
        iv_inReq_fr[i] = {0};
        iv_outRsp_fr[i] = {0};
        iv_inRsp_fr[i] = {0};
    }

    iv_outReq_fr_index = 0;
    iv_inReq_fr_index = 0;
    iv_outRsp_fr_index = 0;
    iv_inRsp_fr_index = 0;

    DEBUG::add_debug_pointer(DEBUG::PLDMFRMAX,
                             &iv_frMax,
                             sizeof(iv_frMax));
    /* Outbound request pointers */
    DEBUG::add_debug_pointer(DEBUG::PLDMOUTREQFR,
                             &iv_outReq_fr,
                             sizeof(pldm_msg_hdr)*iv_frMax);
    DEBUG::add_debug_pointer(DEBUG::PLDMOUTREQNEXT,
                             &iv_outReq_fr_index,
                             sizeof(iv_outReq_fr_index));
    /* Inbound request pointers */
    DEBUG::add_debug_pointer(DEBUG::PLDMINREQFR,
                             &iv_inReq_fr,
                             sizeof(pldm_msg_hdr)*iv_frMax);
    DEBUG::add_debug_pointer(DEBUG::PLDMINREQNEXT,
                             &iv_inReq_fr_index,
                             sizeof(iv_inReq_fr_index));
    /* Outbound response pointers */
    DEBUG::add_debug_pointer(DEBUG::PLDMOUTRSPFR,
                             &iv_outRsp_fr,
                             sizeof(pldm_rsp_hdr)*iv_frMax);
    DEBUG::add_debug_pointer(DEBUG::PLDMOUTRSPNEXT,
                             &iv_outRsp_fr_index,
                             sizeof(iv_outRsp_fr_index));
    /* Inbound response pointers */
    DEBUG::add_debug_pointer(DEBUG::PLDMINRSPFR,
                             &iv_inRsp_fr,
                             sizeof(pldm_rsp_hdr)*iv_frMax);
    DEBUG::add_debug_pointer(DEBUG::PLDMINRSPNEXT,
                             &iv_inRsp_fr_index,
                             sizeof(iv_inRsp_fr_index));
}

void pldmFR::logMsg(const pldm_msg_hdr* const &i_hdr, PLDM::traffic_direction &i_dir)
{
    size_t entry_size = 0;
    size_t* fr_index_ptr = nullptr;
    void * fr_next_entry_ptr = nullptr;

    if(i_hdr->request)
    {
        entry_size = sizeof(pldm_msg_hdr);
        fr_index_ptr = (i_dir == PLDM::INBOUND) ? &iv_inReq_fr_index : &iv_outReq_fr_index;
        fr_next_entry_ptr = reinterpret_cast<void*>((i_dir == PLDM::INBOUND) ? &iv_inReq_fr[*fr_index_ptr] : &iv_outReq_fr[*fr_index_ptr]);
    }
    else
    {
        entry_size = sizeof(pldm_rsp_hdr);
        fr_index_ptr = (i_dir == PLDM::INBOUND) ? &iv_inRsp_fr_index : &iv_outRsp_fr_index;
        fr_next_entry_ptr = reinterpret_cast<void*>((i_dir == PLDM::INBOUND) ? &iv_inRsp_fr[*fr_index_ptr] : &iv_outRsp_fr[*fr_index_ptr]);
    }

    assert(entry_size != 0, "pldmFR::logMsg: entry_size not getting set");
    assert(fr_index_ptr != nullptr, "pldmFR::logMsg: fr_index_ptr not getting set");
    assert(fr_next_entry_ptr != nullptr, "pldmFR::logMsg: fr_next_entry_ptr not getting set");

    memcpy(fr_next_entry_ptr, reinterpret_cast<const void*>(i_hdr), entry_size);

    if((*fr_index_ptr)++ >= (iv_frMax-1))
    {
        *fr_index_ptr = 0;
    }
}