/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/extended/pdr_manager.H $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
#include <memory>
#include <vector>

// PLDM
#include <pldm/extended/hb_pdrs.H>
#include <pldm/requests/pldm_pdr_requests.H>
#include <pldm/requests/pldm_fru_requests.H>

// libpldm
#include <openbmc/pldm/libpldm/pdr.h>

// Misc
#include <sys/sync.h>
#include <errl/errlentry.H>
#include <sys/msg.h>

class PldmPdrTestSuite;

namespace PLDM
{

/* @brief  This class manages a global PDR repository for Hostboot (meant to be
 *         used through the Singleton class).
 *
 * @note  The member functions of this class are thread-safe, and lock/unlock a
 *        per-instance mutex upon entry/exit.
 */
class PdrManager
{
public:
    // Non-copyable, non-assignable
    PdrManager(const PdrManager&) = delete;
    PdrManager& operator=(const PdrManager&) = delete;

    /* @brief  Fetches remote PDRs and adds them to the repository.
     *
     * @return Error if any, otherwise nullptr.
     */
    errlHndl_t addRemotePdrs();

    /* @brief  Adds Hostboot PDRs to the repository.
     *
     * @return Error if any, otherwise nullptr.
     */
    errlHndl_t addLocalPdrs();

    /* @brief  Remove all PDRs from the repository.
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
     */
    bool findPdr(pdr_handle_t& io_record_handle,
                 std::vector<uint8_t>* o_data,
                 uint32_t& o_next_record_handle) const;

    /* @brief Send an event to the BMC indicating that the given set of PDRs
     *        has been added to the repository.
     *
     * @param[in] i_handles  PDR handles that have been added.
     * @return errlHndl_t    Error if any, otherwise nullptr.
     */
    errlHndl_t sendPdrRepositoryChangeEvent(const std::vector<pdr_handle_t>& i_handles) const;

    /* @brief Retrieves a list of all the PDR handles in this repository.
     *
     * @return vector<pdr_handle_t>  List of PDR handles in the repository
     */
    std::vector<pdr_handle_t> getAllPdrHandles() const;

    /* @brief  Return the number of PDRs in the repository.
     *
     * @return size_t Repository's PDR count
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

    /* @brief  Collect the FRU Record Set IDs from all FRU Record Set PDRs for
     *         the given entity type.
     *
     * @param[in] i_entity_type  Entity type to filter by
     * @return vector            List of FRU Record Set IDs for the given entity type
     */
    std::vector<fru_record_set_id> findFruRecordSetIdsByType(entity_type i_entity_type) const;

    /* @brief  Look up the entity ID corresponding with the given FRU Record Set ID
     *         in the PDR repository.
     *
     * @param[in] i_rsid     The FRU RSID to look up
     * @param[out] o_entity  The entity ID if found, otherwise unset
     * @return bool          Whether the FRU RSID was found in the PDR repository
     */
    bool findEntityByFruRecordSetId(fru_record_set_id i_rsid,
                                    pldm_entity& o_entity) const;

    /* @brief  Search all the entity association PDRs in the repository for an
     *         entity with the given entity type and instance number, and return
     *         container ID of the matching entity.
     *
     * @param[in] io_entity.entity_type             The entity type to search for
     * @param[in] io_entity.entity_instance_number  The entity instance number to search for
     * @param[out] io_entity.entity_container_id    The container ID of the found entity
     * @return bool Whether the entity was found.
     * @note io_entity.entity_container_id is left unset if the entity is not found.
     */
    // @TODO RTC 256140: Remove this function when the BMC normalizes all PDRs
    bool findEntityByTypeAndId(pldm_entity& io_entity) const;

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

private:
    std::unique_ptr<pldm_pdr, void(*)(pldm_pdr*)> iv_pdr_repo;
    mutable mutex_t iv_access_mutex;

    // This unique_ptr points to access_mutex, and it will call mutex_destroy on
    // access_mutex when this object is destroyed.
    std::unique_ptr<mutex_t, void(*)(mutex_t*)> iv_access_mutex_owner;

#ifndef __HOSTBOOT_RUNTIME
    // Holds a msg_q_t
    std::shared_ptr<void> iv_bmc_repo_changed_event_q;
#endif

protected:
    PdrManager();

    // For testcases
    friend class ::PldmPdrTestSuite;
};

/* @brief  Fetch the global PDR manager object.
 *
 * @return Reference to the global PDR manager.
 */
PdrManager& thePdrManager();

}

#endif