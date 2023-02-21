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
#include <p10_frequency_buckets.H>

// called from Host only -- uses knowledge of the Host MC frequency attributes
// to derive the relevant bucket selection for Odyssey
fapi2::ReturnCode ody_scratch_regs_get_pll_bucket(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    fapi2::ATTR_OCMB_PLL_BUCKET_Type& o_pll_bucket)
{
    FAPI_DBG("Start");

    fapi2::ATTR_IS_SIMULATION_Type l_is_simulation;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_is_simulation));

    if (l_is_simulation)
    {
        fapi2::ATTR_OCMB_PLL_BUCKET_SIM_Type l_ocmb_pll_bucket_sim;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OCMB_PLL_BUCKET_SIM, i_target, l_ocmb_pll_bucket_sim));
        o_pll_bucket = l_ocmb_pll_bucket_sim;
    }
    else
    {
        fapi2::Target<fapi2::TARGET_TYPE_OMI> l_omi_target;
        fapi2::Target<fapi2::TARGET_TYPE_MC> l_mc_target;
        fapi2::ATTR_FREQ_MC_MHZ_Type l_attr_freq_mc_mhz;
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_host_target;
        bool l_match_found = false;
        o_pll_bucket = 0;

        // walk target model back to host processor chip to determine the frequency of the memory
        // controller attached to this OCMB.  lookup this frequency in the set of supported OCMB
        // frequencies to compute the PLL bucket index to pass to the OCMB SBE to configure its
        // PLL at the matching frequency -- error if no match is found
        FAPI_TRY(i_target.getOtherEnd(l_omi_target));
        l_mc_target = l_omi_target.getParent<fapi2::TARGET_TYPE_MC>();
        l_host_target = l_omi_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_MC_MHZ, l_mc_target, l_attr_freq_mc_mhz),
                 "Error from FAPI_ATTR_GET (ATTR_FREQ_MC_MHZ)");

        for (auto l_ocmb_bucket = 0; l_ocmb_bucket < ODY_MAX_PLL_BUCKETS; l_ocmb_bucket++)
        {
            auto l_ocmb_bucket_descriptor = ODY_PLL_BUCKETS[l_ocmb_bucket];

            if (l_ocmb_bucket_descriptor.freq_grid_mhz == l_attr_freq_mc_mhz)
            {
                o_pll_bucket = l_ocmb_bucket;
                l_match_found = true;
                break;
            }
        }

        FAPI_ASSERT(l_match_found,
                    fapi2::ODY_SCRATCH_REGS_UTILS_BUCKET_LOOKUP_ERR()
                    .set_TARGET_CHIP(i_target)
                    .set_HOST_TARGET(l_host_target)
                    .set_HOST_FREQ_GRID_MHZ(l_attr_freq_mc_mhz),
                    "Requested Ody frequency (%d MHz) not found in p10_frequency_buckets.H!",
                    l_attr_freq_mc_mhz);
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


// called from Host/SPPE sides -- given fixed PLL bucket, return the associated
// grid/link frequencies
fapi2::ReturnCode ody_scratch_regs_get_pll_freqs(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const fapi2::ATTR_OCMB_PLL_BUCKET_Type i_pll_bucket,
    uint32_t& o_freq_grid_mhz,
    uint32_t& o_freq_link_mhz)
{
    FAPI_DBG("Start");

    FAPI_ASSERT(i_pll_bucket < ODY_NUM_PLL_BUCKETS,
                fapi2::ODY_SCRATCH_REGS_UTILS_BUCKET_OUT_OF_RANGE_ERR()
                .set_TARGET_CHIP(i_target)
                .set_BUCKET(i_pll_bucket),
                "Ody PLL bucket (%d) index is out of range!",
                i_pll_bucket);

    o_freq_grid_mhz = ODY_PLL_BUCKETS[i_pll_bucket].freq_grid_mhz;
    o_freq_link_mhz = ODY_PLL_BUCKETS[i_pll_bucket].freq_link_mhz;

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
        fapi2::MCGROUP_1,   1
    } );
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
        fapi2::MCGROUP_5,   5
    } );
    l_group_map.push_back((fapi2::MulticastGroupMapping)
    {
        fapi2::MCGROUP_6,   6
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
