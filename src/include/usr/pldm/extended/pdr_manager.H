/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/extended/pdr_manager.H $                 */
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

/* @file pdr_manager.H
 *
 * Contains definitions for the PDR manager interface.
 */

#ifndef PDR_MANAGER_H__
#define PDR_MANAGER_H__

// Standard library
#include <map>
#include <memory>
#include <vector>

// PLDM
#include <pldm/extended/hb_pdrs.H>
#include <pldm/extended/pldm_fru.H>
#include <pldm/requests/pldm_pdr_requests.H>
#include <pldm/requests/pldm_fru_requests.H>
#include <pldm/responses/pldm_monitor_control_responders.H>

// libpldm
#include <openbmc/pldm/libpldm/pdr.h>
#include <openbmc/pldm/libpldm/platform.h>
#include <openbmc/pldm/libpldm/state_set.h>

// Misc
#include <sys/sync.h>
#include <errl/errlentry.H>
#include <sys/msg.h>

// Forward declarations

struct pldm_set_state_effecter_states_req;
struct pldm_get_state_sensor_readings_req;

class PldmPdrTestSuite;

namespace PLDM
{

/* @brief  This class manages a global PDR repository for Hostboot (meant to be
 *         used through the Singleton class).
 *
 * @note  The member functions of this class are thread-safe, and lock/unlock a
 *        per-instance mutex for the internal PDR repository upon entry/exit.
 */
class PdrManager
{
public:
    PdrManager();

    // Non-copyable, non-assignable
    PdrManager(const PdrManager&) = delete;
    PdrManager& operator=(const PdrManager&) = delete;

    /* @brief  Fetches remote PDRs and adds them to the repository.
     *
     * @return Error if any, otherwise nullptr.
     * @note   Locks the PDR repository.
     */
    errlHndl_t addRemotePdrs();

    /* @brief  Remove all PDRs from the repository. Does NOT remove the sensor/effecter handlers
     *         previously registered with addStateEffecterPdr/addStateSensorPdr.
     * @note   Locks the PDR repository.
     */
    void resetPdrs();

    /* @brief  Find a PDR in the repository.
     *
     * @param[in/out] io_record_handle  Record handle to search for. Set to the
     *                                  real record handle of the record, if
     *                                  found.
     * @param[out] o_data  Container to hold PDR data, if found. Prior contents
     *                     of this container are erased if the PDR is found,
     *                     unaltered otherwise. If this parameter is nullptr,
     *                     the caller will not receive the PDR data but
     *                     o_next_record_handle will be set appropriately.
     * @param[out] o_next_record_handle  Next record handle if PDR is found,
     *                                   unaltered otherwise.
     * @return  True if PDR is found, false otherwise.
     * @note    Locks the PDR repository.
     */
    bool findPdr(pdr_handle_t& io_record_handle,
                 std::vector<uint8_t>* o_data,
                 uint32_t& o_next_record_handle) const;

    /* @brief Sets the Hostboot Terminus Locator PDR's state to not valid
     *        and syncs that PDR to BMC.
     *
     * @return nullptr on success; non-nullptr on error
     * @note   Locks the PDR repository.
     */
    errlHndl_t invalidateHBTerminusLocatorPdr();

    /* @brief Send an event to the BMC indicating that the given set of PDRs
     *        has been added to the repository.
     *
     * @param[in] i_handles  PDR handles that have been added.
     * @return errlHndl_t    Error if any, otherwise nullptr.
     * @note                 Locks the PDR repository.
     */
    errlHndl_t sendPdrRepositoryChangeEvent(const std::vector<pdr_handle_t>& i_handles) const;

    /* @brief Retrieves a list of all the PDR handles in this repository.
     *
     * @return vector<pdr_handle_t>  List of PDR handles in the repository
     * @note   Locks the PDR repository.
     */
    std::vector<pdr_handle_t> getAllPdrHandles() const;

    /* @brief  Return the number of PDRs in the repository.
     *
     * @return size_t Repository's PDR count
     * @note   Locks the PDR repository.
     */
    size_t pdrCount() const;

#ifndef __HOSTBOOT_RUNTIME
    /* @brief  Send notification that the BMC's PDR repository has changed. This
     *         will cause one task blocking on awaitBmcPdrRepoChanged (on this
     *         object) to wake up.
     *
     * @note After this function is called once, an error will be returned if it
     *       is called again (on the same object).
     *
     * @return errlHndl_t  Error if any, otherwise nullptr.
     */
    errlHndl_t notifyBmcPdrRepoChanged();

    // This value can be given to awaitBmcPdrRepoChanged to disable the watchdog
    // timer.
    static constexpr size_t TIMEOUT_NONE = 0;

    /* @brief  Wait for notification that the BMC's PDR repository has changed
     *         (i.e. some task called notifyBmcPdrRepoChanged on this object).
     *
     * @param[in] i_timeout_ms  Timeout in milliseconds. If this timeout elapses,
     *                          then an error log is created and returned. A value
     *                          of TIMEOUT_NONE means wait forever.
     * @return errlHndl_t       Error if any, otherwise nullptr.
     *
     * @note After notifyBmcPdrRepoChanged() has been called once, this function
     *       will return immediately, even on subsequent invocations.
     */
    errlHndl_t awaitBmcPdrRepoChanged(size_t i_timeout_ms = TIMEOUT_NONE);
#endif

    /* @brief  Iterate the PDR repository and invoke a callback for each PDR of
     *         the given type.
     *
     * @param[in]  i_pdr_type  The type of PDR to iterate.
     * @param[in]  i_func      The callback. Can be any object with an operator() that is
     *                         compatible with the signature:
     *                           bool i_func(uint8_t* pdr_data, uint32_t pdr_data_size)
     *                         The functor will be called with the data and length of each
     *                         PDR of the requested type in the PDR repository.
     *                         If the functor returns a truthy value, the iteration will
     *                         halt.
     * @note                   This function acquires a lock on the PDR repository. The functor
     *                         should not call other PdrManager functions that also lock the
     *                         repository, because it will cause a deadlock.
     */
    template<typename F>
    void foreachPdrOfType(pldm_pdr_types i_pdr_type, F&& i_func) const;

    /* @brief  Find the ID of a state effecter with the given characteristics.
     *
     * @param[in] i_entity        The entity that the effecter is attached to.
     * @param[in] i_state_set_id  The state set ID of the effecter.
     * @return    effecter_id_t   The ID of the effecter if any, otherwise 0.
     * @note                      If there are multiple effecters on the same entity with the
     *                            same state set ID, any one of them may be returned.
     */
    effecter_id_t findStateEffecterId(pldm_entity i_entity, pldm_state_set_ids i_state_set_id);

    /* @brief  Collect the FRU Record Set IDs from all FRU Record Set PDRs for
     *         the given entity type.
     *
     * @param[in] i_entity_type  Entity type to filter by
     * @param[in] i_terminus_id  Terminus ID for the terminus that originated the FRU record set PDR
     * @return vector            List of FRU Record Set IDs for the given entity type
     * @note                     Locks the PDR repository.
     */
    std::vector<fru_record_set_id> findFruRecordSetIdsByType(entity_type i_entity_type, terminus_id_t i_terminus_id = TERMINUS_ID_ALL) const;

    /* @brief  Look up the entity ID corresponding with the given FRU Record Set ID
     *         in the PDR repository.
     *
     * @param[in] i_rsid     The FRU RSID to look up
     * @param[out] o_entity  The entity ID if found, otherwise unset
     * @return bool          Whether the FRU RSID was found in the PDR repository
     * @note                 Locks the PDR repository.
     */
    bool findEntityByFruRecordSetId(fru_record_set_id i_rsid,
                                    pldm_entity& o_entity) const;

    /* A "state query" is either a state sensor get-request or a state effecter
     * set-request. */
    enum state_query_handler_id_t
    {
        STATE_QUERY_HANDLER_FUNCTIONAL_STATE_SENSOR = 1,
        STATE_QUERY_HANDLER_OCC_STATE_QUERY = 2,
        STATE_QUERY_HANDLER_GRACEFUL_SHUTDOWN = 3,
        STATE_QUERY_HANDLER_INVALID = 0xFF
    };

    /* Enumeration for handleStateQueryRequest. A state query is either an
     * effecter set-request or a sensor get-request. */
    enum state_query_type_t : uint8_t
    {
        STATE_QUERY_SENSOR = 1,
        STATE_QUERY_EFFECTER = 2
    };

    /* @brief Records stored in the system's PLDM_STATE_QUERY_RECORDS attribute.
     */
    struct pldm_state_query_record_t
    {
        uint32_t target_huid = 0;
        uint16_t query_id = 0;
        uint16_t state_set_id = 0;
        uint16_t function_id = 0;
        state_query_type_t query_type = { };
    } PACKED;

    /* @brief  Add a state effecter PDR to the PDR repository.
     *
     * @param[in] i_target           target that this effecter pertains to. Will be passed to the callback.
     * @param[in] i_entity           Entity information for the FRU that this effecter pertains to.
     * @param[in] i_state_set_id     State set ID that this effecter uses (e.g. PLDM_STATE_SET_HEALTH_STATE)
     * @param[in] i_possible_states  Bitset of valid states in the state set for this effecter. Only 8 states
     *                               are currently supported.
     * @param[in] i_qhandler         The enumeration representing the SetStateEffecterStates callback for
     *                               this effecter. The given function will be called to handle the
     *                               SetStateEffecterStates command for the effecter ID of the new effecter
     *                               PDR. If this is NONE, then the PDR will be created, but the
     *                               SetStateEffecterStates PLDM command for this effecter will respond with
     *                               an error.
     * @note                         Locks the PDR repository.
     */
    void addStateEffecterPdr(TARGETING::Target* i_target,
                             const pldm_entity& i_entity,
                             uint16_t i_state_set_id,
                             uint8_t i_possible_states,
                             state_query_handler_id_t i_qhandler);

    /* @brief  Add a state sensor PDR to the PDR repository.
     *
     * @param[in] i_target           Target that this sensor pertains to. This will be passed to the callback.
     * @param[in] i_entity           Entity information for the FRU that this sensor pertains to.
     * @param[in] i_state_set_id     State set ID that this sensor uses (e.g. PLDM_STATE_SET_HEALTH_STATE)
     * @param[in] i_possible_states  Bitset of valid states in the state set for this sensor. Only 8 states
     *                               are currently supported.
     * @param[in] i_qhandler         The enumeration representing the GetStateSensorReadings callback for
     *                               this effecter. The given function will be called to handle the
     *                               SetStateEffecterStates command for the effecter ID of the new effecter
     *                               PDR. If this is NONE, then the PDR will be created, but the
     *                               GetStateSensorReadings PLDM command for this effecter will respond with
     *                               an error.
     * @note                         Locks the PDR repository.
     */
    void addStateSensorPdr(TARGETING::Target* i_target,
                           const pldm_entity& i_entity,
                           uint16_t i_state_set_id,
                           uint8_t i_possible_states,
                           state_query_handler_id_t i_qhandler);

    /* @brief Get the set of state query records (possibly related to a
     *        particular target).
     *
     * @param[in] i_target  If non-NULL, only return state query records related
     *                      to this target. If NULL, return all records.
     * @return vector       List of PLDM state query records.
     * @note                Locks the PDR repository.
     */
    std::vector<pldm_state_query_record_t> getHostStateQueryRecords(const TARGETING::Target* i_target = nullptr);

    /* @brief Look up a state query ID by state set ID in the list of registered state query records.
     *
     * @param[in] i_state_query_type  The type of state query record to look for.
     * @param[in] i_state_set_id      State set ID of the state query handler to look up.
     * @param[in] i_target            Target to restrict the search for (NULL to search all targets).
     * @return                        The sensor or effecter ID of the registered handler if any, 0 if none.
     * @note                          If there are multiple query handlers registered for the same state set
     *                                on the relevant target(s), an arbitrary one will be returned.
     * @note                          Locks the PDR repository.
     */
    state_query_id_t getHostStateQueryIdForStateSet(state_query_type_t i_state_query_type,
                                                    uint16_t i_state_set_id,
                                                    const TARGETING::Target* i_target = nullptr);

    /* @brief  Handle a SetStateEffecterStates command and send a response.
     *
     * This function invokes the appropriate callback registered with addStateEffecterPdr if there is one,
     * or responds with an error if there is no handler.
     *
     * @param[in] i_msgQ         Handle to the PLDM message queue.
     * @param[in] i_msg          Pointer to the PLDM message.
     * @param[in] i_payload_len  Length of the PLDM message.
     * @param[in] i_req          Decoded PLDM request.
     * @return errlHndl_t        Error if any, otherwise nullptr.
     * @note                     Locks the PDR repository.
     */
    errlHndl_t setStateEffecterStates(msg_q_t i_msgQ,
                                      const pldm_msg* i_msg,
                                      size_t i_payload_len,
                                      const pldm_set_state_effecter_states_req* i_req);

    /* @brief  Handle a GetStateSensorReadings command and send a response.
     *
     * This function invokes the appropriate callback registered with addStateSensorPdr if there is one,
     * or responds with an error if there is no handler.
     *
     * @param[in] i_msgQ         Handle to the PLDM message queue.
     * @param[in] i_msg          Pointer to the PLDM message.
     * @param[in] i_payload_len  Length of the PLDM message.
     * @param[in] i_req          Decoded PLDM request.
     * @return errlHndl_t        Error if any, otherwise nullptr.
     * @note                     Locks the PDR repository.
     */
    errlHndl_t getStateSensorReadings(msg_q_t i_msgQ,
                                      const pldm_msg* i_msg,
                                      size_t i_payload_len,
                                      const pldm_get_state_sensor_readings_req* i_req);

    /* @brief  Add a FRU Record Set PDR to the repository.
     *
     * @param[in] i_rsid    Record Set ID for the new PDR.
     * @param[in] i_entity  Entity information for the PDR.
     * @note                Locks the PDR repository.
     */
    void addFruRecordSetPdr(fru_record_set_id_t i_rsid,
                            const pldm_entity& i_entity);

    /* @brief  Add the entity association PDRs from the given tree to the repository.
     *
     * @param[in] i_tree       The entity association tree to add.
     * @param[in] i_is_remote  Whether the PDRs should have the "remote" flag set.
     * @note                   Locks the PDR repository.
     */
    void addEntityAssociationPdrs(const pldm_entity_association_tree& i_tree, bool i_is_remote);

    /* @brief  Send information about all the functional states of the FRUs in this repository to the BMC.
     *         FRUs that have functional state are the FRUs that have state sensor PDRs for the
     *         PLDM_STATE_SET_HEALTH_STATE state set.
     * @note   Locks the PDR repository.
     */
    void sendAllFruFunctionalStates() const;

    /* @brief Hostboot's PLDM Terminus ID.
     * @return terminus_id_t Hostboot's current terminus ID.
     */
    static terminus_id_t hostbootTerminusId()
    {
        // The BMC TID is 1, HB is 2. It is important that the terminus IDs in
        // the system do not conflict with one another. The implementation of
        // this function will change if/when we implement the SetTID PLDM
        // command.
        return 2;
    }

    /*
     * @brief Adds a Terminus Locator PDR to the PDR repository
     * @note  Locks the PDR repository.
     */
    void addTerminusLocatorPDR();

    // Can be given as a field in the pldm_entity parameter to
    // findStateEffecterId to act as a wildcard in the search.
    static const uint16_t ENTITY_ID_DONTCARE = 0xFFFF;

    /** @brief Find the ID of an effecter that operates with the given state set
     * ID. If there are multiple effecters that operate with the given ID, any
     * of them may be returned.
     *
     * @param[in]  i_state_set_id  The state set ID to search for.
     * @param[in]  i_entity        The entity to search for. If any member of this
     *                             ID is ENTITY_ID_DONTCARE then that member will
     *                             be ignored for purposes of comparison when searching.
     *
     * @return effecter_id_t       The effecter if found, otherwise 0.
     * @note                       Locks the PDR repository.
     */
    effecter_id_t findStateEffecterId(pldm_state_set_ids i_state_set_id,
                                      pldm_entity i_entity);

#ifndef __HOSTBOOT_RUNTIME
    /** @brief  Register a message queue to be messaged when a particular Hostboot PLDM
     *          effecter is set by another terminus.
     *          See DSP0248 v1.2.0 for definitions.
     *
     * @param[in] i_effecter_id   The ID of the effecter to monitor.
     * @param[in] i_composite_id  The offset of the composite effecter to monitor.
     * @param[in] i_msgQ          The message queue to send the message to.
     * @param[in] i_msg_type      The message type to send to the message queue.
     *
     * @note The message queue listener must respond with a message after it is
     *       done operating.
     * @note The message sent to the listener will have two pieces of data:
     *       data[0] will be the PLDM composite effecter ID (0..7 inclusive),
     *       and data[1] will be the new effecter state. In the response
     *       message, data[0] should be the 8-bit PLDM status code that will be
     *       used to respond to the PLDM state effecter set-request.
     * @note Dynamic handlers for the state effecter will be invoked before any static
     *       handler.
     * @note If there is a static handler for the effecter set-request, the PLDM
     *       response code from the dynamic handler(s) will be ignored.
     * @note The PDR repository will not be locked when a message is sent on the
     *       given queue when handling a PLDM state effecter set-request.
     * @note This function locks the PDR repository.
     * @note Waiters on the message queue should use the msg_wait_timeout API to ensure
     *       that they are able to progress even if a message send operation fails.
     */
    void registerStateEffecterCallbackMsgQ(effecter_id_t i_effecter_id,
                                           uint8_t i_composite_id,
                                           msg_q_t i_msgQ,
                                           uint32_t i_msg_type);

    /** @brief  Unregister a registered effecter callback message queue.
     *
     * @param[in] i_effecter_id   See registerStateEffecterCallbackMsgQ.
     * @param[in] i_composite_id  See registerStateEffecterCallbackMsgQ.
     * @param[in] i_msgQ          See registerStateEffecterCallbackMsgQ.
     *
     * @note If the queue is not registered under the given effecter info, this
     *       function does nothing.
     * @note This function locks the PDR repository.
     * @note Users of this function must be careful about how they accept callback
     *       messages, and must be sure to always respond to any message the PDR
     *       manager sends on the queue, otherwise the manager will hang. To avoid
     *       deadlock, users should attempt to receive a message on the queue for a
     *       short period of time after unregistering it to ensure that a message
     *       wasn't sent between the time they stopped waiting and the time that they
     *       unregistered the queue.
     */
    void unregisterStateEffecterCallbackMsgQ(effecter_id_t i_effecter_id,
                                             uint8_t i_composite_id,
                                             msg_q_t i_msgQ);
#endif

private:
    std::unique_ptr<pldm_pdr, void(*)(pldm_pdr*)> iv_pdr_repo;
    mutable mutex_t iv_access_mutex;

    // This unique_ptr points to iv_access_mutex, and it will call mutex_destroy on
    // iv_access_mutex when this object is destroyed.
    std::unique_ptr<mutex_t, void(*)(mutex_t*)> iv_access_mutex_owner;

#ifndef __HOSTBOOT_RUNTIME
    /** @brief  Invoke dynamic callback listeners for a PLDM state effecter.
     *
     * @param[in]     i_req                  The PLDM request
     * @param[in/out] io_pldm_response_code  The response code to send, if there were no static handlers
     *                                       for the PLDM message. For multiple handlers, this will be
     *                                       the "worst" status.
     * @return        bool                   Whether any handlers were invoked.
     * @note                                 This function locks the PDR repository while accessing
     *                                       member variables, then unlocks it when sending messages
     *                                       to the registered message queues.
     */
    bool invokeStateEffecterCallback(const pldm_set_state_effecter_states_req& i_req,
                                     uint8_t& io_pldm_response_code);

    // Holds a msg_q_t
    std::shared_ptr<void> iv_bmc_repo_changed_event_q;

    struct effecter_registry_value_t
    {
        effecter_registry_value_t(msg_q_t i_msgQ, uint32_t i_msg_type)
            : msgQ(i_msgQ), msg_type(i_msg_type) { }

        msg_q_t msgQ = nullptr;
        uint32_t msg_type = 0;
    };

    struct effecter_registry_key_t
    {
        effecter_registry_key_t(uint32_t i_fullword)
        {
            fullword = i_fullword;
        }

        effecter_registry_key_t(effecter_id_t i_eff_id, uint8_t i_comp_id)
        {
            fullword = 0;
            effecter_id = i_eff_id;
            composite_id = i_comp_id;
        }

        union
        {
            struct
            {
                effecter_id_t effecter_id;
                uint8_t composite_id;
            } PACKED;

            uint32_t fullword;
        };
    };

    std::map<uint32_t, std::vector<effecter_registry_value_t>> iv_effecter_msgq_registry;
#endif

    /* This monotonically increasing value is used to assign sensor/effecter IDs, and the IDs are stored in
     * attributes, along with a state_query_handler_id_t value, to record how to handle PLDM sensor/effecter
     * queries. */
    state_query_id_t iv_next_state_query_id = 1;

    /* @brief  Handle a PLDM state sensor or effecter command.
     *
     * @param[in] i_querytype    Whether this is a sensor-read or effecter-write command.
     * @param[in] i_query_id     Sensor/effecter ID.
     * @param[in] i_msgQ         Handle to the PLDM message queue.
     * @param[in] i_msg          PLDM message.
     * @param[in] i_payload_len  PLDM message length.
     * @param[in] i_req          Decoded PLDM message. Must point to a pldm_get_state_sensor_readings_req
     *                           if i_querytype is STATE_QUERY_SENSOR, or pldm_set_state_effecter_states_req
     *                           if i_querytype is STATE_QUERY_EFFECTER.
     * @return errlHndl_t        Error if any, otherwise nullptr.
     */
    errlHndl_t handleStateQueryRequest(state_query_type_t i_querytype,
                                       state_query_id_t i_query_id,
                                       msg_q_t i_msgQ,
                                       const pldm_msg* i_msg,
                                       size_t i_payload_len,
                                       const void* i_req);

    // For testcases
    friend class ::PldmPdrTestSuite;
};

/* @brief  Fetch the global PDR manager object.
 *
 * @return Reference to the global PDR manager.
 */
PdrManager& thePdrManager();

template<typename F>
void PdrManager::foreachPdrOfType(const pldm_pdr_types i_pdr_type, F&& i_func) const
{
    const auto lock = scoped_mutex_lock(iv_access_mutex);

    const pldm_pdr_record* curr_record = nullptr;

    do
    {
        uint8_t* pdr_data = nullptr;
        uint32_t pdr_data_size = 0;

        curr_record = pldm_pdr_find_record_by_type(iv_pdr_repo.get(),
                                                   i_pdr_type,
                                                   curr_record,
                                                   &pdr_data,
                                                   &pdr_data_size);

        if (pdr_data)
        {
            if (i_func(pdr_data, pdr_data_size))
            {
                break;
            }
        }
    } while (curr_record);
}

}

#endif
