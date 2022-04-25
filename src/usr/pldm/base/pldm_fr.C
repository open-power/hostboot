/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/base/pldm_fr.C $                                 */
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

#include <debugpointers.H>
#include <pldm/pldmif.H>
#include "pldm_fr.H"

void PLDM::logPldmMsg(const pldm_msg_hdr* const i_hdr, PLDM::traffic_direction i_dir)
{
    Singleton<pldmFR>::instance().logMsg(i_hdr, i_dir);
}


pldmFR::pldmFR(void)
{
    iv_frMutex = MUTEX_INITIALIZER;
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

    // Lock a mutex so that we don't have to worry about returning invalid trace data
    const auto lock = scoped_mutex_lock(iv_frMutex);

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

/**
 * @brief Helper function for flight recorder (fr) dump
 *        Dumps fr data into o_frData from oldest to newest
 *        T = pldm_msg_hdr or pldm_rsp_hdr type
 * @param[in] i_frPtr Pointer to particular flight recorder array
 * @param[in] i_frMaxSize Maximum size of flight recorder
 * @param[in] i_frIndex Current index into fr array for next data entry
 * @param[out] o_frData fr data from oldest to newest
 */
template<typename T>
void dumpEitherFr(T * i_frPtr, size_t i_frMaxSize, size_t i_frIndex, std::vector<T>& o_frData)
{
    o_frData.clear();

    T blankType = {0};

    // check if next entry is blank (no looping yet)
    if (!memcmp(&(i_frPtr[i_frIndex]), &blankType, sizeof(T)))
    {
        o_frData.insert( o_frData.end(),
                         i_frPtr,
                         &(i_frPtr[i_frIndex]) );
    }
    else
    {
        if (i_frIndex+1 >= i_frMaxSize)
        {
            o_frData.push_back(i_frPtr[i_frIndex]);
            o_frData.insert( o_frData.end(),
                             i_frPtr,
                             &(i_frPtr[i_frIndex]) );
        }
        else
        {
            o_frData.insert( o_frData.end(),
                             &(i_frPtr[i_frIndex]),
                             &(i_frPtr[i_frMaxSize]) );
            if (i_frIndex > 0)
            {
                o_frData.insert( o_frData.end(),
                                 i_frPtr,
                                 &(i_frPtr[i_frIndex]) );
            }
        }
    }
}

void pldmFR::dumpRequestFr(const PLDM::traffic_direction i_dir, std::vector<pldm_msg_hdr>& o_frData)
{
    // Lock a mutex so that we don't have to worry about returning invalid trace data
    const auto lock = scoped_mutex_lock(iv_frMutex);

    if (i_dir == PLDM::INBOUND)
    {
        dumpEitherFr(iv_inReq_fr, iv_frMax, iv_inReq_fr_index, o_frData);
    }
    else
    {
        dumpEitherFr(iv_outReq_fr, iv_frMax, iv_outReq_fr_index, o_frData);
    }
}

void pldmFR::dumpResponseFr(PLDM::traffic_direction i_dir, std::vector<pldm_rsp_hdr>& o_frData)
{
    // Lock a mutex so that we don't have to worry about returning invalid trace data
    const auto lock = scoped_mutex_lock(iv_frMutex);

    if (i_dir == PLDM::INBOUND)
    {
        dumpEitherFr(iv_inRsp_fr, iv_frMax, iv_inRsp_fr_index, o_frData);
    }
    else
    {
        dumpEitherFr(iv_outRsp_fr, iv_frMax, iv_outRsp_fr_index, o_frData);
    }
}
