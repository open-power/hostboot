/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/fapi2/include/target_states.H $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
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
 * @file target_states.H
 * @brief common state for fapi2 targets
 */

#ifndef __FAPI2_TARGET_STATES__
#define __FAPI2_TARGET_STATES__

namespace fapi2
{
///
/// @brief Enumeration of target state values (bitmask values)
///
enum TargetState
{
    TARGET_STATE_PRESENT     = 0x00000001,
    TARGET_STATE_FUNCTIONAL  = 0x00000002,
    TARGET_STATE_NOT_PRESENT = 0x00000004, // Not valid in eCMD/Cronus
    TARGET_STATE_ALL         = 0x00000005,
};
}

#endif
