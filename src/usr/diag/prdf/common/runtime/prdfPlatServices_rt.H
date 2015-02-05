/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/runtime/prdfPlatServices_rt.H $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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

#ifndef __prdfPlatServices_rt_H
#define __prdfPlatServices_rt_H

namespace PRDF
{

namespace PlatServices
{

//##############################################################################
//##                        Memory specific functions
//##############################################################################

// TODO: RTC 124850 need to add support for this.
inline bool isPredDynDeallocEnabled() { return false; }

/**
 * @brief Communicates a page gard request to the hypervisor.
 * @param i_systemAddress Any address in the target page.
 */
void sendPageGardRequest( uint64_t i_systemAddress );

/**
 * @brief Communicates an LMB gard request to the hypervisor.
 * @param i_systemAddress Any address in the target LMB.
 * @param i_isFetchUE     True if cause attention is a fetch UE. False if cause
 *                        attention is a scrub UE (only applicable to FSP code).
 */
void sendLmbGardRequest( uint64_t i_systemAddress, bool i_isFetchUE );

/**
 * @brief Communicates to the hypervisor a range of address to remove from the
 *        available memory space.
 * @param i_startAddr First address in the range.
 * @param i_endAddr   Last address in the range.
 */
void sendDynMemDeallocRequest( uint64_t i_startAddr, uint64_t i_endAddr );

} // end namespace PlatServices

} // end namespace PRDF

#endif // __prdfPlatServices_rt_H

