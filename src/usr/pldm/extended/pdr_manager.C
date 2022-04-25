/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/extended/pdr_manager.C $                         */
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

/* @file pdr_manager.C
 *
 * @brief Implementation file for PdrManager class
 */

#include <errl/errlmanager.H>

#include <pldm/extended/pdr_manager.H>
#include <pldm/extended/hb_pdrs.H>
#include <pldm/requests/pldm_pdr_requests.H>
#include <pldm/pldm_reasoncodes.H>
#include <pldm/pldm_errl.H>
#include <pldm/pldm_response.H>
#include <pldm/pldm_trace.H>

#include <util/singleton.H>

#include "openbmc/libmctp/libmctp-astlpc.h"
#include <openbmc/pldm/libpldm/platform.h>
#include <openbmc/pldm/libpldm/pdr.h>
#include <openbmc/pldm/libpldm/state_set.h>

#include <sys/msg.h>
#include <util/misc.H>


#include <targeting/common/targetservice.H>

using namespace PLDM;
using namespace ERRORLOG;
using namespace TARGETING;

namespace
{

// Used with the libpldm pldm_pdr_add API
const bool PDR_IS_NOT_REMOTE = false;
const int PDR_AUTO_CALCULATE_RECORD_HANDLE = 0;

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

/* @brief Find a Terminus Locator PDR associated with Hostboot
 *
 * @param[in] i_repo  The PDR repository to search
 *
 * @return The pointer to the Terminus Locator PDR structure if
 *         it is found in the PDR repo, or nullptr if not found
 */
pldm_terminus_locator_pdr* findHBTerminusLocatorPdr(const pldm_pdr* i_repo);

errlHndl_t PdrManager::invalidateHBTerminusLocatorPdr()
{
    errlHndl_t l_errl = nullptr;
    uint32_t l_pdr_handle = 0;

    // Grab a temp scope to lock the PDR mutex for the duration of
    // the operations on the PDR repo
    {
    const auto lock = scoped_mutex_lock(iv_access_mutex);
    pldm_terminus_locator_pdr* l_terminus_locator_pdr = findHBTerminusLocatorPdr(iv_pdr_repo.get());
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
        addPdrCounts(l_errl);
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

pldm_terminus_locator_pdr* findHBTerminusLocatorPdr(const pldm_pdr* const i_repo)
{
    const pldm_pdr_record* l_curr_record = nullptr;
    pldm_terminus_locator_pdr* l_hb_pdr = nullptr;

    do
    {
        uint8_t* l_record_data = nullptr;
        uint32_t l_record_size = 0;

        l_curr_record = pldm_pdr_find_record_by_type(i_repo,
                                                     PLDM_TERMINUS_LOCATOR_PDR,
                                                     l_curr_record,
                                                     &l_record_data,
                                                     &l_record_size);
        if(l_curr_record)
        {
            auto l_terminus_locator_record = reinterpret_cast<pldm_terminus_locator_pdr*>(l_record_data);
            if(le16toh(l_terminus_locator_record->terminus_handle) == PdrManager::hostbootTerminusId())
            {
                // We found the HB terminus locator; return it.
                l_hb_pdr = l_terminus_locator_record;
                break;
            }
        }
    } while(l_curr_record);
    return l_hb_pdr;
}

#ifndef __HOSTBOOT_RUNTIME
errlHndl_t PdrManager::checkForHbTerminusLocator()
{
    // Grab a temp scope to lock the PDR mutex for the duration of
    // the operations on the PDR repo
    errlHndl_t l_errl = nullptr;

    const auto lock = scoped_mutex_lock(iv_access_mutex);
    pldm_terminus_locator_pdr* l_terminus_locator_pdr = findHBTerminusLocatorPdr(iv_pdr_repo.get());
    if (!l_terminus_locator_pdr)
    {
        const auto sys = UTIL::assertGetToplevelTarget();

        /*@
         * @errortype
         * @moduleid   MOD_CHECK_FOR_HB_TERMINUS_LOCATOR
         * @reasoncode RC_TERM_LOCATOR_NOT_FOUND
         * @userdata1  Count of BMC/HB PDRs
         * @userdata2  Count of HB PDRs
         * @devdesc    Could not find Terminus Locator PDR in the PDR repo
         * @custdesc   A software error occurred during system boot
         */
        l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                               MOD_CHECK_FOR_HB_TERMINUS_LOCATOR,
                               RC_TERM_LOCATOR_NOT_FOUND,
                               sys->getAttr<ATTR_PLDM_BMC_PDR_COUNT>(),
                               sys->getAttr<ATTR_PLDM_HB_PDR_COUNT>(),
                               ErrlEntry::ADD_SW_CALLOUT);
    }

    return l_errl;
}
#endif

bool PdrManager::entity_id_component_equal(const uint16_t i_haystack, const uint16_t i_needle)
{
    return i_needle == PdrManager::ENTITY_ID_DONTCARE || le16toh(i_haystack) == i_needle;
}

effecter_id_t PdrManager::findStateEffecterId(const pldm_state_set_ids i_state_set_id,
                                              const pldm_entity i_entity_id)
{
    effecter_id_t effecter_id = 0;

    foreachPdrOfType(PLDM_STATE_EFFECTER_PDR,
                     [&effecter_id, i_entity_id, i_state_set_id]
                     (const uint8_t* const pdr_data, const uint32_t pdr_data_size)
                     {
                         const auto state_effecter_pdr =
                             reinterpret_cast<const pldm_state_effecter_pdr*>(pdr_data);

                         if (entity_id_component_equal(state_effecter_pdr->entity_type, i_entity_id.entity_type)
                             && entity_id_component_equal(state_effecter_pdr->entity_instance, i_entity_id.entity_instance_num)
                             && entity_id_component_equal(state_effecter_pdr->container_id, i_entity_id.entity_container_id))
                         {
                             const uint8_t* possible_states_ptr = state_effecter_pdr->possible_states;

                             for (int i = 0; i < state_effecter_pdr->composite_effecter_count; ++i)
                             {
                                 const auto possible_states =
                                     reinterpret_cast<const state_effecter_possible_states*>(possible_states_ptr);

                                 if(le16toh(possible_states->state_set_id) == i_state_set_id)
                                 {
                                     // We found the pdr; return its effecter id.
                                     effecter_id = le16toh(state_effecter_pdr->effecter_id);
                                     return true; // halt iteration
                                 }

                                 possible_states_ptr += (sizeof(*possible_states)
                                                         - sizeof(possible_states->states) // subtract size of variable-length array
                                                         + possible_states->possible_states_size);
                             }
                         }

                         return false; // continue iteration
                     });

    return effecter_id;
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

std::vector<pldm_entity> PdrManager::findEntityAssociationsByContainer(const uint16_t i_containerId) const
{
    std::vector<pldm_entity> assocEntities;

    PLDM_DBG(">> findEntityAssociationsByContainer(big endian 0x%04X)", i_containerId);
    uint16_t leContainerId = htole16(i_containerId);

    foreachPdrOfType(PLDM_PDR_ENTITY_ASSOCIATION,
                     [&assocEntities, leContainerId]
                     (const uint8_t* const pdr_data, const uint32_t pdr_data_size)
                     {
                          const auto pdr_hdr
                              = reinterpret_cast<const pldm_pdr_hdr*>(pdr_data);
                          const auto entity_assoc_pdr
                              = reinterpret_cast<const pldm_pdr_entity_association*>(pdr_hdr + 1);
                          if (entity_assoc_pdr->container_id == leContainerId)
                          {
                              PLDM_DBG("findEntityAssociationsByContainer(0x%04X): "
                                  "ENTITY_ASSOC: containerId 0x%04X, association_type 0x%02X, "
                                  "Container => entity_type 0x%04X, "
                                  "entity_instance_num 0x%04X, container_id 0x%04X",
                                  leContainerId,
                                  entity_assoc_pdr->container_id,
                                  entity_assoc_pdr->association_type,
                                  entity_assoc_pdr->container.entity_type,
                                  entity_assoc_pdr->container.entity_instance_num,
                                  entity_assoc_pdr->container.entity_container_id);

                              assocEntities.push_back(entity_assoc_pdr->container);
                          }
                          else
                          {
                              PLDM_DBG("findEntityAssociationsByContainer(0x%04X): "
                                  "ID 0x%04X --> container: 0x%04X/0x%04X/0x%04X, num_children %d",
                                  leContainerId,
                                  entity_assoc_pdr->container_id,
                                  entity_assoc_pdr->container.entity_type,
                                  entity_assoc_pdr->container.entity_instance_num,
                                  entity_assoc_pdr->container.entity_container_id,
                                  entity_assoc_pdr->num_children);
                          }
                          return false; // check next pdr
                     });

    PLDM_DBG("<< findEntityAssociationsByContainer(0x%04X) - list %d", i_containerId, assocEntities.size());
    return assocEntities;
}


std::vector<fru_record_set_id> PdrManager::findFruRecordSetIdsByType(const entity_type i_ent_type, const terminus_id_t i_terminus_id) const
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
                uint16_t tid = le16toh(record_set_pdr->terminus_handle);
                if ((i_terminus_id == TERMINUS_ID_ALL) ||
                    (i_terminus_id == tid))
                {
                    PLDM_DBG("findFruRecordSetIdsByType(0x%04X, 0x%04X): "
                        "FRU: th 0x%04X, fru_rsi 0x%04X, entity_type 0x%04X, "
                        "entity_instance_num 0x%04X, container_id 0x%04X",
                        i_ent_type, i_terminus_id,
                        record_set_pdr->terminus_handle,
                        record_set_pdr->fru_rsi,
                        record_set_pdr->entity_type,
                        record_set_pdr->entity_instance_num,
                        record_set_pdr->container_id);

                    rsis.push_back(le16toh(record_set_pdr->fru_rsi));
                }
                else
                {
                    PLDM_DBG("findFruRecordSetIdsByType(0x%04X, 0x%04X): "
                        "SKIPPING FRU: th 0x%04X, fru_rsi 0x%04X, entity_type 0x%04X, "
                        "entity_instance_num 0x%04X, container_id 0x%04X",
                        i_ent_type, i_terminus_id,
                        record_set_pdr->terminus_handle,
                        record_set_pdr->fru_rsi,
                        record_set_pdr->entity_type,
                        record_set_pdr->entity_instance_num,
                        record_set_pdr->container_id);
                }
            }
        }
    } while (curr_record);

    return rsis;
}

/* @brief The number of pldm_state_query_record_t we need to allocate to hold an
 *        instance of ATTR_PLDM_STATE_QUERY_RECORDS_type.
 */
constexpr size_t NUM_STATE_QUERY_RECORDS
    = (sizeof(ATTR_PLDM_STATE_QUERY_RECORDS_type) / sizeof(PdrManager::pldm_state_query_record_t)) + 1;

using pldm_state_query_records = std::array<PdrManager::pldm_state_query_record_t, NUM_STATE_QUERY_RECORDS>;

/* @brief Read the array of pldm state query records from the system's
 *        PLDM_STATE_QUERY_RECORDS attribute.
 *
 * @param[in] i_sys  System target
 * @return array     Array of records.
 */
static pldm_state_query_records readPldmStateQueryRecords(Target* const i_sys)
{
    pldm_state_query_records records = { };
    const bool read
        = i_sys->tryGetAttr<ATTR_PLDM_STATE_QUERY_RECORDS>(*reinterpret_cast<ATTR_PLDM_STATE_QUERY_RECORDS_type*>(&records));
    assert(read, "Can't read ATTR_PLDM_STATE_QUERY_RECORDS from system target");
    return records;
}

/* @brief Write an array of pldm state query records to the system's
 *        PLDM_STATE_QUERY_RECORDS attribute.
 *
 * @param[in] i_sys      System target
 * @param[in] i_records  Array of PLDM state query records
 */
static void writePldmStateQueryRecords(Target* const i_sys, const pldm_state_query_records& i_records)
{
    const bool read =
        i_sys->trySetAttr<ATTR_PLDM_STATE_QUERY_RECORDS>(*reinterpret_cast<const ATTR_PLDM_STATE_QUERY_RECORDS_type*>(&i_records));
    assert(read, "Can't set ATTR_PLDM_STATE_QUERY_RECORDS on system target");
}

/* @brief Add a PLDM state query record to the system's PLDM_STATE_QUERY_RECORDS
 *        attribute.
 *
 * @param[in] i_record  The record to add.
 */
static void appendStateQueryInfo(const PdrManager::pldm_state_query_record_t i_record)
{
    const auto sys = UTIL::assertGetToplevelTarget();
    const auto num_records = sys->getAttr<ATTR_NUM_PLDM_STATE_QUERY_RECORDS>();
    constexpr auto max_possible_records = sizeof(ATTR_PLDM_STATE_QUERY_RECORDS_type) / sizeof(PdrManager::pldm_state_query_record_t);

    assert(num_records + 1 < max_possible_records,
           "Too many PLDM state query handlers registered (max %d)",
           max_possible_records);

    /* Read the existing records, add one, then write them back */

    auto records = readPldmStateQueryRecords(sys);
    records[num_records] = i_record;
    writePldmStateQueryRecords(sys, records);
    sys->setAttr<ATTR_NUM_PLDM_STATE_QUERY_RECORDS>(num_records + 1);
}

void PdrManager::AssertInvalidRange(const state_query_id_t next_state_query_id)
{
    errlHndl_t errl = nullptr;
    /*@
     * @moduleid   MOD_PDR_MANAGER
     * @reasoncode RC_INVALID_OFFSET_ID
     * @userdata1  HB_PLDM_SENSOR_EFFECTER_ID_RANGE_END
     * @userdata2  The Out of Range Next Query ID
     * @devdesc    Software problem, overrun state sensor/effecter IDs
     * @custdesc   A software error occurred during system boot
     */
    errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                         MOD_PDR_MANAGER,
                         RC_INVALID_OFFSET_ID,
                         HB_PLDM_SENSOR_EFFECTER_ID_RANGE_END,
                         next_state_query_id,
                         ErrlEntry::NO_SW_CALLOUT);
    addBmcErrorCallouts(errl);
    errlCommit(errl, PLDM_COMP_ID);
    // We commit the errl to have an identifier as to why we assert,
    // this condition should -NOT- happen
    assert(false, "Exceeded Hostboot PDR ID range");
}

void PdrManager::addStateSensorPdr(Target* const i_target,
                                   const pldm_entity& i_entity,
                                   const uint16_t i_state_set_id,
                                   const uint32_t i_possible_states,
                                   const state_query_handler_id_t i_qhandler,
                                   const uint64_t i_userdata)
{
    const auto lock = scoped_mutex_lock(iv_access_mutex);

    // state_sensor_possible_states.states is a variable-length array
    uint8_t state_storage[sizeof(state_sensor_possible_states)
                          + sizeof(i_possible_states)
                          - sizeof(state_sensor_possible_states::states)] = {};
    auto possible_states = reinterpret_cast<state_sensor_possible_states*>(state_storage);

    // fill in possible states structure
    possible_states->state_set_id = i_state_set_id;
    possible_states->possible_states_size = sizeof(i_possible_states);

    // need to swap the byte order for little endian order
    uint32_t swapped = htole32(i_possible_states);
    memcpy(possible_states->states, &swapped, sizeof(swapped));


    /* Create and encode the PDR. */

    uint8_t encoded_pdr[sizeof(pldm_state_sensor_pdr) + sizeof(state_storage)] = { };

    const auto pdr = reinterpret_cast<pldm_state_sensor_pdr*>(encoded_pdr);

    *pdr =
    {
        /// Header
        .hdr =
        {
            .record_handle = 0, // ask libpldm to fill this out
            .version = 0, // will be filled out by the encoder
            .type = 0, // will be filled out by the encoder
            .record_change_num = 0,
            .length = 0 // will be filled out by the encoder
        },

        /// Body
        .terminus_handle = hostbootTerminusId(),

        .sensor_id = iv_next_state_query_id,

        .entity_type = i_entity.entity_type,
        .entity_instance = i_entity.entity_instance_num,
        .container_id = i_entity.entity_container_id,

        .sensor_init = PLDM_NO_INIT,
        .sensor_auxiliary_names_pdr = false,
        .composite_sensor_count = 1
    };

    size_t actual_pdr_size = 0;

    const int rc = encode_state_sensor_pdr(pdr, sizeof(encoded_pdr), possible_states, sizeof(state_storage), &actual_pdr_size);

    assert(rc == PLDM_SUCCESS,
           "Failed to encode state sensor PDR");

    /* Add the PDR to the PDR repository. */

    pldm_pdr_add(iv_pdr_repo.get(), encoded_pdr, actual_pdr_size,
                 PDR_AUTO_CALCULATE_RECORD_HANDLE,
                 PDR_IS_NOT_REMOTE);

    PLDM_INF("Added state sensor PDR for target 0x%08x, sensor id = 0x%08x, state set ID = %d",
             get_huid(i_target),
             iv_next_state_query_id,
             i_state_set_id);

    /* Update record-keeping state */

    const pldm_state_query_record_t query_record
    {
        .target_huid = get_huid(i_target),
        .query_id = iv_next_state_query_id,
        .state_set_id = i_state_set_id,
        .function_id = i_qhandler,
        .query_type = STATE_QUERY_SENSOR,
        .userdata = i_userdata
    };

    appendStateQueryInfo(query_record);

    ++iv_next_state_query_id;
    if (iv_next_state_query_id > HB_PLDM_SENSOR_EFFECTER_ID_RANGE_END)
    {
        // This should -NOT- ever happen
        PLDM_ERR("addStateSensorPdr HB_PLDM_SENSOR_EFFECTER_ID_RANGE_END reached, this should -NOT- have happened");
        AssertInvalidRange(iv_next_state_query_id);
    }
}

void PdrManager::addStateEffecterPdr(Target* const i_target,
                                     const pldm_entity& i_entity,
                                     const uint16_t i_state_set_id,
                                     const uint8_t i_possible_states,
                                     const state_query_handler_id_t i_qhandler,
                                     const uint64_t i_userdata)

{
    const auto lock = scoped_mutex_lock(iv_access_mutex);

    const state_effecter_possible_states states =
    {
        .state_set_id = i_state_set_id,
        .possible_states_size = 1, // size of possible_states
        .states = { i_possible_states } // possible_states (only support 1 byte of states right now)
    };

    uint8_t encoded_pdr[sizeof(pldm_state_effecter_pdr) + sizeof(states)];

    const auto pdr = reinterpret_cast<pldm_state_effecter_pdr*>(encoded_pdr);

    *pdr =
    {
        /// Header
        .hdr =
        {
            .record_handle = 0, // ask libpldm to fill this out
            .version = 0, // will be filled out by the encoder
            .type = 0, // will be filled out by the encoder
            .record_change_num = 0,
            .length = 0 // will be filled out by the encoder
        },

        /// Body
        .terminus_handle = hostbootTerminusId(),

        .effecter_id = iv_next_state_query_id,

        .entity_type = i_entity.entity_type,
        .entity_instance = i_entity.entity_instance_num,
        .container_id = i_entity.entity_container_id,

        .effecter_semantic_id = 0, // PLDM defines no semantic IDs yet
        .effecter_init = PLDM_NO_INIT,
        .has_description_pdr = false,
        .composite_effecter_count = 1
    };

    size_t actual_pdr_size = 0;

    const int rc = encode_state_effecter_pdr(pdr, sizeof(encoded_pdr), &states, sizeof(states), &actual_pdr_size);

    assert(rc == PLDM_SUCCESS,
           "Failed to encode state effecter PDR");

    pldm_pdr_add(iv_pdr_repo.get(), encoded_pdr, actual_pdr_size,
                 PDR_AUTO_CALCULATE_RECORD_HANDLE,
                 PDR_IS_NOT_REMOTE);

    PLDM_INF("Added state effecter PDR for target 0x%08x, sensor id = 0x%08x, state set id = %d",
             get_huid(i_target),
             iv_next_state_query_id,
             i_state_set_id);

    const pldm_state_query_record_t query_record
    {
        .target_huid = get_huid(i_target),
        .query_id = iv_next_state_query_id,
        .state_set_id = i_state_set_id,
        .function_id = i_qhandler,
        .query_type = STATE_QUERY_EFFECTER,
        .userdata = i_userdata
    };

    appendStateQueryInfo(query_record);

    ++iv_next_state_query_id;
    if (iv_next_state_query_id > HB_PLDM_SENSOR_EFFECTER_ID_RANGE_END)
    {
        // This should -NOT- ever happen
        PLDM_ERR("addStateEffecterPdr HB_PLDM_SENSOR_EFFECTER_ID_RANGE_END reached, this should -NOT- have happened");
        AssertInvalidRange(iv_next_state_query_id);
    }
}

/**
 * @brief Populates the input Terminus Locator PDR with the correct data for
 *        if to be added to a PDR repository.
 *
 * @param[in] i_pdr the input PDR pointer to be populated
 */
void generateTerminusLocatorPDR(pldm_terminus_locator_pdr* const i_pdr)
{
    const uint8_t DEFAULT_CONTAINER_ID = 0;
    i_pdr->hdr.record_handle = 0; // record_handle will be generated for us
    i_pdr->hdr.version = 1;
    i_pdr->hdr.type = PLDM_TERMINUS_LOCATOR_PDR;
    i_pdr->hdr.record_change_num = 0;
    i_pdr->hdr.length = htole16(sizeof(pldm_terminus_locator_pdr) - sizeof(pldm_pdr_hdr));
    i_pdr->terminus_handle = htole16(PLDM::thePdrManager().hostbootTerminusId());
    i_pdr->validity = PLDM_TL_PDR_VALID;
    i_pdr->tid = PLDM::thePdrManager().hostbootTerminusId();
    i_pdr->container_id = DEFAULT_CONTAINER_ID;
    i_pdr->terminus_locator_type = PLDM_TERMINUS_LOCATOR_TYPE_MCTP_EID;
    i_pdr->terminus_locator_value_size = sizeof(pldm_terminus_locator_type_mctp_eid);
    auto l_locatorValue = reinterpret_cast<pldm_terminus_locator_type_mctp_eid*>(i_pdr->terminus_locator_value);
    l_locatorValue->eid = HOST_EID;
}

void PdrManager::addTerminusLocatorPDR()
{
    const auto lock = scoped_mutex_lock(iv_access_mutex);

    pldm_terminus_locator_pdr l_pdr = { };

    generateTerminusLocatorPDR(&l_pdr);
    pldm_pdr_add(iv_pdr_repo.get(),
                 reinterpret_cast<const uint8_t*>(&l_pdr),
                 sizeof(l_pdr),
                 PDR_AUTO_CALCULATE_RECORD_HANDLE,
                 PDR_IS_NOT_REMOTE);
}

errlHndl_t PdrManager::setStateEffecterStates(const msg_q_t i_msgQ,
                                              const pldm_msg* const i_msg,
                                              const size_t i_payload_len,
                                              const pldm_set_state_effecter_states_req* const i_req)
{
    return handleStateQueryRequest(STATE_QUERY_EFFECTER, i_req->effecter_id, i_msgQ, i_msg, i_payload_len, i_req);
}

errlHndl_t PdrManager::getStateSensorReadings(const msg_q_t i_msgQ,
                                              const pldm_msg* const i_msg,
                                              const size_t i_payload_len,
                                              const pldm_get_state_sensor_readings_req* const i_req)
{
    return handleStateQueryRequest(STATE_QUERY_SENSOR, i_req->sensor_id, i_msgQ, i_msg, i_payload_len, i_req);
}

namespace
{

/* Signature for a SetStateEffecterStates callback function. */
using state_effecter_handler_t = errlHndl_t(*)(const state_effecter_callback_args&);

/* Signature for a GetStateSensorReadings callback function. */
using state_sensor_handler_t = errlHndl_t(*)(const state_sensor_callback_args&);

struct state_query_handler_t
{
    state_sensor_handler_t sensor_handler = nullptr;
    state_effecter_handler_t effecter_handler = nullptr;
};

/* @brief Array associating state query handler enumeration values with functions.
 *
 * The offset in this array should correspond to the value of the
 * state_query_handler_id_t enumeration that the function handles (e.g. array
 * element 2 should correspond to STATE_QUERY_HANDLER_OCC_STATE_QUERY).
 */
const state_query_handler_t handlers[] =
{
    { nullptr, nullptr },                               //    STATE_QUERY_HANDLER enumeration starts at 1
    { handleFunctionalStateSensorGetRequest, nullptr }, // 1: STATE_QUERY_HANDLER_FUNCTIONAL_STATE_SENSOR
    { handleOccStateSensorGetRequest,                   // 2: STATE_QUERY_HANDLER_OCC_STATE_QUERY
      handleOccSetStateEffecterRequest },
    { handleGracefulShutdownSensorGetRequest,           // 3: STATE_QUERY_HANDLER_GRACEFUL_SHUTDOWN
      handleGracefulShutdownRequest },
    { nullptr,
      handleSbeHresetRequest },                         // 4: STATE_QUERY_HANDLER_REQUEST_HRESET
    { handleAttributeBackedSensorGetRequest,            // 5: STATE_QUERY_HANDLER_ATTRIBUTE_GETTER
      nullptr },
    { nullptr,
      handleInvokeDceRequest }                          // 6: STATE_QUERY_HANDLER_INVOKE_DCE
};

state_query_handler_t get_state_handler(PdrManager::state_query_handler_id_t i_id)
{
    assert(i_id < std::size(handlers),
           "Index %d is out of bounds of sensor query handler array", i_id);

    return handlers[i_id];
}

errlHndl_t invoke_state_effecter_handler(const PdrManager::state_query_handler_id_t i_handler_id,
                                         Target* const i_target,
                                         const msg_q_t i_msgq,
                                         const pldm_msg* const i_msg,
                                         const size_t i_msgsize,
                                         const pldm_set_state_effecter_states_req& i_req,
                                         const uint64_t i_userdata)
{
    const auto handler = get_state_handler(i_handler_id);

    assert(handler.effecter_handler,
           "invoke_state_effecter_handler: Invalid effecter ID %d registered on target 0x%08x",
           i_handler_id, get_huid(i_target));

    state_effecter_callback_args args;
    args.i_target = i_target;
    args.i_msgQ = i_msgq;
    args.i_msg = i_msg;
    args.i_payload_len = i_msgsize;
    args.i_userdata = i_userdata;
    args.i_req = &i_req;

    return handler.effecter_handler(args);
}

errlHndl_t invoke_state_sensor_handler(const PdrManager::state_query_handler_id_t i_handler_id,
                                       Target* const i_target,
                                       const msg_q_t i_msgq,
                                       const pldm_msg* const i_msg,
                                       const size_t i_msgsize,
                                       const pldm_get_state_sensor_readings_req& i_req,
                                       const uint64_t i_userdata)
{
    const auto handler = get_state_handler(i_handler_id);

    assert(handler.sensor_handler,
           "invoke_state_sensor_handler: Invalid sensor ID %d registered on target 0x%08x",
           i_handler_id, get_huid(i_target));

    state_sensor_callback_args args;
    args.i_target = i_target;
    args.i_msgQ = i_msgq;
    args.i_msg = i_msg;
    args.i_payload_len = i_msgsize;
    args.i_userdata = i_userdata;
    args.i_req = &i_req;

    return handler.sensor_handler(args);
}

} // anonymous namespace

errlHndl_t PdrManager::handleStateQueryRequest(const state_query_type_t i_querytype,
                                               const state_query_id_t i_query_id,
                                               const msg_q_t i_msgQ,
                                               const pldm_msg* const i_msg,
                                               const size_t i_payload_len,
                                               const void* const i_req)
{
    PLDM_INF(ENTER_MRK"handleStateQueryRequest: query type: %d, query ID: %d", i_querytype, i_query_id);

    errlHndl_t errl = nullptr;
    uint8_t response_code = PLDM_SUCCESS; // Only sent if we don't find an appropriate query handler
    bool dynamic_handler_invoked = false, static_handler_invoked = false;

    do
    {

    /* First, invoke any dynamically registered callbacks */

#ifndef __HOSTBOOT_RUNTIME
    if (i_querytype == STATE_QUERY_EFFECTER)
    {
        dynamic_handler_invoked = invokeStateEffecterCallback(*static_cast<const pldm_set_state_effecter_states_req*>(i_req),
                                                              response_code);
    }
#endif

    /* Look up the query handler callback for this sensor. */

    Target* handler_target = nullptr;
    uint64_t callback_userdata = 0;
    uint8_t handler_function_id = STATE_QUERY_HANDLER_INVALID;

    {
        const auto sys = UTIL::assertGetToplevelTarget();
        const auto lock = scoped_mutex_lock(iv_access_mutex);
        const auto num_records = sys->getAttr<ATTR_NUM_PLDM_STATE_QUERY_RECORDS>();
        const auto records = readPldmStateQueryRecords(sys);

        for (uint32_t i = 0; i < num_records; ++i)
        {
            // A sensor and effecter will not both have the same ID, so we don't
            // need to check that.
            if (records[i].query_id == i_query_id)
            {
                handler_target = Target::getTargetFromHuid(records[i].target_huid);
                handler_function_id = records[i].function_id;
                callback_userdata = records[i].userdata;
                break;
            }
        }

        if (handler_function_id == STATE_QUERY_HANDLER_INVALID)
        {
            if (!dynamic_handler_invoked)
            {
                PLDM_ERR("PdrManager::handleStateQueryRequest: No handler for sensor/effecter ID 0x%08x",
                         i_query_id);

                /*@
                 * @errortype  ERRL_SEV_INFORMATIONAL
                 * @moduleid   MOD_PDR_MANAGER
                 * @reasoncode RC_INVALID_STATE_QUERY_ID
                 * @userdata1[0:31]  Sensor/effecter ID
                 * @userdata1[32:63] Query type (1 = sensor, 2 = effecter)
                 * @userdata2  Unused
                 * @devdesc    Software problem, invalid state sensor/effecter ID received from BMC
                 * @custdesc   A software error occurred during system boot
                 */
                errl = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                     MOD_PDR_MANAGER,
                                     RC_INVALID_STATE_QUERY_ID,
                                     TWO_UINT32_TO_UINT64(i_query_id, i_querytype),
                                     0,
                                     ErrlEntry::NO_SW_CALLOUT);
                addBmcErrorCallouts(errl);
                errlCommit(errl, PLDM_COMP_ID);
                response_code = PLDM_ERROR_NOT_READY;
                // Trace so we can observe if Hostboot encounters any issues
                // with BMC continually hitting NOT READY conditions, otherwise it
                // will not be noticed
                PLDM_INF(INFO_MRK"PLDM_ERROR_NOT_READY i_query_id=0x%08x i_querytype=0x%08x response_code=0x%08x",
                    i_query_id, i_querytype, response_code);
            }

            break;
        }
    }

    /* Invoke the appropriate callback.
     * If we actually invoke a handler, then we don't need to send a response,
     * so we don't modify response_code here, and we won't send a response
     * below. */

    static_handler_invoked = true;

    if (i_querytype == STATE_QUERY_EFFECTER)
    {
        errl = invoke_state_effecter_handler(static_cast<state_query_handler_id_t>(handler_function_id),
                                             handler_target, i_msgQ, i_msg, i_payload_len,
                                             *static_cast<const pldm_set_state_effecter_states_req*>(i_req),
                                             callback_userdata);
        break;
    }
    else if (i_querytype == STATE_QUERY_SENSOR)
    {
        errl = invoke_state_sensor_handler(static_cast<state_query_handler_id_t>(handler_function_id),
                                           handler_target, i_msgQ, i_msg, i_payload_len,
                                           *static_cast<const pldm_get_state_sensor_readings_req*>(i_req),
                                           callback_userdata);
        break;
    }

    } while (false);

    /* Reply if we didn't invoke any static handler. If we call a static query
       handler at all, it should send the response (even if there's an error
       within it or something), so we don't need to do it here.  Dynamic
       handlers, on the other hand, shouldn't send the response themselves, so
       we do want to do that for them here. */

    if (!static_handler_invoked)
    {
        PLDM::send_cc_only_response(i_msgQ, i_msg, response_code);
    }

    PLDM_INF(EXIT_MRK"handleStateQueryRequest (errl = %p)", errl);

    return errl;
}

std::vector<PdrManager::pldm_state_query_record_t> PdrManager::getHostStateQueryRecords(const Target* const i_target)
{
    const auto lock = scoped_mutex_lock(iv_access_mutex);
    std::vector<pldm_state_query_record_t> query_ids;

    const auto sys = UTIL::assertGetToplevelTarget();
    const auto num_records = sys->getAttr<ATTR_NUM_PLDM_STATE_QUERY_RECORDS>();
    const auto huid = get_huid(i_target);
    const auto records = readPldmStateQueryRecords(sys);

    for (uint32_t i = 0; i < num_records; ++i)
    {
        if (!i_target || records[i].target_huid == huid)
        {
            query_ids.push_back(records[i]);
        }
    }

    return query_ids;
}

state_query_id_t PdrManager::getHostStateQueryIdForStateSet(const state_query_type_t i_state_query_type,
                                                            const uint16_t i_state_set_id,
                                                            const Target* const i_target)
{
    state_query_id_t query_id = 0;

    for (const auto& record : thePdrManager().getHostStateQueryRecords(i_target))
    {
        if (record.state_set_id == i_state_set_id && record.query_type == i_state_query_type)
        {
            query_id = record.query_id;
            break;
        }
    }

    return query_id;
}

void PdrManager::sendAllFruFunctionalStates() const
{
    do
    {

    if (!Util::isTargetingLoaded())
    {
        PLDM_ERR("sendAllFruFunctionalStates: Cannot send FRU functional states, targeting not available");
        break;
    }

    const auto lock = scoped_mutex_lock(iv_access_mutex);

    /* Read the query handler records from the system target */

    const auto sys = UTIL::assertGetToplevelTarget();
    const auto num_records = sys->getAttr<ATTR_NUM_PLDM_STATE_QUERY_RECORDS>();
    const auto records = readPldmStateQueryRecords(sys);

    /* Iterate each registered target state sensor and send an event about its
     * status to the BMC. */

    for (uint32_t i = 0; i < num_records; ++i)
    {
        const auto record = records[i];

        if (record.state_set_id == PLDM_STATE_SET_HEALTH_STATE
            && record.query_type == STATE_QUERY_SENSOR)
        {
            Target* const target = Target::getTargetFromHuid(record.target_huid);

            assert(target, "NULL target in sendAllFruFunctionalStates (sensor ID = %d)",
                   record.query_id);

            const bool functional = target->getAttr<ATTR_HWAS_STATE>().functional;

            errlHndl_t errl
                = sendFruFunctionalStateChangedEvent(target, // target
                                                     record.query_id, // sensor ID
                                                     functional);

            PLDM_DBG("Sending FRU functional state changed event for target 0x%08x/sensor ID %d, err = %p",
                     record.target_huid,
                     record.query_id,
                     errl);

            if (errl)
            {
                errlCommit(errl, PLDM_COMP_ID);
            }
        }
    }

    } while(false);
}

errlHndl_t PdrManager::getStateSensorId(Target* const i_target, state_query_id_t &o_sensor_id)
{
    bool l_found_sensor{false};
    errlHndl_t l_err{nullptr};

    do
    {
    const auto lock = scoped_mutex_lock(iv_access_mutex);

    /* Read the query handler records from the system target */

    const auto sys = UTIL::assertGetToplevelTarget();
    const auto num_records = sys->getAttr<ATTR_NUM_PLDM_STATE_QUERY_RECORDS>();
    const auto records = readPldmStateQueryRecords(sys);

    // get target huid to match
    const auto l_target_huid = get_huid(i_target);

    /* Iterate each registered target state sensor */
    for (uint32_t i = 0; i < num_records; ++i)
    {
        const auto record = records[i];

        if (record.state_set_id == PLDM_STATE_SET_HEALTH_STATE
            && record.query_type == STATE_QUERY_SENSOR)
        {
            if (l_target_huid == record.target_huid)
            {
                o_sensor_id = record.query_id;
                l_found_sensor = true;
                break;
            }
        }
    }

    if (!l_found_sensor)
    {
        /*@
         * @moduleid   MOD_GET_STATE_SENSOR_ID
         * @reasoncode RC_NO_SENSOR
         * @userdata1  target huid
         * @userdata2  total records
         * @devdesc    Unable to find target in ATTR_PLDM_STATE_QUERY_RECORDS
         * @custdesc   Internal firmware error
         */
        l_err = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                              MOD_GET_STATE_SENSOR_ID,
                              RC_NO_SENSOR,
                              l_target_huid,
                              num_records,
                              ErrlEntry::ADD_SW_CALLOUT);

    }

    } while(0);

    return l_err;
}

void PdrManager::addFruRecordSetPdr(const fru_record_set_id_t i_rsid,
                                    const pldm_entity& i_entity)
{
    const auto lock = scoped_mutex_lock(iv_access_mutex);
    // Passing 0 as the record handle will automatically
    // assign the next record handle available to hostboot.
    const auto NEXT_RECORD_HANDLE = 0;

    pldm_pdr_add_fru_record_set(iv_pdr_repo.get(),
                                hostbootTerminusId(),
                                i_rsid,
                                i_entity.entity_type,
                                i_entity.entity_instance_num,
                                i_entity.entity_container_id,
                                NEXT_RECORD_HANDLE);
}

void PdrManager::addEntityAssociationPdrs(const pldm_entity_association_tree& i_tree, const bool i_is_remote)
{
    const auto lock = scoped_mutex_lock(iv_access_mutex);

    pldm_entity_association_pdr_add(const_cast<pldm_entity_association_tree*>(&i_tree),
                                    iv_pdr_repo.get(),
                                    i_is_remote);
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
         * @errortype
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
        addPdrCounts(errl);

        // If the queue is nullptr, that means that we've already completed the
        // PDR exchange and we are not expecting any PDR sync messages. Reduce
        // the severity of the error.
        if(notify_q == nullptr)
        {
            errl->setSev(ERRL_SEV_INFORMATIONAL);
        }

    }

    return errl;
}

errlHndl_t PdrManager::awaitBmcPdrRepoChanged(const size_t i_timeout_ms)
{
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
        uint64_t l_timeout_ms = i_timeout_ms;
        auto msgs = msg_wait_timeout(msgq.get(), l_timeout_ms);
        if (msgs.size() == 0)
        {
            PLDM_INF("msg_wait_timeout(iv_bmc_repo_changed_event_q, %lld) timed out", i_timeout_ms);
            /*@
             * @errortype
             * @moduleid   MOD_PDR_MANAGER
             * @reasoncode RC_TIMEOUT
             * @userdata1  Timeout in milliseconds
             * @userdata2  Time left in milliseconds (usually 0)
             * @devdesc    Timeout while waiting for BMC PDR repo changed event
             * @custdesc   A software error occurred during system boot
             */
            errl = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                                 MOD_PDR_MANAGER,
                                 RC_TIMEOUT,
                                 i_timeout_ms,
                                 l_timeout_ms,
                                 ErrlEntry::NO_SW_CALLOUT);
            addBmcErrorCallouts(errl);
            addPdrCounts(errl);
        }
        else
        {
            // cleanup memory for all msgs returned
            for( auto & msg : msgs)
            {
                // should not see this extra_data populated for this queue but just incase
                if (msg->extra_data != nullptr)
                {
                    free(msg->extra_data);
                    msg->extra_data = nullptr;
                }
                msg_free(msg);
                msg = nullptr;
            }
        }

        // Null out the event queue so that it gets destroyed when we exit this
        // function, to prevent messages from accumulating in the queue and
        // never being dequeued.
        iv_bmc_repo_changed_event_q = nullptr;
    }
    else
    {
        /*@
         * @errortype
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
        addPdrCounts(errl);
    }

    // checks for PLDM error and adds flight recorder data to log
    addPldmFrData(errl);

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

#ifndef __HOSTBOOT_RUNTIME

template<typename T>
static bool operator==(T i_lhs, T i_rhs)
{
    return i_lhs.msgQ == i_rhs.msgQ;
}

using std::begin;
using std::end;

void PdrManager::registerStateEffecterCallbackMsgQ(const effecter_id_t i_effecter_id,
                                                   const uint8_t i_composite_id,
                                                   const msg_q_t i_msgQ,
                                                   const uint32_t i_msg_type)
{
    const auto lock = scoped_mutex_lock(iv_access_mutex);

    effecter_registry_key_t new_key(i_effecter_id, i_composite_id);

    const effecter_registry_value_t new_value(i_msgQ, i_msg_type);

    auto& list = iv_effecter_msgq_registry[new_key.fullword];

    list.push_back(new_value);
}

void PdrManager::unregisterStateEffecterCallbackMsgQ(const effecter_id_t i_effecter_id,
                                                     const uint8_t i_composite_id,
                                                     const msg_q_t i_msgQ)
{
    const auto lock = scoped_mutex_lock(iv_access_mutex);

    effecter_registry_key_t key(i_effecter_id, i_composite_id);
    const effecter_registry_value_t remove_value(i_msgQ, 0);

    const auto list = iv_effecter_msgq_registry.find(key.fullword);

    if (list != iv_effecter_msgq_registry.end())
    {
        list->second.erase(std::remove(begin(list->second), end(list->second), remove_value),
                           end(list->second));

        if (list->second.empty()) // free up memory when we can
        {
            iv_effecter_msgq_registry.erase(list);
        }
    }
}

bool PdrManager::invokeStateEffecterCallback(const pldm_set_state_effecter_states_req& i_req,
                                             uint8_t& io_pldm_response_code)
{
    struct effecter_callback_args
    {
        effecter_registry_value_t callback_info;
        int composite_id;
        int state;
    };

    std::vector<effecter_callback_args> messages;

    /* Lock the PDR manager and find all of the message queues that have
     * registered to receive a callback about this state effecter */

    {
        const auto lock = scoped_mutex_lock(iv_access_mutex);

        for (int i = 0; i < i_req.comp_effecter_count; ++i)
        {
            if (i_req.field[i].set_request)
            {
                effecter_registry_key_t key(i_req.effecter_id, i);

                const auto it = iv_effecter_msgq_registry.find(key.fullword);

                if (it != end(iv_effecter_msgq_registry))
                {
                    for (const auto value : it->second)
                    {
                        messages.push_back({ value, i, i_req.field[i].effecter_state });
                    }
                }
            }
        }
    }

    /* With the PDR repository unlocked, send messages to each registered queue
     * and wait for a response. */

    for (const auto entry : messages)
    {
        msg_t* msg = msg_allocate();
        msg->type = entry.callback_info.msg_type;
        msg->data[0] = entry.composite_id;
        msg->data[1] = entry.state;
        const int rc = msg_sendrecv(entry.callback_info.msgQ, msg);
        if (rc != 0)
        {
            PLDM_ERR("PdrManager::invokeStateEffecterCallback: msg_sendrecv failed with rc %d "
                     "on effecter %d/%d, message type = 0x%08x",
                     rc, i_req.effecter_id, entry.composite_id, entry.callback_info.msg_type);

            /*@
             * @errortype        ERRL_SEV_UNRECOVERABLE
             * @moduleid         MOD_PDR_MANAGER
             * @reasoncode       RC_SENDRECV_FAIL
             * @userdata1[0:31]  Return code from msg_sendrecv
             * @userdata1[32:63] Message type for registered callback
             * @userdata2[0:31]  PLDM effecter ID
             * @userdata2[32:63] PLDM composite effecter ID
             * @devdesc          msg_sendrecv() failed
             * @custdesc         Firmware error during system boot
             */
            errlHndl_t err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                           MOD_PDR_MANAGER,
                                           RC_SENDRECV_FAIL,
                                           TWO_UINT32_TO_UINT64(rc, entry.callback_info.msg_type),
                                           TWO_UINT32_TO_UINT64(i_req.effecter_id, entry.composite_id),
                                           ErrlEntry::ADD_SW_CALLOUT);
            errlCommit(err, PLDM_COMP_ID);
        }
        else
        {
            if (msg->data[0] != PLDM_SUCCESS)
            {
                io_pldm_response_code = msg->data[0];
            }
        }

        msg_free(msg);
        msg = nullptr;
    }

    return !messages.empty();
}

#endif // #ifndef __HOSTBOOT_RUNTIME

}
