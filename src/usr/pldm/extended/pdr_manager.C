/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/extended/pdr_manager.C $                         */
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

/* @file pdr_manager.C
 *
 * @brief Implementation file for PdrManager class
 */

#include <pldm/extended/pdr_manager.H>
#include <pldm/extended/hb_pdrs.H>
#include <pldm/requests/pldm_pdr_requests.H>

#include <util/singleton.H>

#include "../extern/pdr.h"

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

}

namespace PLDM
{

PdrManager::PdrManager()
    : pdr_repo(nullptr, pldm_pdr_destroy),
      access_mutex(MUTEX_INITIALIZER),
      access_mutex_owner(&access_mutex, mutex_destroy)
{
    resetPdrs();
}

void PdrManager::resetPdrs()
{
    const auto lock = scoped_mutex_lock(access_mutex);

    pdr_repo.reset(pldm_pdr_init());
}

errlHndl_t PdrManager::addRemotePdrs()
{
    const auto lock = scoped_mutex_lock(access_mutex);

    return getRemotePdrRepository(pdr_repo.get());
}

void PdrManager::addLocalPdrs()
{
    const auto lock = scoped_mutex_lock(access_mutex);

    return addHostbootPdrs(pdr_repo.get(), hostboot_terminus_id);
}

size_t PdrManager::pdrCount() const
{
    const auto lock = scoped_mutex_lock(access_mutex);

    return pldm_pdr_get_record_count(pdr_repo.get());
}

bool PdrManager::findPdr(const pdr_handle_t i_record_handle,
                         std::vector<uint8_t>* o_data,
                         uint32_t& o_next_record_handle) const
{
    const auto lock = scoped_mutex_lock(access_mutex);

    uint8_t* data = nullptr;
    uint32_t data_size = 0;

    const bool found = (pldm_pdr_find_record(pdr_repo.get(),
                                             i_record_handle,
                                             &data,
                                             &data_size,
                                             &o_next_record_handle)
                        != nullptr);

    if (found && o_data)
    {
        o_data->assign(data, data + data_size);
    }

    return found;
}

PdrManager& thePdrManager()
{
    return Singleton<PdrManager>::instance();
}

}
