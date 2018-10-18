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

namespace SMF_TRACE
{
    extern trace_desc_t* g_trac_smf;
}

namespace SECUREBOOT
{
namespace SMF
{

/**
 * @brief A function that destributes the requested amount of secure
 *        memory between the functional procs with memory on the system.
 *        The memory is distributed in power-of-two chunks of 256MB
 *        until either all memory is distributed or there are no procs
 *        remaining with memory available. The function returns predictive
 *        or informational errors in the following cases: there is no
 *        available memory behind the procs on the system (predictive error),
 *        the exact amount of secure mem allocated did not match the requested
 *        amount (informational error). If 0 is passed in to the function, no
 *        attempt at distribution occurs and the SMF mode is turned off.
 *
 * @param[in] i_requestedSmfMemAmtInBytes the amount of secure memory to be
 *            distributed (in bytes)
 *            among the procs on the system
 *
 * @return   nullptr: the memory was successfully distributed as requested
 *           non-nullptr: a distribution error occurred (this error is never
 *           unrecoverable)
 */
errlHndl_t distributeSmfMem(uint64_t i_requestedSmfMemAmtInBytes);

} // namespace SMF
} // namespace SECUREBOOT

#endif
