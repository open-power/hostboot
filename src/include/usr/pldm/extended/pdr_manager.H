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

#include <memory>
#include <vector>
#include <sys/sync.h>
#include <errl/errlentry.H>
#include <sys/msg.h>
#include <pldm/requests/pldm_pdr_requests.H>

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
     */
    void addLocalPdrs();

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
    errlHndl_t sendPdrRepositoryChangeEvent(const std::vector<uint32_t>& i_handles) const;

    /* @brief Retrieves a list of all the PDR handles in this repository.
     *
     * @return vector<uint32_t>  List of PDR handles in the repository
     */
    std::vector<uint32_t> getAllPdrHandles() const;

    /* @brief  Return the number of PDRs in the repository.
     *
     * @return size_t Repository's PDR count
     */
    size_t pdrCount() const;

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

    // The BMC TID is 1, HB is 2. It is important that the terminus IDs in the
    // system do not conflict with one another.
    static constexpr terminus_id hostboot_terminus_id = 2;

private:
    std::unique_ptr<pldm_pdr, void(*)(pldm_pdr*)> pdr_repo;
    mutable mutex_t access_mutex;

    // This unique_ptr points to access_mutex, and it will call mutex_destroy on
    // access_mutex when this object is destroyed.
    std::unique_ptr<mutex_t, void(*)(mutex_t*)> access_mutex_owner;

    // Holds a msg_q_t
    std::shared_ptr<void> bmc_repo_changed_event_q;

protected:
    PdrManager();
};

/* @brief  Fetch the global PDR manager object.
 *
 * @return Reference to the global PDR manager.
 */
PdrManager& thePdrManager();

}

#endif
