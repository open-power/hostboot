/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/odyutil.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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

/* @file
   This file includes various targeting utilities for Odyssey OCMBs
*/

#include <targeting/common/target.H>
#include <attributeenums.H>
#include <chipids.H>

namespace TARGETING::UTIL
{

/**
 * @brief Checks whether the input target is a chip of type Odyssey.
 *
 * @param[in] i_target The input target to check
 * @return bool Whether the input target is a chip of type Odyssey
 */
inline bool isOdysseyChip(const Target* i_target)
{
    return (i_target->getAttr<ATTR_TYPE>() == TYPE_OCMB_CHIP &&
            i_target->getAttr<ATTR_CHIP_ID>() == POWER_CHIPID::ODYSSEY_16);
}

} // namespace TARGETING::UTIL
