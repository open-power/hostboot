/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/secureboot/key_clear_if.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
/**
 * @file key_clear_if.H
 *
 * @brief Interfaces to Process Key Clear Requests
 *
 */
#ifndef __KEY_CLEAR_H
#define __KEY_CLEAR_H
// -----------------------------------------------
// Includes
// -----------------------------------------------

#include <errl/errlentry.H>
#include <targeting/common/commontargeting.H>
#include <attributeenums.H>
#include <config.h>

namespace SECUREBOOT
{
    /**
     * @brief Returns Key Clear Request information and if a Physical Presence
     *        check is requested
     *
     * @param[out] o_requestPhysPresence  - If true, then physical presence
     *                                      assertion is requested; otherwise
     *                                      false
     *
     * @param[out] o_keyClearRequests - Struct containing the specifics of
     *                                  the key clear requests
     *
     * @note Any error logs generated will be handled internally
     *
     * @note The associated ATTR_KEY_CLEAR_REQUEST will also be updated by
     *       this function
     *
     * @return void
     */
    void getKeyClearRequest(bool & o_requestPhysPresence,
                            TARGETING::KEY_CLEAR_REQUEST & o_keyClearRequests);

} // namespace SECUREBOOT

#endif // __PHYS_PRESENCE_H
