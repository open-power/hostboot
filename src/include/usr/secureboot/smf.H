/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/secureboot/smf.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
#ifndef __SMF_H
#define __SMF_H

#include <errl/errlentry.H>
#include <stdint.h>
#include <limits.h>

// The maximum size of the unsecure HOMER region in reserved memory
#define MAX_UNSECURE_HOMER_SIZE (1 * PAGESIZE)

namespace SMF_TRACE
{
    extern trace_desc_t* g_trac_smf;
}

namespace SECUREBOOT
{
namespace SMF
{

/**
 * @brief A function that distributes the requested amount of secure
 *        memory between the functional procs with memory on the system.
 *        The memory is distributed in power-of-two chunks of 256MB
 *        until either all memory is distributed or there are no procs
 *        remaining with memory available. If the requested amount is not
 *        a power-of-two factor of 256MB, the amount of memory will be rounded
 *        up accordingly. The function returns predictive or informational
 *        errors in the following cases: there is no available memory behind the
 *        procs on the system (predictive error), the exact amount of secure mem
 *        allocated did not match the requested amount (informational error). If
 *        0 is passed in to the function, no attempt at distribution occurs and
 *        the SMF mode is turned off.
 *
 * @param[in] i_requestedSmfMemAmtInBytes the amount of secure memory to be
 *            distributed (in bytes) among the procs on the system
 *
 * @return   nullptr: the memory was successfully distributed as requested
 *           non-nullptr: a distribution error occurred (the error type will
 *           never be unrecoverable)
 */
errlHndl_t distributeSmfMem(const uint64_t i_requestedSmfMemAmtInBytes);

/**
 * @brief Function to distribute the requested amount of SMF memory between
 *        passed in procs with available memory. If 0 is passed in to the
 *        function, no attempt at distribution occurs and the SMF mode is turned
 *        off. Amount that are not power-of-two factors of 256MB are rounded up
 *        accordingly.
 *
 * @param[in] i_requestedSmfMemAmtInBytes the requested amount of secure memory
 *            to distribute between the procs (in bytes)
 *
 * @param[in] i_procToMemVec the vector of available procs on the system and
 *            the amount of memory attached to each
  *
 * @return nullptr: distribution was successful
 *         non-nullptr: an error occurred during distribution (the error type
 *         will never be unrecoverable)
 */
errlHndl_t distributeSmfMem(const uint64_t i_requestedSmfMemAmtInBytes,
                            std::vector<struct ProcToMemAssoc>& i_procToMemVec);

/**
 * @brief Helper function to return the total amount of memory available behind
 *        the given proc
 *
 * @param[in] i_proc the proc target to calculate the total memory for
 *
 * @pre       the target must not be nullptr or the funtion will assert
 *
 * @return the total amount of memory, in bytes, available behind the input proc
 */
uint64_t getTotalProcMemSize(const TARGETING::Target* const i_proc);

} // namespace SMF
} // namespace SECUREBOOT

#endif
