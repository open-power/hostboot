/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/extended/sbe_dump.H $                    */
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

/* @brief Contains the interfaces for triggering an SBE dump on the BMC via
 * PLDM.
 */

#ifndef PLDM_SBE_DUMP_H
#define PLDM_SBE_DUMP_H

#include <errl/errlmanager.H>

namespace TARGETING
{
class Target;
}

namespace PLDM
{

/** @brief Requests that the BMC perform an SBE dump on the SBE in the given
 *         processor and wait for it to complete or fail.
 *
 * @param[in] i_proc      The processor that contains the SBE to dump.
 * @param[in] i_errorlog  The error log that is responsible for the dump.
 * @return    errlHndl_t  Error if any, nullptr otherwise.
 * @note                  This function will wait a bounded amount of time
 *                        for the SBE dump to complete. If it does not complete
 *                        within the alotted time, an error will be returned.
 */
errlHndl_t dumpSbe(TARGETING::Target* i_proc, errlHndl_t i_errorlog);

/* @brief Structure containing a snapshot of the CURRENT_SBE_HRESET_STATUS
 *        attributes for a set of processors.
 */
struct sbe_hreset_states
{
    struct huid_state
    {
        TARGETING::ATTR_HUID_type huid = 0;
        TARGETING::ATTR_CURRENT_SBE_HRESET_STATUS_type state = 0;
    };

    std::vector<huid_state> states;
};

/* @brief Notify the BMC that an HRESET has started on the given processor.
 *
 * @param[in] i_proc  The processor being HRESET.
 *
 * @return            A snapshot of the old HRESET states, to be given to notifyEndSbeHreset.
 */
sbe_hreset_states notifyBeginSbeHreset(TARGETING::Target* i_proc);

/* @brief Notify the BMC that an HRESET is complete.
 *
 * @param[in] i_proc        The target processor
 * @param[in] i_state       The result of the HRESET operation.
 * @param[in] i_old_states  Return value of the corresponding notifyBeginSbeHreset call.
 */
void notifyEndSbeHreset(TARGETING::Target* i_proc,
                        TARGETING::ATTR_CURRENT_SBE_HRESET_STATUS_type i_state,
                        const sbe_hreset_states& i_old_states);

/* @brief Notify the BMC about whether the host is ready to handle HRESET requests.
 *
 * @param[in] i_ready  True if the host is ready for HRESET requests, else false.
 */
void notifySbeHresetsReady(bool i_ready);

}

#endif
