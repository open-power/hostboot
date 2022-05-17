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
