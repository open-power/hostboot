/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/power_thermal/ody_decoder.C $ */
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

// EKB-Mirror-To: hostboot
///
/// @file ody_decoder.C
/// @brief Decode MRW attributes for DIMM power curves and power limits
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

// fapi2
#include <fapi2.H>
#include <vector>
#include <utility>

#include <lib/shared/ody_consts.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/dimm/kind.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <generic/memory/lib/utils/power_thermal/gen_decoder.H>
#include <lib/power_thermal/ody_throttle_traits.H>

namespace mss
{
namespace power_thermal
{

const std::vector< std::pair<uint8_t , uint8_t> > throttle_traits<mss::mc_type::ODYSSEY>::DIMM_TYPE_MAP =
{
    {fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_RDIMM, 0b000},
    {fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_UDIMM, 0b001},
    {fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_DDIMM, 0b011},
    {ANY_TYPE, 0b111}
};

const std::vector< std::pair<uint8_t , uint8_t> > throttle_traits<mss::mc_type::ODYSSEY>::DIMM_ATTACHED_MAP =
{
    {0, 0b00},
    {1, 0b01},
    {2, 0b10},
    {ANY_ATTACHED, 0b11},
};

///
/// @brief Finds a value for the power curve slope attributes by matching the generated hashes
/// @param[in] i_slope vector of generated key-values from MRW power curve attriutes
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff the encoding was successful
/// @note populates iv_vddr_slope, iv_total_slope
///
template<>
fapi2::ReturnCode decoder<mss::mc_type::ODYSSEY>::find_slope (
    const std::vector< const std::vector<uint64_t>* >& i_slope)
{
    using TT = throttle_traits<mss::mc_type::ODYSSEY>;

    // For odyssey, two attribute are used to get slope (i_slope[0], i_slope[1])
    //   ATTR_MSS_MRW_OCMB_PWR_SLOPE is for thermal power slope
    //   ATTR_MSS_MRW_OCMB_CURRENT_CURVE_WITH_LIMIT is for power slope
    FAPI_ASSERT(i_slope.size() == 2,
                fapi2::MSS_POWER_THERMAL_ATTR_VECTORS_INCORRECT()
                .set_FUNCTION(SLOPE)
                .set_INPUT_SIZE(i_slope.size())
                .set_EXPECTED_SIZE(2),
                "The attributes vectors size is incorrect for find_slope input:%d, expected:%d",
                i_slope.size(),
                2);

    // To get thermal power slope
    FAPI_TRY( (get_power_thermal_value<TT::THERMAL_START, TT::THERMAL_LENGTH, SLOPE>(
                   *i_slope[0],
                   "ATTR_MSS_MRW_OCMB_PWR_SLOPE",
                   TT::DONT_DECODE_SAFE_MODE,
                   iv_total_slope)) );

    // To get power slope
    FAPI_TRY( (get_power_thermal_value<TT::POWER_SLOPE_START, TT::POWER_SLOPE_LENGTH, SLOPE>(
                   *i_slope[1],
                   "ATTR_MSS_MRW_OCMB_CURRENT_CURVE_WITH_LIMIT",
                   TT::DONT_DECODE_SAFE_MODE,
                   iv_vddr_slope)) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Finds a value for power curve intercept attributes by matching the generated hashes
/// @param[in] i_intercept vector of generated key-values from MRW power curve attributes
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff the encoding was successful
/// @note populates iv_vddr_intercept, iv_total_intercept
///
template<>
fapi2::ReturnCode decoder<mss::mc_type::ODYSSEY>::find_intercept (
    const std::vector< const std::vector<uint64_t>* >& i_intercept)
{
    using TT = throttle_traits<mss::mc_type::ODYSSEY>;

    // For odyssey, two attribute are used to get slope (i_slope[0], i_slope[1])
    //   ATTR_MSS_MRW_OCMB_PWR_INTERCEPT is for thermal power intercept
    //   ATTR_MSS_MRW_OCMB_CURRENT_CURVE_WITH_LIMIT is for power intercept
    FAPI_ASSERT(i_intercept.size() == 2,
                fapi2::MSS_POWER_THERMAL_ATTR_VECTORS_INCORRECT()
                .set_FUNCTION(INTERCEPT)
                .set_INPUT_SIZE(i_intercept.size())
                .set_EXPECTED_SIZE(2),
                "The attributes vectors size is incorrect for find_intercept input:%d, expected:%d",
                i_intercept.size(),
                2);

    // To get thermal power intercept
    FAPI_TRY( (get_power_thermal_value<TT::THERMAL_START, TT::THERMAL_LENGTH, INTERCEPT>(
                   *i_intercept[0],
                   "ATTR_MSS_MRW_OCMB_PWR_INTERCEPT",
                   TT::DONT_DECODE_SAFE_MODE,
                   iv_total_intercept)) );

    // To get power intercept
    FAPI_TRY( (get_power_thermal_value<TT::POWER_INTERCEPT_START, TT::POWER_INTERCEPT_LENGTH, INTERCEPT>(
                   *i_intercept[1],
                   "ATTR_MSS_MRW_OCMB_CURRENT_CURVE_WITH_LIMIT",
                   TT::DONT_DECODE_SAFE_MODE,
                   iv_vddr_intercept)) );

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Finds a value for the power limit attributes by matching the generated hashes
/// @param[in] i_thermal_limits is a vector of the generated values from MRW power limit attributes
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff the encoding was successful
/// @note populates iv_thermal_power_limit, iv_power_limit
///
template<>
fapi2::ReturnCode decoder<mss::mc_type::ODYSSEY>::find_thermal_power_limit (
    const std::vector< const std::vector<uint64_t>* >& i_thermal_limits)
{
    using TT = throttle_traits<mss::mc_type::ODYSSEY>;

    // For odyssey, two attribute are used to get slope (i_slope[0], i_slope[1])
    //   ATTR_MSS_MRW_OCMB_THERMAL_MEMORY_POWER_LIMIT is for thermal power limit
    //   ATTR_MSS_MRW_OCMB_CURRENT_CURVE_WITH_LIMIT is for power limit
    FAPI_ASSERT(i_thermal_limits.size() == 2,
                fapi2::MSS_POWER_THERMAL_ATTR_VECTORS_INCORRECT()
                .set_FUNCTION(INTERCEPT)
                .set_INPUT_SIZE(i_thermal_limits.size())
                .set_EXPECTED_SIZE(2),
                "The attributes vectors size is incorrect for find_thermal_power_limit input:%d, expected:%d",
                i_thermal_limits.size(),
                2);

    // To get thermal power limit
    FAPI_TRY( (get_power_thermal_value<TT::THERMAL_START, TT::THERMAL_LENGTH, POWER_LIMIT>(
                   *i_thermal_limits[0],
                   "ATTR_MSS_MRW_OCMB_THERMAL_MEMORY_POWER_LIMIT",
                   TT::DONT_DECODE_SAFE_MODE,
                   iv_thermal_power_limit)) );

    // To get regulator power or current limit
    FAPI_TRY( (get_power_thermal_value<TT::POWER_LIMIT_START, TT::POWER_LIMIT_LENGTH, POWER_LIMIT>(
                   *i_thermal_limits[1],
                   "ATTR_MSS_MRW_OCMB_CURRENT_CURVE_WITH_LIMIT",
                   TT::DONT_DECODE_SAFE_MODE,
                   iv_power_limit)) );

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief find the power curve attributes for each dimm on an MEM_PORT target
/// @param[in] i_throttle_type specifies whether this is for power or thermal throttling
/// @param[in] i_port vector of MEM_PORT targets on which dimm attrs will be set
/// @param[in] i_slope vector of generated hashes for encoding the values for memory power curve slopes
/// @param[in] i_intercept vector of generated hashes for encoding the values for memory power curve intercepts
/// @param[in] i_thermal_power_limit vector of generated hashes for encoding the values for memory power limits
/// @param[in] i_current_curve_with_limit vector of generated hashes for encoding the values for regulator power curves and limits
/// @param[in] i_safemode_throttles vector of generated hashes for safemode throttles array
/// @param[out] o_slope the power curve slope for each dimm
/// @param[out] o_intercept the power curve intercept for each dimm
/// @param[out] o_limit the power limit for the dimm
/// @param[out] o_safemode the safe mode throttle value for the dimm
/// @return FAPI2_RC_SUCCESS iff ok
/// @note used to set power curve attributes in calling function
/// @note decodes the attribute "encoding" to get the power curves and power limits for a dimm
///
template<>
fapi2::ReturnCode get_power_attrs<mss::mc_type::ODYSSEY> (const mss::throttle_type i_throttle_type,
        const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_port,
        const std::vector< uint64_t >& i_slope,
        const std::vector< uint64_t >& i_intercept,
        const std::vector< uint64_t >& i_thermal_power_limit,
        const std::vector< uint64_t >& i_current_curve_with_limit,
        const std::vector< uint64_t >& i_safemode_throttles,
        uint16_t o_slope [throttle_traits<mss::mc_type::ODYSSEY>::DIMMS_PER_PORT],
        uint16_t o_intercept [throttle_traits<mss::mc_type::ODYSSEY>::DIMMS_PER_PORT],
        uint32_t o_limit [throttle_traits<mss::mc_type::ODYSSEY>::DIMMS_PER_PORT],
        uint32_t& o_safemode)
{
    using TT = throttle_traits<mss::mc_type::ODYSSEY>;

    // get number of ports on ocmb - used later to split the safemode utilization across all ports
    const uint8_t l_port_count = mss::count_mem_port(mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_port));

    for (const auto& l_dimm : find_targets <fapi2::TARGET_TYPE_DIMM> (i_port))
    {
        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
        const auto l_dimm_pos = mss::index(l_dimm);
        mss::dimm::kind<mss::mc_type::ODYSSEY> l_kind(l_dimm, l_rc);
        FAPI_TRY(l_rc, "%s Failed to create dimm::kind instance", mss::c_str(l_dimm));
        mss::power_thermal::decoder<mss::mc_type::ODYSSEY> l_decoder(l_kind);
        fapi2::buffer<uint64_t> l_attr_value;

        // DDIMMs mrw slope/intercept/limit attribute values are for whole DDIMM, so divide these by total number of virtual DIMMs
        //   to get it to a DIMM level.  This will get the DIMM count to use in later calculations.
        // ISDIMMs use a value of 1 since mrw attribute values are at the DIMM level
        const uint8_t l_number_dimm_for_attr_value = (l_kind.iv_dimm_type == fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_DDIMM) ?
                mss::count_dimm(mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(l_dimm)) :
                1;

        FAPI_TRY( l_decoder.generate_encoding(TT::DONT_DECODE_SAFE_MODE), "Fail encountered while generating encodings on %s",
                  mss::c_str(l_dimm) );

        // The first entry into these arrays must be valid
        // If we don't find any values, the attributes aren't found so go with some defaults
        l_attr_value = i_slope[0];

        if (i_slope.empty() || !l_attr_value.getBit<TT::POWER_LIMIT_START, TT::POWER_LENGTH>())
        {
            FAPI_INF("%s ATTR_MSS_MRW_OCMB_PWR_SLOPE not found or has zero values", mss::c_str(l_dimm));

            o_slope[l_dimm_pos] =
                ((i_throttle_type == mss::throttle_type::POWER) ? TT::POWER_SLOPE : TT::TOTAL_SLOPE) /
                l_number_dimm_for_attr_value;
        }
        else
        {
            const std::vector< const std::vector<uint64_t>* > l_slope {&i_slope, &i_current_curve_with_limit};

            FAPI_TRY( l_decoder.find_slope(l_slope), "Fail encountered in find_slope on %s",
                      mss::c_str(l_dimm) );
            o_slope[l_dimm_pos] =
                ((i_throttle_type == mss::throttle_type::POWER) ? l_decoder.iv_vddr_slope : l_decoder.iv_total_slope) /
                l_number_dimm_for_attr_value;
        }

        l_attr_value = i_intercept[0];

        if (i_intercept.empty() || !l_attr_value.getBit<TT::POWER_LIMIT_START, TT::POWER_LENGTH>())
        {
            FAPI_INF("%s ATTR_MSS_MRW_OCMB_PWR_INTERCEPT not found or has zero values", mss::c_str(l_dimm));

            o_intercept[l_dimm_pos] =
                ((i_throttle_type == mss::throttle_type::POWER) ? TT::POWER_INT : TT::TOTAL_INT) /
                l_number_dimm_for_attr_value;
        }
        else
        {
            const std::vector< const std::vector<uint64_t>* > l_intercept {&i_intercept, &i_current_curve_with_limit};

            FAPI_TRY( l_decoder.find_intercept(l_intercept),
                      "Fail encountered in find_intercept on %s", mss::c_str(l_dimm) );

            o_intercept[l_dimm_pos] =
                ((i_throttle_type == mss::throttle_type::POWER) ? l_decoder.iv_vddr_intercept : l_decoder.iv_total_intercept) /
                l_number_dimm_for_attr_value;
        }

        l_attr_value = i_thermal_power_limit[0];

        if (i_thermal_power_limit.empty() || !l_attr_value.getBit<TT::THERMAL_START, TT::THERMAL_LENGTH>())
        {
            FAPI_INF("%s ATTR_MSS_MRW_OCMB_THERMAL_MEMORY_POWER_LIMIT not found or has zero values", mss::c_str(l_dimm));

            // The unit of limit and intercept is cA but limit is dA in mss::throttle_type::POWER
            // So we need to transfer them to the same unit
            o_limit[l_dimm_pos] =
                ((i_throttle_type == mss::throttle_type::POWER) ? TT::POWER_LIMIT* DECI_TO_CENTI : TT::THERMAL_LIMIT) /
                l_number_dimm_for_attr_value;
        }
        else
        {
            std::vector< const std::vector<uint64_t>* > l_thermal_power_limit {&i_thermal_power_limit, &i_current_curve_with_limit};

            FAPI_TRY( l_decoder.find_thermal_power_limit(l_thermal_power_limit),
                      "Fail encountered during find_thermal_power_limit on %s", mss::c_str(l_dimm) );
            // The unit of limit and intercept is cA but limit is dA in mss::throttle_type::POWER
            // So we need to transfer them to the same unit
            o_limit[l_dimm_pos] =
                ((i_throttle_type == mss::throttle_type::POWER) ?
                 l_decoder.iv_power_limit* DECI_TO_CENTI : l_decoder.iv_thermal_power_limit
                ) /
                l_number_dimm_for_attr_value;
        }

        l_attr_value = i_safemode_throttles[0];

        if (i_safemode_throttles.empty() || !l_attr_value.getBit<TT::DIMM_COUNT_START, TT::DIMM_COUNT_LEN>())
        {
            FAPI_INF("%s ATTR_MSS_MRW_OCMB_SAFEMODE_UTIL_ARRAY not found or has zero values", mss::c_str(l_dimm));
            o_safemode = TT::SAFEMODE_THROTTLE_DEFAULT;
        }
        else
        {
            mss::power_thermal::decoder<mss::mc_type::ODYSSEY> l_decoder_safemode(l_kind);

            FAPI_TRY( l_decoder_safemode.generate_encoding(TT::DECODE_SAFE_MODE),
                      "Fail encountered while generating encodings on %s", mss::c_str(l_dimm) );
            FAPI_TRY( (l_decoder_safemode.get_power_thermal_value<TT::SAFEMODE_START, TT::SAFEMODE_LENGTH, SAFEMODE>(
                           i_safemode_throttles,
                           "ATTR_MSS_MRW_OCMB_SAFEMODE_UTIL_ARRAY",
                           TT::DECODE_SAFE_MODE,
                           o_safemode)) );

            // safemode utilization is for OCMB, so split it across ports
            if (l_port_count >= 1)
            {
                o_safemode = o_safemode / l_port_count;
            }
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}
} //ns power_thermal
} // ns mss
