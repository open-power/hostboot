/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/targplatreasoncodes.H $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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

#ifndef TARGPLATREASONCODES_H
#define TARGPLATREASONCODES_H

/**
 *  @file targeting/targplatreasoncodes.H
 *
 *  @brief Provides reason codes for various platform specific targeting errors
 */

//******************************************************************************
// Includes
//******************************************************************************

#include <targeting/adapters/types.H>

//******************************************************************************
// Constants
//******************************************************************************

namespace TARGETING
{

/**
 *  @brief Platform specific targeting module IDs
 *
 *  @note Must always start @ 0x80, since common module IDs occupy 0x00 -> 0x7F
 *     range
 */
enum PlatTargetingModuleId
{
    TARG_MOD_QUERY_MASTER_PROC_CHIP               = 0x80,
    TARG_MOD_SET_MASTER_NODE                      = 0x81,
    TARG_MOD_ATTRRP_RT                            = 0x82,
};

/**
 *  @brief Platform specific targeting reason codes
 *
 *  @note Must always start @ 0x80, since common reasons codes occupy
 *      0x00 -> 0x7F range
 */
enum PlatTargetingReasonCode
{
    TARG_RC_INVALID_NODE        = TARG_COMP_ID | 0x80,
    TARG_RC_TARGET_NOT_FOUND    = TARG_COMP_ID | 0x81,
};

} // End TARGETING namespace

#endif // TARGPLATREASONCODES_H

