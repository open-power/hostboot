/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/extended/pdr_manager.C $                         */
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

/* @file pdr_manager.C
 *
 * @brief Implementation file for PdrManager class
 */

#include <pldm/extended/pdr_manager.H>
#include <pldm/extended/hb_pdrs.H>
#include <pldm/requests/pldm_pdr_requests.H>
#include <pldm/pldm_reasoncodes.H>
#include "../common/pldmtrace.H"

#include <util/singleton.H>

#include <pdr.h>
#include <platform.h>

#include <sys/msg.h>

using namespace PLDM;
using namespace ERRORLOG;

namespace
{

using mutex_lock_t = std::unique_ptr<mutex_t, void(*)(mutex_t*)>;

/* @brief Locks a mutex and returns an object which owns the lock. The object
 *        will automatically unlock the mutex when it is destroyed.
 *
 * @param[in] i_mutex  Mutex to lock
 * @return mutex_lock_t  Lock object
 */
mutex_lock_t scoped_mutex_lock(mutex_t& i_mutex)
{
    mutex_lock(&i_mutex);
    return { &i_mutex, mutex_unlock };
}

/* @brief findPdr_impl
 *
 *        This function is the same as findPdr but doesn't lock the PdrManager
 *        mutex. See PdrManager::findPdr for documentation.
 */
bool findPdr_impl(pdr_handle_t& io_record_handle,
                  const uint8_t*& o_data,
                  uint32_t& o_size,
                  uint32_t& o_next_record_handle,
                  const pldm_pdr* const i_pdr_repo)
{
    const bool found = pldm_pdr_find_record(i_pdr_repo,
                                            io_record_handle,
                                            const_cast<uint8_t**>(&o_data),
                                            &o_size,
                                            &o_next_record_handle);

    if (found)
    {
        assert(o_size >= sizeof(pldm_pdr_hdr),
               "PDR data is smaller than PDR header size (size is %u, expecting at least %llu)",
               o_size,
               sizeof(pldm_pdr_hdr));

        // Update the record handle (specifically for the case where we request
        // PDR handle 0, the real handle for the first PDR in the repository
        // could be any number).
        io_record_handle = le32toh(reinterpret_cast<const pldm_pdr_hdr*>(o_data)->record_handle);
    }

    return found;
}

}

namespace PLDM
{

PdrManager::PdrManager()
    : iv_pdr_repo(nullptr, pldm_pdr_destroy),
      iv_access_mutex(MUTEX_INITIALIZER),
      iv_access_mutex_owner(&iv_access_mutex, mutex_destroy)
#ifndef __HOSTBOOT_RUNTIME
      ,iv_bmc_repo_changed_event_q(msg_q_create(), msg_q_destroy)
#endif
{
    resetPdrs();
}

void PdrManager::resetPdrs()
{
    const auto lock = scoped_mutex_lock(iv_access_mutex);

    iv_pdr_repo.reset(pldm_pdr_init());
}

errlHndl_t PdrManager::addRemotePdrs()
{
    const auto lock = scoped_mutex_lock(iv_access_mutex);

    return getRemotePdrRepository(iv_pdr_repo.get());
}

errlHndl_t PdrManager::addLocalPdrs()
{
    const auto lock = scoped_mutex_lock(iv_access_mutex);

    return addHostbootPdrs(iv_pdr_repo.get());
}

size_t PdrManager::pdrCount() const
{
    const auto lock = scoped_mutex_lock(iv_access_mutex);

    return pldm_pdr_get_record_count(iv_pdr_repo.get());
}

bool PdrManager::findPdr(pdr_handle_t& io_record_handle,
                         std::vector<uint8_t>* const o_data,
                         uint32_t& o_next_record_handle) const
{
    const auto lock = scoped_mutex_lock(iv_access_mutex);

    const uint8_t* data = nullptr;
    uint32_t data_size = 0;

    const bool found = findPdr_impl(io_record_handle,
                                    data,
                                    data_size,
                                    o_next_record_handle,
                                    iv_pdr_repo.get());

    if (found && o_data)
    {
        o_data->assign(data, data + data_size);
    }

    return found;
}

errlHndl_t PdrManager::invalidateHBTerminusLocatorPdr()
{
    errlHndl_t l_errl = nullptr;
    uint32_t l_pdr_handle = 0;

    // Grab a temp scope to lock the PDR mutex for the duration of
    // the operations on the PDR repo
    {
    const auto lock = scoped_mutex_lock(iv_access_mutex);
    pldm_terminus_locator_pdr* l_terminus_locator_pdr = findHBTerminusLocatorPdr();
    if(!l_terminus_locator_pdr)
    {
        /*@
         * @errortype
         * @moduleid   MOD_PDR_MANAGER
         * @reasoncode RC_TERM_LOCATOR_NOT_FOUND
         * @devdesc    Could not find Terminus Locator PDR in the PDR repo
         * @custdesc   A software error occurred during system boot
         */
        l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                               MOD_PDR_MANAGER,
                               RC_TERM_LOCATOR_NOT_FOUND,
                               0,
                               0,
                               ErrlEntry::ADD_SW_CALLOUT);
    }
    else
    {
        l_terminus_locator_pdr->validity = PLDM_TL_PDR_NOT_VALID;
        l_pdr_handle = le32toh(l_terminus_locator_pdr->hdr.record_handle);
    }
    }

    if(l_pdr_handle)
    {
        // Tell BMC that this PDR has changed
        std::vector<uint32_t>l_pdr_handles = {l_pdr_handle};
        l_errl = sendPdrRepositoryChangeEvent(l_pdr_handles);
    }

    return l_errl;
}

pldm_terminus_locator_pdr* PdrManager::findHBTerminusLocatorPdr()
{
    const pldm_pdr_record* l_curr_record = nullptr;
    pldm_terminus_locator_pdr* l_hb_pdr = nullptr;

    do
    {
        uint8_t* l_record_data = nullptr;
        uint32_t l_record_size = 0;

        l_curr_record = pldm_pdr_find_record_by_type(iv_pdr_repo.get(),
                                                     PLDM_TERMINUS_LOCATOR_PDR,
                                                     l_curr_record,
                                                     &l_record_data,
                                                     &l_record_size);
        if(l_curr_record)
        {
            auto l_terminus_locator_record = reinterpret_cast<pldm_terminus_locator_pdr*>(l_record_data);
            if(le16toh(l_terminus_locator_record->terminus_handle) == hostbootTerminusId())
            {
                // We found the HB terminus locator; return it.
                l_hb_pdr = l_terminus_locator_record;
                break;
            }
        }
    } while(l_curr_record);
    return l_hb_pdr;
}

errlHndl_t PdrManager::sendPdrRepositoryChangeEvent(const std::vector<pdr_handle_t>& i_handles) const
{
    const auto lock = scoped_mutex_lock(iv_access_mutex);

    return sendRepositoryChangedEvent(iv_pdr_repo.get(),
                                      i_handles);
}

std::vector<pdr_handle_t> PdrManager::getAllPdrHandles() const
{
    const auto lock = scoped_mutex_lock(iv_access_mutex);

    std::vector<pdr_handle_t> pdrs;

    pdr_handle_t record_handle = FIRST_PDR_HANDLE,
                 next_record_handle = 0;

    do
    {
        const uint8_t* pdr_data = nullptr;
        uint32_t pdr_size = 0;
        if (!findPdr_impl(record_handle, pdr_data, pdr_size, next_record_handle, iv_pdr_repo.get()))
        {
            assert(false,
                   "PDR manager failed to find next record handle 0x%08x",
                   record_handle);
        }

        pdrs.push_back(record_handle);
        record_handle = next_record_handle;
    } while (record_handle != NO_MORE_PDR_HANDLES);

    return pdrs;
}


std::vector<fru_record_set_id> PdrManager::findFruRecordSetIdsByType(const entity_type i_ent_type) const
{
    const auto lock = scoped_mutex_lock(iv_access_mutex);

    std::vector<fru_record_set_id> rsis;

    const pldm_pdr_record* curr_record = nullptr;

    do
    {
        uint8_t* record_data = nullptr;
        uint32_t record_size = 0;

        curr_record =
            pldm_pdr_find_record_by_type(iv_pdr_repo.get(),
                                         PLDM_PDR_FRU_RECORD_SET,
                                         curr_record,
                                         &record_data,
                                         &record_size);

        if (curr_record)
        {

            const auto pdr_hdr
                = reinterpret_cast<const pldm_pdr_hdr*>(record_data);
            const auto record_set_pdr
                = reinterpret_cast<const pldm_pdr_fru_record_set*>(pdr_hdr + 1);

            if (le16toh(record_set_pdr->entity_type) == i_ent_type)
            {
                rsis.push_back(le16toh(record_set_pdr->fru_rsi));
            }
        }
    } while (curr_record);

    return rsis;
}

/* @brief Find an entity in the data of an entity association PDR by entity
 *        type/instance number and return the container ID of the entity.
 *
 * @param[in] data                              Entity Assocation PDR data
 * @param[in] data_size                         Data size
 * @param[in] io_entity.entity_type             Type of entity to search for
 * @param[in] io_entity.entity_instance_number  Entity instance to search for
 * @param[out] io_entity.entity_container_id    Container ID of found entity
 * @return bool Whether the entity was found
 * @note io_entity.entity_container_id is left unset if the entity is not found.
 */
// @TODO RTC 256140: Remove this function when the BMC normalizes all PDRs
static bool search_entity_assoc_pdr(const uint8_t* const data,
                                    const uint32_t data_size,
                                    pldm_entity& io_entity)
{
    bool found = false;
    pldm_entity* entities = nullptr;
    size_t num_entities = 0;

    pldm_entity_association_pdr_extract(data, data_size, &num_entities, &entities);

    std::unique_ptr<pldm_entity[], decltype(&free)>
        entities_owner(entities, free);

    entities = nullptr;

    for (size_t i = 0; i < num_entities; ++i)
    {
        if (entities_owner[i].entity_type == io_entity.entity_type
            && entities_owner[i].entity_instance_num == io_entity.entity_instance_num)
        {
            found = true;
            io_entity.entity_container_id = entities_owner[i].entity_container_id;
            break;
        }
    }

    return found;
}

// @TODO RTC 256140: Remove this function when the BMC normalizes all PDRs
bool PdrManager::findEntityByTypeAndId(pldm_entity& io_entity) const
{
    const auto lock = scoped_mutex_lock(iv_access_mutex);

    bool found = false;
    const pldm_pdr_record* entity_assoc_pdr = nullptr;

    while (true)
    {
        uint8_t* data = nullptr;
        uint32_t data_size = 0;

        entity_assoc_pdr = pldm_pdr_find_record_by_type(iv_pdr_repo.get(),
                                                        PLDM_PDR_ENTITY_ASSOCIATION,
                                                        entity_assoc_pdr,
                                                        &data,
                                                        &data_size);

        if (!entity_assoc_pdr)
        {
            break;
        }

        found = search_entity_assoc_pdr(data, data_size, io_entity);

        if (found)
        {
            break;
        }
    }

    return found;
}

#ifndef __HOSTBOOT_RUNTIME
errlHndl_t PdrManager::notifyBmcPdrRepoChanged()
{
    errlHndl_t errl = nullptr;

    /* Get an owning handle to the notification message queue. If it is null,
     * the msg_send will fail and we will report an error. */

    auto notify_q = iv_bmc_repo_changed_event_q;

    /* Send the event notification message */

    // msg contains no data, we just use it for IPC synchronization
    std::unique_ptr<msg_t, decltype(&msg_free)> msg
        { msg_allocate(), msg_free };

    const int rc = msg_send(notify_q.get(), msg.get());

    if (rc == 0)
    {
        // Transfer ownership to the receiver of the message
        msg.release();
    }
    else
    {
        PLDM_INF("PdrManager::notifyBmcPdrRepoChanged: msg_send failed (rc = %d)",
                 rc);
        /*@
         * @errortype  ERRL_SEV_UNRECOVERABLE
         * @moduleid   MOD_PDR_MANAGER
         * @reasoncode RC_SEND_FAIL
         * @userdata1  Return code from message send routine
         * @devdesc    Software problem, failed to send IPC message
         * @custdesc   A software error occurred during system boot
         */
        errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                             MOD_PDR_MANAGER,
                             RC_SEND_FAIL,
                             rc,
                             0,
                             ErrlEntry::ADD_SW_CALLOUT);
    }

    return errl;
}

errlHndl_t PdrManager::awaitBmcPdrRepoChanged(const size_t i_timeout_ms)
{
    // @TODO RTC 249701: Add watchdog timer for the msg_wait below
    assert(i_timeout_ms == TIMEOUT_NONE,
           "awaitBmcPdrRepoChanged: timeout not supported");

    // This mutex protects this function from being called while another task is
    // already waiting on a message.
    static mutex_t wait_mutex = MUTEX_INITIALIZER;

    errlHndl_t errl = nullptr;

    const auto lock = scoped_mutex_lock(wait_mutex);

    // Get a local handle to the event queue to keep it alive while we use
    // it.
    std::shared_ptr<void> msgq = iv_bmc_repo_changed_event_q;

    if (msgq)
    {
        msg_t* msg = msg_wait(msgq.get());

        msg_free(msg);
        msg = nullptr;

        // Null out the event queue so that it gets destroyed when we exit this
        // function, to prevent messages from accumulating in the queue and
        // never being dequeued.
        iv_bmc_repo_changed_event_q = nullptr;
    }
    else
    {
        /*@
         * @errortype  ERRL_SEV_PREDICTIVE
         * @moduleid   MOD_PDR_MANAGER
         * @reasoncode RC_MULTIPLE_AWAIT
         * @devdesc    Software problem, multiple awaits on PDR manager
         * @custdesc   A software error occurred during system boot
         */
        errl = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                             MOD_PDR_MANAGER,
                             RC_MULTIPLE_AWAIT,
                             0,
                             0,
                             ErrlEntry::ADD_SW_CALLOUT);

    }

    return errl;
}

#endif

bool PdrManager::findEntityByFruRecordSetId(const fru_record_set_id i_rsid,
                                            pldm_entity& o_entity) const
{
    const auto lock = scoped_mutex_lock(iv_access_mutex);

    terminus_id_t terminus_id = 0;

    return pldm_pdr_fru_record_set_find_by_rsi(iv_pdr_repo.get(),
                                               i_rsid,
                                               &terminus_id,
                                               &o_entity.entity_type,
                                               &o_entity.entity_instance_num,
                                               &o_entity.entity_container_id);
}

PdrManager& thePdrManager()
{
    return Singleton<PdrManager>::instance();
}

}
