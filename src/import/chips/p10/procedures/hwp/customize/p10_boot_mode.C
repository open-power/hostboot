/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/customize/p10_boot_mode.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
/// @file  p10_boot_mode.C
/// @brief Calculate and return set of dynamic init features to be applied
///        at image customization time
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Maintainer   : Sumit Kumar <sumit_kumar@in.ibm.com>
// *HWP Consumed by     : HB
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_boot_mode.H>
#include <p10_dyninit_bitvec_utils.H>
#include <p10_dynamic.H>
#include <p10_ipl_customize.H>
#include <p10_fbc_async_utils.H>

//------------------------------------------------------------------------------
// Constant Definitions
//------------------------------------------------------------------------------

#ifndef __P10_BOOT_MODE_NO_BACKWARDS_COMPAT__
// remap dynamic init features supported prior to addition of dyninit
// image sections
const std::vector<uint8_t> DYN_FEATURES_COMPAT_XLATE_MAP =
    // old index        new index   feature
    // -------------------------------------------
{
    0,              // 00       CACHE_CONTAINED
    1,              // 01       CHIP_CONTAINED
    2,              // 02       COMMON_CONTAINED
    3,              // 03       HOSTBOOT
    24,             // 04       HV_INITS
    4,              // 05       L2RC_HIGH_JITTER
    17,             // 06       MC2RT_NOMINAL
    18,             // 07       MC2RT_SAFE
    16,             // 08       MC2RT_TURBO
    15,             // 09       MC2RT_ULTRATURBO
    9,              // 10       MC_FAST
    25,             // 11       MMA_STATIC_POWEROFF
    13,             // 12       PA2RT_NOMINAL
    14,             // 13       PA2RT_SAFE
    12,             // 14       PA2RT_TURBO
    21,             // 15       RT2MC_NOMINAL
    22,             // 16       RT2MC_SAFE
    20,             // 17       RT2MC_TURBO
    19,             // 18       RT2MC_ULTRATURBO
    10,             // 19       RT2PA_NOMINAL
    11,             // 20       RT2PA_SAFE
    5,              // 21       RUNN_SRESET_THREAD0
    6,              // 22       RUNN_SRESET_THREAD1
    7,              // 23       RUNN_SRESET_THREAD2
    8,              // 24       RUNN_SRESET_THREAD3
    23,             // 25       RUNN_USE_QME_TB_SRC
    26,             // 26       RUNN_CONTAINED_DUMP
    27,             // 27       UV_INITS
    28,             // 28       CONVERT_DCBZ_TO_RWITM
};
#endif

//------------------------------------------------------------------------------
// Function definitions
//-----------------------------------------------------------------------------

///
/// @brief Bit vector utility function -- merge HW image and platform
///        bit vectors
///
/// Logically ORs the content of the two input bit vectors, producing an
/// output bit vector that is sized to the larger of the two input vectors.
///
/// Checks to ensure that the platform bit vector does not contain any
/// bits set beyond the end of the HW image bit vector range -- in the
/// scope of the larger HWP execution, this corresponds to a request from
/// the platform which cannot be supported by the HW image content.
///
/// @param[in]  i_hw_image_bvec   HW image bit vector
/// @param[in]  i_plat_bvec       Platform bit vector
///
/// @returns fapi2::ReturnCode FAPI2_RC_SUCCESS if successful, else error
///
fapi2::ReturnCode
merge_bitvecs(
    const p10_dyninit_bitvec& i_hw_image_bvec,
    const p10_dyninit_bitvec& i_plat_bvec,
    p10_dyninit_bitvec& o_merged_bvec)
{
    FAPI_DBG("Start");

    using namespace p10_dyninit_bitvec_utils;

    // validate inputs
    FAPI_ASSERT((i_hw_image_bvec.iv_source == HW_IMAGE) &&
                (i_plat_bvec.iv_source == PLAT) &&
                (i_hw_image_bvec.iv_type == i_plat_bvec.iv_type),
                fapi2::P10_BOOT_MODE_BITVEC_MERGE_ERROR()
                .set_HW_IMAGE_BIT_COUNT(i_hw_image_bvec.iv_bit_count)
                .set_HW_IMAGE_SIZE(i_hw_image_bvec.iv_bits.size())
                .set_HW_IMAGE_SOURCE(i_hw_image_bvec.iv_source)
                .set_HW_IMAGE_TYPE(i_hw_image_bvec.iv_type)
                .set_PLAT_BIT_COUNT(i_plat_bvec.iv_bit_count)
                .set_PLAT_SIZE(i_plat_bvec.iv_bits.size())
                .set_PLAT_SOURCE(i_plat_bvec.iv_source)
                .set_PLAT_TYPE(i_plat_bvec.iv_type),
                "Unexpected state in bit vectors requested for merging!");

    // size output vector to larger of the two vectors and clear it
    o_merged_bvec.iv_bit_count =
        (i_plat_bvec.iv_bit_count > i_hw_image_bvec.iv_bit_count) ?
        (i_plat_bvec.iv_bit_count) :
        (i_hw_image_bvec.iv_bit_count);

    o_merged_bvec.iv_bits.resize((o_merged_bvec.iv_bit_count / 64) ?
                                 (o_merged_bvec.iv_bit_count / 64) :
                                 (1));
    o_merged_bvec.iv_source = MERGED;
    o_merged_bvec.iv_type = i_hw_image_bvec.iv_type;

    // walk range of output vector
    for (uint16_t l_bit = 0; l_bit < o_merged_bvec.iv_bit_count; l_bit++)
    {
        // process HW image bit vector first
        bool l_hw_image_bit_set = false;
        bool l_hw_image_bit_in_range = test_bit_in_range(i_hw_image_bvec, l_bit);

        if (l_hw_image_bit_in_range)
        {
            FAPI_TRY(is_bit_set(i_hw_image_bvec, l_bit, l_hw_image_bit_set));

            if (l_hw_image_bit_set)
            {
                FAPI_TRY(set_bit(o_merged_bvec, l_bit, "HW"));
            }
        }

        // process plat bit vector -- skip this bit position if we've already
        // determined bit is set in HW image vector
        if (!l_hw_image_bit_set)
        {
            bool l_plat_bit_set = false;
            bool l_plat_bit_in_range = test_bit_in_range(i_plat_bvec, l_bit);

            if (l_plat_bit_in_range)
            {
                FAPI_TRY(is_bit_set(i_plat_bvec, l_bit, l_plat_bit_set));
                FAPI_ASSERT(!l_plat_bit_set ||
                            l_hw_image_bit_in_range,
                            fapi2::P10_BOOT_MODE_BITVEC_PLAT_ERROR()
                            .set_HW_IMAGE_BIT_COUNT(i_hw_image_bvec.iv_bit_count)
                            .set_HW_IMAGE_SIZE(i_hw_image_bvec.iv_bits.size())
                            .set_HW_IMAGE_SOURCE(i_hw_image_bvec.iv_source)
                            .set_HW_IMAGE_TYPE(i_hw_image_bvec.iv_type)
                            .set_PLAT_BIT_COUNT(i_plat_bvec.iv_bit_count)
                            .set_PLAT_SIZE(i_plat_bvec.iv_bits.size())
                            .set_PLAT_SOURCE(i_plat_bvec.iv_source)
                            .set_PLAT_TYPE(i_plat_bvec.iv_type)
                            .set_BIT_POS(l_bit),
                            "Platform requested bit position (%d) is out of HW image range!",
                            l_bit);

                if (l_plat_bit_set)
                {
                    FAPI_TRY(set_bit(o_merged_bvec, l_bit, "PLAT"));
                }
            }
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;

}

///
/// @brief Initialize bit vector from HW image capabilities
///
/// Queries requested dynamic init section from HW image (services or
/// features) to determine HW image capabilities.
///
/// Returns an all zero bit vector of the appropriate size, along with a
/// pointer to the section data for future API queries.
///
/// @param[in]  i_target        Processor chip target
/// @param[in]  i_hw_image      Pointer to HW image
/// @param[in]  i_type          Type of bit vector to create.  Used to index
///                             into appropriate HW image section.
/// @param[out] o_section_ptr   Pointer to HW image section
/// @param[out] o_bvec          Zeroed bit vector sized to HW image capability
///
/// @returns fapi2::ReturnCode FAPI2_RC_SUCCESS if successful, else error
///
fapi2::ReturnCode
init_bitvec_from_hw_image(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    void* const i_hw_image,
    const p10_dyninit_bitvec_type i_type,
    void*& o_section_ptr,
    p10_dyninit_bitvec& o_bvec)
{
    P9XipSection l_section;
    int l_xip_rc;
    bool l_skip_section_check = false;
    uint8_t l_bvec_size = 0;
    o_section_ptr = NULL;

    FAPI_DBG("Start");

#ifndef __P10_BOOT_MODE_NO_BACKWARDS_COMPAT__
    l_skip_section_check = true;
#endif

    // query HW image, fill structure based on requested section
    l_xip_rc = p9_xip_get_section(i_hw_image,
                                  static_cast<p9_xip_section_hw_t>(i_type),
                                  &l_section);

    // error in lookup, return error
    FAPI_ASSERT((l_xip_rc == INFRASTRUCT_RC_SUCCESS) &&
                (l_skip_section_check ||
                 (l_section.iv_size != 0)),
                fapi2::XIPC_XIP_GET_SECTION_ERROR()
                .set_CHIP_TARGET(i_target)
                .set_XIP_RC(l_xip_rc)
                .set_SECTION_ID(i_type)
                .set_DDLEVEL(UNDEFINED_DD_LEVEL)
                .set_OCCURRENCE(1),
                "init_bitvec_from_hw_image -- p9_xip_get_section() failed w/rc=0x%08X for section"
                " section 0x%x",
                (uint32_t)l_xip_rc, i_type);

#ifndef __P10_BOOT_MODE_NO_BACKWARDS_COMPAT__

    // section not found -- code will only execute if compiled
    // for backwards compatability with old images that do not
    // contain the section
    if (l_section.iv_size == 0)
    {
        FAPI_INF("HW image section (ID=0x%X) empty or not found!",
                 i_type);

        if (i_type == MODE)
        {
            o_bvec.iv_bit_count = 0;
        }
        else
        {
            o_bvec.iv_bit_count = DYN_FEATURES_COMPAT_XLATE_MAP.size();
        }

        l_bvec_size = 1;
    }
    else
#endif
        // section found, process it
    {
        // set pointer to section
        o_section_ptr = (void*) (l_section.iv_offset + (uint8_t*) i_hw_image);
        // consult HW image to build set of supported init modes
        dynamic_get_bitVectorSize_n_numRecords(o_section_ptr,
                                               &l_bvec_size,
                                               &o_bvec.iv_bit_count);
    }

    o_bvec.iv_bits.resize(l_bvec_size);

    for (uint16_t iSet = 0; iSet < l_bvec_size; iSet++)
    {
        o_bvec.iv_bits[iSet] = 0;
    }

    o_bvec.iv_type = i_type;
    o_bvec.iv_source = HW_IMAGE;

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Build set of dynamic init features required to satisfy
///        requested init modes using HW image
///
/// Queries platform attributes to initialize bit vector content sized
/// to match build time attribute properties
///
/// @param[in]  i_section_ptr   Pointer to HW image section
/// @param[in]  i_mode_bvec     Bit vector containing init modes to apply
/// @param[out] o_feature_bvec  Bit vector containing set of associated
///                             dynamic inits
///
/// @returns fapi2::ReturnCode FAPI2_RC_SUCCESS if successful, else error
///
fapi2::ReturnCode
fill_bitvec_from_hw_image(
    void* const i_section_ptr,
    const p10_dyninit_bitvec& i_mode_bvec,
    p10_dyninit_bitvec& o_feature_bvec)
{
    using namespace p10_dyninit_bitvec_utils;

    FAPI_DBG("Start");

    // allocate bitvec to hold feature content for each init mode
    // retreived
    p10_dyninit_bitvec l_feature_bvec;
    l_feature_bvec.iv_bits.resize(o_feature_bvec.iv_bits.size());
    l_feature_bvec.iv_bit_count = o_feature_bvec.iv_bit_count;
    l_feature_bvec.iv_source = o_feature_bvec.iv_source;
    l_feature_bvec.iv_type = o_feature_bvec.iv_type;

    // validate inputs
    FAPI_ASSERT((i_mode_bvec.iv_type == MODE) &&
                (o_feature_bvec.iv_type == FEATURE),
                fapi2::P10_BOOT_MODE_FEATURE_LOOKUP_ERROR()
                .set_MODE_BIT_COUNT(i_mode_bvec.iv_bit_count)
                .set_MODE_SIZE(i_mode_bvec.iv_bits.size())
                .set_MODE_SOURCE(i_mode_bvec.iv_source)
                .set_MODE_TYPE(i_mode_bvec.iv_type)
                .set_FEATURE_BIT_COUNT(o_feature_bvec.iv_bit_count)
                .set_FEATURE_SIZE(o_feature_bvec.iv_bits.size())
                .set_FEATURE_SOURCE(o_feature_bvec.iv_source)
                .set_FEATURE_TYPE(o_feature_bvec.iv_type),
                "Unexpected state in bit vectors supplied for HW image lookup!");


    // for each active init mode, query HW image to retreive associated
    // dynamic inits & OR into output feature bitvec
    for (uint16_t l_bit = 0; l_bit < i_mode_bvec.iv_bit_count; l_bit++)
    {
        bool l_init_mode_set = false;
        FAPI_TRY(is_bit_set(i_mode_bvec, l_bit, l_init_mode_set));

        if (l_init_mode_set)
        {
            // lookup feature content for this init mode
            dynamic_get_bitVector_perValue(i_section_ptr,
                                           l_bit,
                                           &(l_feature_bvec.iv_bits[0]));

            // logically OR content into output feature bitvec
            for (uint16_t i = 0; i < o_feature_bvec.iv_bits.size(); i++)
            {
                o_feature_bvec.iv_bits[i] |= l_feature_bvec.iv_bits[i];
            }
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Add SBE phase dynamic init features (non-contained)
///
/// @param[in]  i_target_proc  Processor scope target for attribute query
/// @param[in]  i_target_sys   System scope target for attribute query
/// @param[in]  i_bvec         Bit vector filled to platform state/capabilities
/// @param[in]  i_img_bvec     Bit vector representing image state/capabilities
///
/// @returns fapi2::ReturnCode FAPI2_RC_SUCCESS if successful, else error
///
fapi2::ReturnCode
add_plat_features_sbe(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_proc,
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target_sys,
    p10_dyninit_bitvec& i_bvec,
    p10_dyninit_bitvec& i_img_bvec)
{
    using namespace p10_dyninit_bitvec_utils;

    FAPI_DBG("Start");

    // apply baseline Hostboot dynamic inits
    FAPI_TRY(set_bit(i_bvec, HOSTBOOT, "HOSTBOOT"));

    // apply fabric async settings
    {
        rt2pa_ratio l_rt2pa;
        pa2rt_ratio l_pa2rt;
        uint32_t    l_freq_mc_mhz;
        rt2mc_ratio l_rt2mc;
        mc2rt_ratio l_mc2rt;

        // PAU
        FAPI_TRY(p10_fbc_async_utils_calc_pau_ratios(i_target_sys,
                 l_rt2pa,
                 l_pa2rt),
                 "Error from p10_fbc_async_utils_calc_pau_ratios");

        // racetrack-to-PAU
        if (l_rt2pa == RT2PA_RATIO_NOMINAL)
        {
            FAPI_TRY(set_bit(i_bvec, RT2PA_NOMINAL, "RT2PA_NOMINAL"));
        }
        else
        {
            FAPI_TRY(set_bit(i_bvec, RT2PA_SAFE, "RT2PA_SAFE"));
        }

        // PAU-to-racetrack
        if (l_pa2rt == PA2RT_RATIO_TURBO)
        {
            FAPI_TRY(set_bit(i_bvec, PA2RT_TURBO, "PA2RT_TURBO"));
        }
        else if (l_pa2rt == PA2RT_RATIO_NOMINAL)
        {
            FAPI_TRY(set_bit(i_bvec, PA2RT_NOMINAL, "PA2RT_NOMINAL"));
        }
        else
        {
            FAPI_TRY(set_bit(i_bvec, PA2RT_SAFE, "PA2RT_SAFE"));
        }

        // MC
        FAPI_TRY(p10_fbc_async_utils_calc_mc_ratios(i_target_proc,
                 i_target_sys,
                 l_freq_mc_mhz,
                 l_rt2mc,
                 l_mc2rt),
                 "Error from p10_fbc_async_utils_calc_mc_ratios");

        // racetrack-to-MC
        if (l_rt2mc == RT2MC_RATIO_ULTRATURBO)
        {
            FAPI_TRY(set_bit(i_bvec, RT2MC_ULTRATURBO, "RT2MC_ULTATURBO"));
        }
        else if (l_rt2mc == RT2MC_RATIO_TURBO)
        {
            FAPI_TRY(set_bit(i_bvec, RT2MC_TURBO, "RT2MC_TURBO"));
        }
        else if (l_rt2mc == RT2MC_RATIO_NOMINAL)
        {
            FAPI_TRY(set_bit(i_bvec, RT2MC_NOMINAL, "RT2MC_NOMINAL"));
        }
        else
        {
            FAPI_TRY(set_bit(i_bvec, RT2MC_SAFE, "RT2MC_SAFE"));
        }

        // MC-to-racetrack
        if (l_mc2rt == MC2RT_RATIO_ULTRATURBO)
        {
            FAPI_TRY(set_bit(i_bvec, MC2RT_ULTRATURBO, "MC2RT_ULTRATURBO"));
        }
        else if (l_mc2rt == MC2RT_RATIO_TURBO)
        {
            FAPI_TRY(set_bit(i_bvec, MC2RT_TURBO, "MC2RT_TURBO"));
        }
        else if (l_mc2rt == MC2RT_RATIO_NOMINAL)
        {
            FAPI_TRY(set_bit(i_bvec, MC2RT_NOMINAL, "MC2RT_NOMINAL"));
        }
        else
        {
            FAPI_TRY(set_bit(i_bvec, MC2RT_SAFE, "MC2RT_SAFE"));
        }

        // MC fast
        if (l_freq_mc_mhz > 1610)
        {
            FAPI_TRY(set_bit(i_bvec, MC_FAST, "MC_FAST"));
        }
    }

    // fabric broadcast configuration
    {
        fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE_Type l_fbc_broadcast_mode;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE,
                               i_target_sys,
                               l_fbc_broadcast_mode));

        if (l_fbc_broadcast_mode == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
        {
            if (test_bit_in_range(i_img_bvec, FBC_ONEHOP))
            {
                FAPI_TRY(set_bit(i_bvec, FBC_ONEHOP, "FBC_ONEHOP"));
            }
            else
            {
                FAPI_INF("Unable to set FBC_ONEHOP, feature unsupported by HW reference image");
            }
        }
    }

    // contained mode
    {
        fapi2::ATTR_CONTAINED_IPL_TYPE_Type l_attr_contained_ipl_type;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CONTAINED_IPL_TYPE,
                               i_target_sys,
                               l_attr_contained_ipl_type));

        if (l_attr_contained_ipl_type !=
            fapi2::ENUM_ATTR_CONTAINED_IPL_TYPE_NONE)
        {
            FAPI_TRY(set_bit(i_bvec, CONTAINED_CLKOFFS, "CONTAINED_CLKOFFS"));
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Add SBE phase dynamic init features (contained)
///
/// @param[in]  i_target_proc  Processor scope target for attribute query
/// @param[in]  i_target_sys   System scope target for attribute query
/// @param[in]  i_bvec         Bit vector filled to platform state/capabilities
///
/// @returns fapi2::ReturnCode FAPI2_RC_SUCCESS if successful, else error
///
fapi2::ReturnCode
add_plat_features_sbe_contained(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_proc,
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target_sys,
    p10_dyninit_bitvec& i_bvec)
{
    using namespace p10_dyninit_bitvec_utils;

    FAPI_DBG("Start");

    fapi2::ATTR_CONTAINED_IPL_TYPE_Type l_attr_contained_ipl_type;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CONTAINED_IPL_TYPE,
                           i_target_sys,
                           l_attr_contained_ipl_type));

    FAPI_TRY(set_bit(i_bvec, COMMON_CONTAINED, "COMMON_CONTAINED"));
    FAPI_TRY(set_bit(i_bvec, CONTAINED_CLKOFFS, "CONTAINED_CLKOFFS"));

    if (l_attr_contained_ipl_type == fapi2::ENUM_ATTR_CONTAINED_IPL_TYPE_CACHE)
    {
        FAPI_TRY(set_bit(i_bvec, CACHE_CONTAINED, "CACHE_CONTAINED"));
    }
    else
    {
        FAPI_TRY(set_bit(i_bvec, CHIP_CONTAINED, "CHIP_CONTAINED"));
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Add runtime phase dynamic init features
///
/// @param[in]  i_target_proc  Processor scope target for attribute query
/// @param[in]  i_target_sys   System scope target for attribute query
/// @param[in]  i_bvec         Bit vector filled to platform state/capabilities
///
/// @returns fapi2::ReturnCode FAPI2_RC_SUCCESS if successful, else error
///
fapi2::ReturnCode
add_plat_features_rt(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_proc,
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target_sys,
    p10_dyninit_bitvec& i_bvec)
{
    using namespace p10_dyninit_bitvec_utils;

    FAPI_DBG("Start");

    fapi2::ATTR_SMF_CONFIG_Type l_attr_smf_config;
    fapi2::ATTR_SYSTEM_MMA_POWERON_DISABLE_Type l_attr_system_mma_poweron_disable;
    fapi2::ATTR_MRW_L2_INCREASE_JITTER_Type l_attr_mrw_l2_increase_jitter;
    fapi2::ATTR_CONTAINED_IPL_TYPE_Type l_attr_contained_ipl_type;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SMF_CONFIG,
                           i_target_sys,
                           l_attr_smf_config));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_MMA_POWERON_DISABLE,
                           i_target_sys,
                           l_attr_system_mma_poweron_disable));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MRW_L2_INCREASE_JITTER,
                           i_target_sys,
                           l_attr_mrw_l2_increase_jitter));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CONTAINED_IPL_TYPE,
                           i_target_sys,
                           l_attr_contained_ipl_type));

    if (l_attr_smf_config == fapi2::ENUM_ATTR_SMF_CONFIG_ENABLED)
    {
        FAPI_TRY(set_bit(i_bvec, UV_INITS, "UV_INITS"));
    }

    if (l_attr_system_mma_poweron_disable == fapi2::ENUM_ATTR_SYSTEM_MMA_POWERON_DISABLE_ON)
    {
        FAPI_TRY(set_bit(i_bvec, MMA_STATIC_POWEROFF, "MMA_STATIC_POWEROFF"));
    }

    // apply only outside of contained modes
    if (l_attr_contained_ipl_type == fapi2::ENUM_ATTR_CONTAINED_IPL_TYPE_NONE)
    {
        if (l_attr_mrw_l2_increase_jitter == fapi2::ENUM_ATTR_MRW_L2_INCREASE_JITTER_TRUE)
        {
            FAPI_TRY(set_bit(i_bvec, L2RC_HIGH_JITTER, "L2RC_HIGH_JITTER"));
        }

        // by default, escalate core->system checkstop in Cronus
        if (fapi2::is_platform<fapi2::PLAT_CRONUS>())
        {
            FAPI_TRY(set_bit(i_bvec, CRONUS_CORE_TO_SYS_XSTOP, "CRONUS_CORE_TO_SYS_XSTOP"));
        }
    }

    // ensure unwanted features are cleared (necessary based on
    // contained mode usage)
    FAPI_TRY(clear_bit(i_bvec, HOSTBOOT, "HOSTBOOT"));
    FAPI_TRY(clear_bit(i_bvec, COMMON_CONTAINED, "COMMON_CONTAINED"));
    FAPI_TRY(clear_bit(i_bvec, CACHE_CONTAINED, "CACHE_CONTAINED"));
    FAPI_TRY(clear_bit(i_bvec, CHIP_CONTAINED, "CHIP_CONTAINED"));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Add dynamic init features based on current platform state
///
/// @param[in]  i_target_proc  Processor scope target for attribute query
/// @param[in]  i_target_sys   System scope target for attribute query
/// @param[in]  i_sys_phase    Customization phase {HB_SBE,RT_QME,HB_MEAS}
/// @param[in]  i_bvec         Bit vector filled to platform state/capabilities
/// @param[in]  i_img_bvec     Bit vector filled to image state/capabilities
///
/// @returns fapi2::ReturnCode FAPI2_RC_SUCCESS if successful, else error
///
fapi2::ReturnCode
add_plat_features(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_proc,
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target_sys,
    uint8_t i_sys_phase,
    p10_dyninit_bitvec& i_bvec,
    p10_dyninit_bitvec& i_img_bvec)
{
    FAPI_DBG("Start");

    fapi2::ATTR_SYSTEM_IPL_PHASE_Type l_attr_system_ipl_phase;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_IPL_PHASE,
                           i_target_sys,
                           l_attr_system_ipl_phase));

    // SBE phase (non-contained) inits
    if ((l_attr_system_ipl_phase == fapi2::ENUM_ATTR_SYSTEM_IPL_PHASE_HB_IPL) &&
        (i_sys_phase == SYSPHASE_HB_SBE))
    {
        FAPI_TRY(add_plat_features_sbe(i_target_proc,
                                       i_target_sys,
                                       i_bvec,
                                       i_img_bvec));
    }
    // SBE phase (contained) inits
    else if (l_attr_system_ipl_phase == fapi2::ENUM_ATTR_SYSTEM_IPL_PHASE_CONTAINED_IPL)
    {
        FAPI_TRY(add_plat_features_sbe_contained(i_target_proc,
                 i_target_sys,
                 i_bvec));
    }
    // Runtime specific inits
    else
    {
        FAPI_TRY(add_plat_features_rt(i_target_proc,
                                      i_target_sys,
                                      i_bvec));
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


#ifndef __P10_BOOT_MODE_NO_BACKWARDS_COMPAT__
///
/// @brief Rewrite feature bit vector for compatability with HW image content
///        prior to addition of dynamic init services and feature sections
///
/// @param[out]  o_bvec        Bit vector adjusted to old feature numbering schema
///
/// @returns fapi2::ReturnCode FAPI2_RC_SUCCESS if successful, else error
///
fapi2::ReturnCode
rewrite_bitvec(
    p10_dyninit_bitvec& o_bvec)
{
    using namespace p10_dyninit_bitvec_utils;

    p10_dyninit_bitvec l_remap_bvec;
    l_remap_bvec.iv_bits.resize(o_bvec.iv_bits.size());
    l_remap_bvec.iv_bit_count = o_bvec.iv_bit_count;

    for (uint16_t l_bit = 0; l_bit < o_bvec.iv_bit_count; l_bit++)
    {
        bool l_bit_set = false;
        FAPI_TRY(is_bit_set(o_bvec, l_bit, l_bit_set));

        if (l_bit_set)
        {
            FAPI_TRY(set_bit(l_remap_bvec, DYN_FEATURES_COMPAT_XLATE_MAP[l_bit], NULL));
        }
    }

    o_bvec.iv_bits = l_remap_bvec.iv_bits;

fapi_try_exit:
    return fapi2::current_err;
}
#endif


//------------------------------------------------------------------------------
// HWP entry point
//------------------------------------------------------------------------------

///
/// @brief Calculate and return set of dynamic init features to be applied
///        at image customization time
///
/// @param[in]  i_target_chip  Reference to TARGET_TYPE_PROC_CHIP target
/// @param[in]  i_hw_image     Pointer to HW image
/// @param[in]  i_sys_phase    Customization phase {HB_SBE,RT_QME,HB_MEAS}
/// @param[out] o_vector_vec   Bit vector of features to be applied
///
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode
p10_boot_mode(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
    void* const i_hw_image,
    uint8_t i_sys_phase,
    p10_dyninit_bitvec& o_feature_bvec)
{
    using namespace p10_dyninit_bitvec_utils;

    FAPI_DBG("Start");

    // targets
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    // HW image pointers
    void* l_dyn_services_ptr = NULL;
    void* l_dyn_features_ptr = NULL;

    // mode (services) bit vectors
    p10_dyninit_bitvec l_hw_image_mode_bvec;
    p10_dyninit_bitvec l_plat_mode_bvec;
    p10_dyninit_bitvec l_mode_bvec;

    // feature bit vectors
    p10_dyninit_bitvec l_hw_image_feature_bvec;
    p10_dyninit_bitvec l_plat_feature_bvec;

    //
    // dynamic init mode handling
    //

    // initialize bit vector from HW image sized to represent
    // set of supported init modes -- content will be all zero
    FAPI_TRY(init_bitvec_from_hw_image(i_proc_target,
                                       i_hw_image,
                                       MODE,
                                       l_dyn_services_ptr,
                                       l_hw_image_mode_bvec),
             "Error from init_bitvec_from_hw_image (mode)");

    dump_bitvec(l_hw_image_mode_bvec);

    // initialize bit vector from platform -- content will reflect attribute
    // selected init modes
    FAPI_TRY(init_bitvec_from_plat(i_proc_target,
                                   MODE,
                                   l_plat_mode_bvec),
             "Error from init_bitvec_from_plat (mode)");

    dump_bitvec(l_plat_mode_bvec);

    // merge bit vectors, confirms all platform requested init modes are
    // supported by HW image capabilities
    FAPI_TRY(merge_bitvecs(l_hw_image_mode_bvec,
                           l_plat_mode_bvec,
                           l_mode_bvec),
             "Error from merge_bitvecs (mode)");

    dump_bitvec(l_mode_bvec);


    //
    // dynamic init feature handling
    //

    // initialize bit vector from HW image sized to represent
    // set of supported features -- content will be all zero after
    // this call
    FAPI_TRY(init_bitvec_from_hw_image(i_proc_target,
                                       i_hw_image,
                                       FEATURE,
                                       l_dyn_features_ptr,
                                       l_hw_image_feature_bvec),
             "Error from init_bitvec_from_hw_image (feature)");

    dump_bitvec(l_hw_image_feature_bvec);

    // fill HW image bit vector by ORing in HW image defined
    // values for each selected init mode
    FAPI_TRY(fill_bitvec_from_hw_image(l_dyn_services_ptr,
                                       l_mode_bvec,
                                       l_hw_image_feature_bvec),
             "Error from fill_bitvec_from_hw_image");

    dump_bitvec(l_hw_image_feature_bvec);

    // initialize bit vector from platform -- content will reflect
    // curent value of platform dynamic init feature vector attribute
    FAPI_TRY(init_bitvec_from_plat(i_proc_target,
                                   FEATURE,
                                   l_plat_feature_bvec),
             "Error from init_bitvec_from_plat (feature)");

    dump_bitvec(l_plat_feature_bvec);

    // layer in other features that are needed based on current
    // platform atribute state
    FAPI_TRY(add_plat_features(i_proc_target,
                               FAPI_SYSTEM,
                               i_sys_phase,
                               l_plat_feature_bvec,
                               l_hw_image_feature_bvec),
             "Error from add_plat_features");

    dump_bitvec(l_plat_feature_bvec);

    // write platform dynamic init feature vector attribute,
    // honor platform attribute override
    FAPI_TRY(save_bitvec_to_plat(i_proc_target,
                                 l_plat_feature_bvec),
             "Error from save_bitvec_to_plat");

    dump_bitvec(l_plat_feature_bvec);

    // merge bit vectors, confirms all platform requested features are
    // supported by HW image capabilities
    FAPI_TRY(merge_bitvecs(l_hw_image_feature_bvec,
                           l_plat_feature_bvec,
                           o_feature_bvec),
             "Error from or_bvecs (feature)");

#ifndef __P10_BOOT_MODE_NO_BACKWARDS_COMPAT__

    if (!l_dyn_services_ptr &&
        !l_dyn_features_ptr)
    {
        FAPI_DBG("Remapping feature bit vector");
        FAPI_TRY(rewrite_bitvec(o_feature_bvec));
    }

#endif

    dump_bitvec(o_feature_bvec);

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

// TODO optimize to process in 64 bit chunks
// walk range of output vector
// merge_bitvecs
