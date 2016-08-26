/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemScrubUtils.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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

/** @file  prdfMemScrubUtils.H
 *  @brief Define the functionality necessary to start initial background scrub
 */

#ifndef __prdfMemScrubUtils_H
#define __prdfMemScrubUtils_H

#include <iipconst.h>
#include <iipServiceDataCollector.h>
#include <iipSystem.h>

namespace PRDF
{

/**
 * @brief Clears the cmd complete attention from the inputted chip
 * @param chip The chip, either mba or mcbist
 * @return SUCCESS if the cmd complete attention is cleared, else Non-SUCCESS
 */
template<TARGETING::TYPE T>
int32_t clearCmdCompleteAttn (ExtensibleChip* chip);

/**
 * @brief Clears the ecc counters from the inputted chip
 * @param chip The chip, either mba or mcbist
 * @return SUCCESS if the ecc counters are cleared, else Non-SUCCESS
 */
template<TARGETING::TYPE T>
int32_t clearEccCounters (ExtensibleChip* chip);

/**
 * @brief Clears the ecc firs from the inputted chip
 * @param chip The chip, either mba or mcbist
 * @return SUCCESS if the ecc firs are cleared, else Non-SUCCESS
 */
template<TARGETING::TYPE T>
int32_t clearEccFirs (ExtensibleChip* chip);

} //end namespace PRDF

#endif // __prdfMemScrubUtils_H
