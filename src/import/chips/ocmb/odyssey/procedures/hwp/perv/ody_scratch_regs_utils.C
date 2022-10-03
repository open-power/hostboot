/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/perv/ody_scratch_regs_utils.C $ */
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
/// @file  ody_scratch_regs_utils.C
/// @brief Project specific utility functions to support Odyssey scratch
///        register setup
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Anusha Reddy (anusrang@in.ibm.com)
// *HWP FW Maintainer   : Raja Das (rajadas2@in.ibm.com)
//------------------------------------------------------------------------------

#include <ody_scratch_regs_utils.H>
#include <poz_perv_common_params.H>
#include <multicast_group_defs.H>

fapi2::ReturnCode ody_scratch_regs_get_pll_bucket(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    fapi2::ATTR_OCMB_PLL_BUCKET_Type& o_pll_bucket)
{
    FAPI_DBG("Start");

    fapi2::ATTR_IS_SIMULATION_Type l_is_simulation;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_is_simulation));

    if (l_is_simulation)
    {
        o_pll_bucket = 1;
    }
    else
    {
#if 0
        // RTC: 279640 TODO: translate host side PLL bucket definition into OCMB/Odyssey side bucket
        fapi2::Target<fapi2::TARGET_TYPE_OMI> l_omi_target;
        fapi2::Target<fapi2::TARGET_TYPE_MC> l_mc_target;
        fapi2::ATTR_CHIP_UNIT_POS_Type l_mc_unit_pos;
        fapi2::ATTR_MC_PLL_BUCKET_Type l_host_mc_pll_bucket;
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_host_target;
#endif
        o_pll_bucket = 0;
#if 0
        FAPI_TRY(i_target.getOtherEnd(l_omi_target));
        l_mc_target = l_omi_target.getParent<fapi2::TARGET_TYPE_MI>();
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_mc_target, l_mc_unit_pos));
        l_host_target = l_omi_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MC_PLL_BUCKET, l_host_target, l_host_mc_pll_bucket));
        o_pll_bucket = l_host_mc_pll_bucket[l_mc_unit_pos];
#endif
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


fapi2::ReturnCode ody_scratch_regs_setup_plat_multicast_attrs(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
#if !defined(__HOSTBOOT_MODULE) && !defined(__PPE__)
    std::vector<fapi2::MulticastGroupMapping> l_group_map;
    l_group_map.push_back((fapi2::MulticastGroupMapping)
    {
        fapi2::MCGROUP_2,   2
    } );
    l_group_map.push_back((fapi2::MulticastGroupMapping)
    {
        fapi2::MCGROUP_4,   4
    } );
    l_group_map.push_back((fapi2::MulticastGroupMapping)
    {
        fapi2::MCGROUP_5,   6
    } );
    l_group_map.push_back((fapi2::MulticastGroupMapping)
    {
        fapi2::MCGROUP_5,   6
    } );
    l_group_map.push_back((fapi2::MulticastGroupMapping)
    {
        fapi2::MCGROUP_ALL, 7
    } );
    FAPI_TRY(fapi2::setMulticastGroupMap(i_target, l_group_map));
fapi_try_exit:
#endif
    return fapi2::current_err;
}
