/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/multicast_group_defs.H $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
 * @file multicast_group_defs.H
 * @brief definitions for P10 fapi2 multicast groups
 */

#ifndef __P10_FAPI2_MULTICAST_GROUP_DEFS__
#define __P10_FAPI2_MULTICAST_GROUP_DEFS__
#include <stdint.h>

/// FAPI namespace
namespace fapi2
{

///
/// @brief Enumeration of P10 multicast groups
///
enum MulticastGroup : uint32_t
{
    MCGROUP_ALL,               ///< All chiplets, good or bad, a.k.a. broadcast
    MCGROUP_GOOD,              ///< All good chiplets
    MCGROUP_GOOD_NO_TP,        ///< All good chiplets except PERV
    MCGROUP_GOOD_MC,           ///< All good MC chiplets
    MCGROUP_GOOD_IOHS,         ///< All good IOHS chiplets
    MCGROUP_GOOD_PAU,          ///< All good PAU chiplets
    MCGROUP_GOOD_PCI,          ///< All good PCI chiplets
    MCGROUP_GOOD_EQ,           ///< All EQ chiplets with at least one good core
    MCGROUP_ALL_EQ,            ///< All EQ chiplets
};

}

#endif
