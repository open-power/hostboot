/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/perv/poz_perv_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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
//------------------------------------------------------------------------------
/// @file  poz_perv_utils.H
/// @brief Utility function support for pervasive HWP code
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Sreekanth Reddy <skadapal@in.ibm.com>
// *HWP FW Maintainer   : Raja Das (rajadas2@in.ibm.com)
//------------------------------------------------------------------------------

#pragma once

#include <fapi2.H>

fapi2::Target<fapi2::TARGET_TYPE_PERV> get_tp_chiplet_target(const fapi2::Target<fapi2::TARGET_TYPE_CHIPS> i_chip);


/// @brief Determine (and init) multicast group for hotplug operations
///
/// Depending on whether or not we want to hotplug we may need to use different
/// sets of targets. This either returns a matching static group or initializes
/// the required dynamic group and returns the group ID.
///
/// @param[in]   i_target                  Chip to operate on
/// @param[out]  o_mcgroup                 Resulting MC group to use for further operations
///
fapi2::ReturnCode get_hotplug_mc_group(
    const fapi2::Target<fapi2::TARGET_TYPE_ANY_POZ_CHIP>& i_target,
    fapi2::MulticastGroup& o_mcgroup);

/**
 * @brief Print the hex equivalent of an integer into a string
 *
 * The destination buffer will be overwritten; no trailing zero byte
 * will be appended. It is recommended to reserve enough space in the
 * destination string to hold the requested number of characters.
 *
 * @param o_str   Location to start writing
 * @param i_value Value to print
 * @param i_width With in hex nibbles
 */
void strhex(char* o_str, uint64_t i_value, int i_width);

/**
 * @brief Apply a bucketed ring
 *
 * @param i_target   Target chiplet to apply ring on
 * @param i_ring_id  Bucketed ring ID, must be one ending in _XX
 * @param i_bucket   Bucket number to apply
 */
fapi2::ReturnCode putRingBucket(const fapi2::Target<fapi2::TARGET_TYPE_ALL_MC>& i_target,
                                const char* i_ring_id,
                                int i_bucket);
