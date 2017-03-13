/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/mss_attribute_accessors_manual.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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

///
/// @file mss_attribute_accessors_manual.H
/// @brief Manually created attribute accessors.
/// Some attributes aren't in files we want to incorporate in to our automated
/// accessor generator. EC workarounds is one example - everytime someone creates
/// a work-around they'd be burdened with updating this file.
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory

#ifndef MSS_ATTR_ACCESS_MANUAL_H_
#define MSS_ATTR_ACCESS_MANUAL_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/find.H>

namespace mss
{

///
/// @brief 2N mode helper
/// When figuring out 2N mode we need to access two attributes. This helper
/// gives us a place to put that common code
/// @tparam T the fapi2::TargetType of the input target
/// @param[in] the target from which to get the 2N mode autoset attribute
/// @return true iff 2N mode is 'on'
///
template< fapi2::TargetType T >
inline bool two_n_mode_helper(const fapi2::Target<T>& i_target)
{
    uint8_t l_2n_autoset = 0;
    uint8_t l_2n_mrw_mode = 0;

    // There are no VPD enums defined for 2N autoset <shrug>.
    constexpr uint8_t ATTR_MSS_VPD_MR_MC_2N_MODE_AUTOSET_2N_MODE = 0x02;

    const auto l_mcs = mss::find_target<fapi2::TARGET_TYPE_MCS>(i_target);

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MSS_VPD_MR_MC_2N_MODE_AUTOSET, l_mcs, l_2n_autoset) );
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_DRAM_2N_MODE, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_2n_mrw_mode) );

    // If the MRW states 'auto' we use what's in VPD, otherwise we use what's in the MRW.
    return (l_2n_mrw_mode == fapi2::ENUM_ATTR_MSS_MRW_DRAM_2N_MODE_AUTO) ?
           l_2n_autoset == ATTR_MSS_VPD_MR_MC_2N_MODE_AUTOSET_2N_MODE :
           l_2n_mrw_mode == fapi2::ENUM_ATTR_MSS_MRW_DRAM_2N_MODE_FORCE_TO_2N_MODE;

fapi_try_exit:
    FAPI_ERR("failed accessing vpd_mr_mc_2n_mode_autoset or mrw_dram_2n_mode: 0x%lx (target: %s)",
             uint64_t(fapi2::current_err), mss::c_str(i_target));
    fapi2::Assert(false);
    return false;
}

///
/// @brief ATTR_CHIP_EC_FEATURE_MSS_UT_EC_NIMBUS_LESS_THAN_TWO_OH getter
/// @tparam T the fapi2 target type of the target
/// @param[in] const ref to the target
/// @return bool true iff we're on a Nimbus < EC 2.0
///
template< fapi2::TargetType T >
inline bool chip_ec_nimbus_lt_2_0(const fapi2::Target<T>& i_target)
{
    const auto l_chip = mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_target);
    uint8_t l_value = 0;

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_MSS_UT_EC_NIMBUS_LESS_THAN_TWO_OH, l_chip, l_value) );

    return l_value != 0;

fapi_try_exit:
    FAPI_ERR("failed accessing ATTR_CHIP_EC_FEATURE_MSS_UT_EC_NIMBUS_LESS_THAN_TWO_OH: 0x%lx (target: %s)",
             uint64_t(fapi2::current_err), mss::c_str(i_target));
    fapi2::Assert(false);
    return false;
}

///
/// @brief ATTR_CHIP_EC_FEATURE_MCBIST_END_OF_RANK getter
/// @tparam T the fapi2 target type of the target
/// @param[in] const ref to the target
/// @return bool true iff feature is enabled
///
template< fapi2::TargetType T >
inline bool chip_ec_feature_mcbist_end_of_rank(const fapi2::Target<T>& i_target)
{
    const auto l_chip = mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_target);
    uint8_t l_value = 0;

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_MCBIST_END_OF_RANK, l_chip, l_value) );

    return l_value != 0;

fapi_try_exit:
    FAPI_ERR("failed accessing ATTR_CHIP_EC_FEATURE_MCBIST_END_OF_RANK: 0x%lx (target: %s)",
             uint64_t(fapi2::current_err), mss::c_str(i_target));
    fapi2::Assert(false);
    return false;
}

///
/// @brief ATTR_CHIP_EC_FEATURE_MSS_WR_VREF getter
/// @tparam T the fapi2 target type of the target
/// @param[in] const ref to the target
/// @return bool true iff feature is enabled
///
template< fapi2::TargetType T >
inline bool chip_ec_feature_mss_wr_vref(const fapi2::Target<T>& i_target)
{
    const auto l_chip = mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_target);
    uint8_t l_value = 0;
    uint8_t l_do_value = 0;

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_MSS_WR_VREF, l_chip, l_value) );
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_DO_MSS_WR_VREF, l_chip, l_do_value) );

    return (l_value != 0) && (l_do_value == fapi2::ENUM_ATTR_DO_MSS_WR_VREF_YES);

fapi_try_exit:
    FAPI_ERR("failed accessing ATTR_CHIP_EC_FEATURE_MSS_WR_VREF or ATTR_DO_MSS_WR_VREF: 0x%lx (target: %s)",
             uint64_t(fapi2::current_err), mss::c_str(i_target));
    fapi2::Assert(false);
    return false;
}

///
/// @brief ATTR_CHIP_EC_FEATURE_MSS_DQS_POLARITY getter
/// @tparam T the fapi2 target type of the target
/// @param[in] const ref to the target
/// @return bool true iff feature is enabled
///
template< fapi2::TargetType T >
inline bool chip_ec_feature_mss_dqs_polarity(const fapi2::Target<T>& i_target)
{
    // Seeing better results with Monza and LaGrange by switching this off
    // TODO RTC:168029 - Remove DQS polarity EC feature if turning it off is a permanent fix.
#ifdef DO_POLARITY_WORKAROUND
    const auto l_chip = mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_target);
    uint8_t l_value = 0;

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_MSS_DQS_POLARITY, l_chip, l_value) );

    return l_value != 0;

fapi_try_exit:
    FAPI_ERR("failed accessing ATTR_CHIP_EC_FEATURE_MSS_DQS_POLARITY: 0x%lx (target: %s)",
             uint64_t(fapi2::current_err), mss::c_str(i_target));
    fapi2::Assert(false);
#endif

    return false;
}

///
/// @brief ATTR_CHIP_EC_FEATURE_MSS_VREF_DAC getter
/// @tparam T the fapi2 target type of the target
/// @param[in] const ref to the target
/// @return bool true iff feature is enabled
///
template< fapi2::TargetType T >
inline bool chip_ec_feature_mss_vref_dac(const fapi2::Target<T>& i_target)
{
    const auto l_chip = mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_target);
    uint8_t l_value = 0;
    uint8_t l_do_value = 0;

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_MSS_VREF_DAC, l_chip, l_value) );
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_DO_MSS_VREF_DAC, l_chip, l_do_value) );

    return (l_value != 0) && (l_do_value == fapi2::ENUM_ATTR_DO_MSS_VREF_DAC_YES);

fapi_try_exit:
    FAPI_ERR("failed accessing ATTR_CHIP_EC_FEATURE_MSS_VREF_DAC or ATTR_DO_MSS_VREF_DAC: 0x%lx (target: %s)",
             uint64_t(fapi2::current_err), mss::c_str(i_target));
    fapi2::Assert(false);
    return false;
}

///
/// @brief ATTR_CHIP_EC_FEATURE_MSS_WAT_DEBUG_ATTN getter
/// @tparam T the fapi2 target type of the target
/// @param[in] const ref to the target
/// @return bool true iff feature is enabled
///
template< fapi2::TargetType T >
inline bool chip_ec_feature_mss_wat_debug_attn(const fapi2::Target<T>& i_target)
{
    const auto l_chip = mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_target);
    uint8_t l_value = 0;

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_MSS_WAT_DEBUG_ATTN, l_chip, l_value) );

    return l_value != 0;

fapi_try_exit:
    FAPI_ERR("failed accessing ATTR_CHIP_EC_FEATURE_MSS_WAT_DEBUG_ATTN: 0x%lx (target: %s)",
             uint64_t(fapi2::current_err), mss::c_str(i_target));
    fapi2::Assert(false);
    return false;
}

///
/// @brief ATTR_CHIP_EC_FEATURE_MSS_TRAINING_BAD_BITS getter
/// @tparam T the fapi2 target type of the target
/// @param[in] const ref to the target
/// @return bool true iff feature is enabled
///
template< fapi2::TargetType T >
inline bool chip_ec_feature_mss_training_bad_bits(const fapi2::Target<T>& i_target)
{
    // TODO RTC:168964 Enable training bad bits workaround at appropriate EC levels
    // Running dirty until we know what EC major & minor number we want to add this to.

#ifdef ALWAYS_DO_TRAINING_BAD_BITS_WORKAROUND
    const auto l_chip = mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_target);
    uint8_t l_value = 0;
    uint8_t l_do_value = 0;

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_MSS_TRAINING_BAD_BITS, l_chip, l_value) );
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_DO_MSS_TRAINING_BAD_BITS, l_chip, l_do_value) );

    return (l_value != 0) && (l_do_value == fapi2::ENUM_ATTR_DO_MSS_TRAINING_BAD_BITS_YES);

fapi_try_exit:
    FAPI_ERR("failed accessing ATTR_CHIP_EC_FEATURE_MSS_TRAINING_BAD_BITS"
             " or ATTR_DO_MSS_TRAINING_BAD_BITS: 0x%lx (target: %s)",
             uint64_t(fapi2::current_err), mss::c_str(i_target));
    fapi2::Assert(false);
    return false;
#else
    return true;
#endif
}

///
/// @brief ATTR_CHIP_EC_FEATURE_MSS_BLUE_WATERFALL_ADJUST getter
/// @tparam T the fapi2 target type of the target
/// @param[in] const ref to the target
/// @return bool true iff feature is enabled
///
template< fapi2::TargetType T >
inline bool chip_ec_feature_blue_waterfall_adjust(const fapi2::Target<T>& i_target)
{
    const auto l_chip = mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_target);
    uint8_t l_value = 0;
    uint8_t l_do_value = 0;

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_MSS_BLUE_WATERFALL_ADJUST, l_chip, l_value) );
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_DO_BLUE_WATERFALL_ADJUST, l_chip, l_do_value) );

    return (l_value != 0) && (l_do_value == fapi2::ENUM_ATTR_DO_BLUE_WATERFALL_ADJUST_YES);

fapi_try_exit:
    FAPI_ERR("failed accessing ATTR_CHIP_EC_FEATURE_MSS_BLUE_WATERFALL_ADJUST or ATTR_DO_BLUE_WATERFALL_ADJUST: 0x%lx (target: %s)",
             uint64_t(fapi2::current_err), mss::c_str(i_target));
    fapi2::Assert(false);
    return false;
}

///
/// @brief ATTR_CHIP_EC_FEATURE_MSS_ENABLE_HW_VREF_CAL getter
/// @tparam T the fapi2 target type of the target
/// @param[in] const ref to the target
/// @return bool true iff feature is enabled
///
template< fapi2::TargetType T >
inline bool chip_ec_feature_skip_hw_vref_cal(const fapi2::Target<T>& i_target)
{
    const auto l_chip = mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_target);
    uint8_t l_chip_check = 0;
    uint8_t l_skip_check = 0;
    uint8_t l_sim = 0;

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_MSS_CHECK_DISABLE_HW_VREF_CAL, l_chip, l_chip_check) );
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_SKIP_HW_VREF_CAL, l_chip, l_skip_check) );
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_sim) );

    FAPI_DBG("Values of the attributes for HW VREF cal skip chip: %d skip: %d", l_chip_check, l_skip_check);

    // Chip check is required   && we're in the HW sub-revision where the skip is required - then set a skip value
    // Skips if we are in sim mode - VREF cal takes too long for simulation
    return l_sim || ((l_chip_check != 0) && (l_skip_check != 0));

fapi_try_exit:
    FAPI_ERR("failed accessing ATTR_SKIP_HW_VREF_CAL or ATTR_CHIP_EC_FEATURE_MSS_CHECK_DISABLE_HW_VREF_CAL: 0x%lx (target: %s)",
             uint64_t(fapi2::current_err), mss::c_str(i_target));
    fapi2::Assert(false);
    return false;
}

///
/// @brief ATTR_CHIP_EC_FEATURE_MSS_ODT_CONFIG getter
/// @tparam T the fapi2 target type of the target
/// @param[in] const ref to the target
/// @return bool true iff feature is enabled
///
template< fapi2::TargetType T >
inline bool chip_ec_feature_mss_odt_config(const fapi2::Target<T>& i_target)
{
    const auto l_chip = mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_target);
    uint8_t l_value = 0;

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_MSS_ODT_CONFIG, l_chip, l_value) );

    return l_value != 0;

fapi_try_exit:
    FAPI_ERR("failed accessing ATTR_CHIP_EC_FEATURE_MSS_ODT_CONFIG: 0x%lx (target: %s)",
             uint64_t(fapi2::current_err), mss::c_str(i_target));
    fapi2::Assert(false);
    return false;
}

///
/// @brief ATTR_SKIP_RD_VREF_VREFSENSE_OVERRIDE getter
/// @tparam T the fapi2 target type of the target
/// @param[in] const ref to the target
/// @return bool true iff feature is enabled
///
template< fapi2::TargetType T >
inline bool chip_ec_feature_skip_rd_vref_vrefsense_override(const fapi2::Target<T>& i_target)
{
    const auto l_chip = mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_target);
    uint8_t l_chip_check = 0;
    uint8_t l_skip_check = 0;
    uint8_t l_sim = 0;

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_MSS_CHECK_DIABLE_RD_VREF_CAL_VREFSENSE, l_chip, l_chip_check) );
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_SKIP_RD_VREF_VREFSENSE_OVERRIDE, l_chip, l_skip_check) );
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_sim) );

    FAPI_DBG("Values of the attributes VREFSENSE chip: %d skip: %d", l_chip_check, l_skip_check);

    // Chip check is required   && we're in the HW sub-revision where the skip is required - then set a skip value
    // Skips if we are in sim mode - VREF cal takes too long for simulation
    return l_sim || ((l_chip_check != 0) && (l_skip_check != 0));

fapi_try_exit:
    FAPI_ERR("failed accessing ATTR_SKIP_RD_VREF_VREFSENSE_OVERRIDE or ATTR_CHIP_EC_FEATURE_MSS_CHECK_DIABLE_RD_VREF_CAL_VREFSENSE: 0x%lx (target: %s)",
             uint64_t(fapi2::current_err), mss::c_str(i_target));
    fapi2::Assert(false);
    return false;
}

} // close mss namespace

#endif
