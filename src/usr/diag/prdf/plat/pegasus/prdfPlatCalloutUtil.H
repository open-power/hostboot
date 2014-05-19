/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfPlatCalloutUtil.H $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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

#ifndef __prdfPlatCalloutUtil_H
#define __prdfPlatCalloutUtil_H

/** @file prdfPlatCalloutUtil.H */

// Framework includes
#include <prdfEnums.H>

namespace PRDF
{

class MemoryMru;

namespace CalloutUtil
{

/**
 * @brief Add all parts of a MemoryMru to the callout list of an error log.
 *        Also, adds the MemoryMru info to the capture data.
 *
 * This is only intended to be used by non-attention analysis code like Restore
 * DRAM Repairs or MNFG IPL CE analysis. In these cases, there is no SDC to
 * collect the callout info or capture data.
 *
 * @param io_errl         The target error log.
 * @param i_memmru        The target MemoryMru.
 * @param i_priority      The callout priority
 * @param i_deconfigState The deconfiguration state.
 * @param i_gardType      The GARD error type.
 */
void calloutMemoryMru( errlHndl_t io_errl, const MemoryMru & i_memmru,
                       const HWAS::callOutPriority i_priority,
                       const HWAS::DeconfigEnum    i_deconfigState,
                       const HWAS::GARD_ErrorType  i_gardType );

} // end namespace CalloutUtil

} // end namespace PRDF

#endif // __prdfPlatCalloutUtil_H

