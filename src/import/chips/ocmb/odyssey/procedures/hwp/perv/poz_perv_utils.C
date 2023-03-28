/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/perv/poz_perv_utils.C $ */
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
/// @file  poz_perv_utils.C
/// @brief Utility function support for pervasive HWP code
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Sreekanth Reddy <skadapal@in.ibm.com>
// *HWP FW Maintainer   : Raja Das (rajadas2@in.ibm.com)
//------------------------------------------------------------------------------

#include <poz_perv_utils.H>
#include <poz_perv_mod_misc.H>
#include <poz_ring_ids.H>
#include <target_filters.H>
#include <assert.h>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------
using namespace fapi2;

Target<TARGET_TYPE_PERV> get_tp_chiplet_target(const Target<TARGET_TYPE_CHIPS> i_chip)
{
    auto l_children = i_chip.getChildren<TARGET_TYPE_PERV>(TARGET_FILTER_TP, TARGET_STATE_PRESENT);
    // The TP chiplet should always be present so just use
    // assert() instead of FAPI_ASSERT() as a sanity check.
    assert(!l_children.empty());
    return l_children[0];
}

ReturnCode get_hotplug_mc_group(
    const Target<TARGET_TYPE_ANY_POZ_CHIP>& i_target,
    MulticastGroup& o_mcgroup)
{
    Target<TARGET_TYPE_SYSTEM> l_system_target;
    buffer<uint8_t> l_attr_hotplug;
    buffer<uint64_t> l_attr_sim_chiplet_mask;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HOTPLUG, l_system_target, l_attr_hotplug),
             "Error from FAPI_ATTR_GET (ATTR_HOTPLUG)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SIM_CHIPLET_MASK, i_target, l_attr_sim_chiplet_mask),
             "Error from FAPI_ATTR_GET (ATTR_SIM_CHIPLET_MASK)");

    if (l_attr_hotplug)
    {
        o_mcgroup = MCGROUP_GOOD_NO_TP;
    }
    else
    {
        FAPI_INF("Configure all PRESENT chiplets except TP as part of multicast group 5");
        FAPI_TRY(mod_multicast_setup(i_target, MCGROUP_5, l_attr_sim_chiplet_mask & 0x3FFFFFFFFFFFFFFF, TARGET_STATE_PRESENT));
        o_mcgroup = MCGROUP_5;
    }

fapi_try_exit:
    return current_err;
}

static char hex[] = "0123456789abcdef";

void strhex(char* o_str, uint64_t i_value, int i_width)
{
    while (i_width)
    {
        i_width--;
        o_str[i_width] = hex[i_value & 0xF];
        i_value >>= 4;
    }
}

ReturnCode putRingBucket(const Target<TARGET_TYPE_ALL_MC>& /*i_target*/,
                         const char* i_ring_id,
                         int i_bucket)
{
    char ring_id[RING_ID_MAXLEN];
    int len = strlen(i_ring_id);
    memcpy(ring_id, i_ring_id, len + 1);
    strhex(ring_id + len - 2, i_bucket, 2);
    return FAPI2_RC_SUCCESS; //putRing(i_target, ring_id); TODO enable when SBE platform supports putRing
}
