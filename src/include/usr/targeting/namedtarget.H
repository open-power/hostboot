/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/namedtarget.H $                     */
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
#ifndef __TARGETING_UTIL_NAMEDTARGET_H
#define __TARGETING_UTIL_NAMEDTARGET_H

/**
 *  @file namedtarget.H
 *
 *  @brief hostBoot-specific Targeting Filter utility functions
 */

#include <attributeenums.H>
#include <targeting/common/predicates/predicatebase.H>
#include <targeting/common/iterators/targetiterator.H>
#include <targeting/common/iterators/rangefilter.H>


namespace TARGETING
{


/**
 * @brief   find master core in system
 *
 *  @return master target core, NULL otherwise
 */
const TARGETING::Target *   getMasterCore( );

}   //  end namespace

#endif
