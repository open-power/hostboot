/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/mss_attribute_accessors_manual.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
// *HWP HWP Backup: Steven Glancy <sglancy@usi.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory

#ifndef MSS_ATTR_ACCESS_MANUAL_H_
#define MSS_ATTR_ACCESS_MANUALH_

#include <fapi2.H>
#include <lib/utils/find.H>

namespace mss
{

///
/// @brief ATTR_CHIP_EC_FEATURE_MSS_UT_EC_NIMBUS_LESS_THAN_TWO_OH getter
/// @tparam T the fapi2 target type of the target
/// @param[in] const ref to the target
/// @param[out] uint8_t& reference to store the value
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
/// @param[out] uint8_t& reference to store the value
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
/// @param[out] uint8_t& reference to store the value
/// @return bool true iff feature is enabled
///
template< fapi2::TargetType T >
inline bool chip_ec_feature_mss_wr_vref(const fapi2::Target<T>& i_target)
{
    const auto l_chip = mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_target);
    uint8_t l_value = 0;

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_MSS_WR_VREF, l_chip, l_value) );

    return l_value != 0;

fapi_try_exit:
    FAPI_ERR("failed accessing ATTR_CHIP_EC_FEATURE_MSS_WR_VREF: 0x%lx (target: %s)",
             uint64_t(fapi2::current_err), mss::c_str(i_target));
    fapi2::Assert(false);
    return false;
}

///
/// @brief ATTR_CHIP_EC_FEATURE_MSS_DQS_POLARITY getter
/// @tparam T the fapi2 target type of the target
/// @param[in] const ref to the target
/// @param[out] uint8_t& reference to store the value
/// @return bool true iff feature is enabled
///
template< fapi2::TargetType T >
inline bool chip_ec_feature_mss_dqs_polarity(const fapi2::Target<T>& i_target)
{
    const auto l_chip = mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_target);
    uint8_t l_value = 0;

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_MSS_DQS_POLARITY, l_chip, l_value) );

    return l_value != 0;

fapi_try_exit:
    FAPI_ERR("failed accessing ATTR_CHIP_EC_FEATURE_MSS_DQS_POLARITY: 0x%lx (target: %s)",
             uint64_t(fapi2::current_err), mss::c_str(i_target));
    fapi2::Assert(false);
    return false;
}

///
/// @brief ATTR_CHIP_EC_FEATURE_MSS_VCCD_OVERRIDE getter
/// @tparam T the fapi2 target type of the target
/// @param[in] const ref to the target
/// @param[out] uint8_t& reference to store the value
/// @return bool true iff feature is enabled
///
template< fapi2::TargetType T >
inline bool chip_ec_feature_mss_vccd_override(const fapi2::Target<T>& i_target)
{
    const auto l_chip = mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_target);
    uint8_t l_value = 0;

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_MSS_VCCD_OVERRIDE, l_chip, l_value) );

    return l_value != 0;

fapi_try_exit:
    FAPI_ERR("failed accessing ATTR_CHIP_EC_FEATURE_MSS_VCCD_OVERRIDE: 0x%lx (target: %s)",
             uint64_t(fapi2::current_err), mss::c_str(i_target));
    fapi2::Assert(false);
    return false;
}

///
/// @brief ATTR_CHIP_EC_FEATURE_MSS_VREF_DAC getter
/// @tparam T the fapi2 target type of the target
/// @param[in] const ref to the target
/// @param[out] uint8_t& reference to store the value
/// @return bool true iff feature is enabled
///
template< fapi2::TargetType T >
inline bool chip_ec_feature_mss_vref_dac(const fapi2::Target<T>& i_target)
{
    const auto l_chip = mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_target);
    uint8_t l_value = 0;

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_MSS_VREF_DAC, l_chip, l_value) );

    return l_value != 0;

fapi_try_exit:
    FAPI_ERR("failed accessing ATTR_CHIP_EC_FEATURE_MSS_VREF_DAC: 0x%lx (target: %s)",
             uint64_t(fapi2::current_err), mss::c_str(i_target));
    fapi2::Assert(false);
    return false;
}

///
/// @brief ATTR_CHIP_EC_FEATURE_MSS_VREG_COARSE getter
/// @tparam T the fapi2 target type of the target
/// @param[in] const ref to the target
/// @param[out] uint8_t& reference to store the value
/// @return bool true iff feature is enabled
///
template< fapi2::TargetType T >
inline bool chip_ec_feature_mss_vreg_coarse(const fapi2::Target<T>& i_target)
{
    const auto l_chip = mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_target);
    uint8_t l_value = 0;

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_MSS_VREG_COARSE, l_chip, l_value) );

    return l_value != 0;

fapi_try_exit:
    FAPI_ERR("failed accessing ATTR_CHIP_EC_FEATURE_MSS_VREG_COARSE: 0x%lx (target: %s)",
             uint64_t(fapi2::current_err), mss::c_str(i_target));
    fapi2::Assert(false);
    return false;
}

///
/// @brief ATTR_CHIP_EC_FEATURE_MSS_TRAINING_BAD_BITS getter
/// @tparam T the fapi2 target type of the target
/// @param[in] const ref to the target
/// @param[out] uint8_t& reference to store the value
/// @return bool true iff feature is enabled
///
template< fapi2::TargetType T >
inline bool chip_ec_feature_mss_training_bad_bits(const fapi2::Target<T>& i_target)
{
    // TODO RTC:165862 - need to get the minor EC number and check that in here.
    const auto l_chip = mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_target);
    uint8_t l_value = 0;

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_MSS_TRAINING_BAD_BITS, l_chip, l_value) );

    return l_value != 0;

fapi_try_exit:
    FAPI_ERR("failed accessing ATTR_CHIP_EC_FEATURE_MSS_TRAINING_BAD_BITS: 0x%lx (target: %s)",
             uint64_t(fapi2::current_err), mss::c_str(i_target));
    fapi2::Assert(false);
    return false;
}


} // close mss namespace

#endif
