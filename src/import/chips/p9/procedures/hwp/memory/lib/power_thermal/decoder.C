/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/power_thermal/decoder.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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
/// @file decoder.C
/// @brief Decode MSS_MRW_PWR_CURVE_SLOPE, PWR_CURVE_INTERCEPT, and THERMAL_POWER_LIMIT
///
// *HWP HWP Owner: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <lib/shared/nimbus_defaults.H>
#include <lib/dimm/mrs_traits_nimbus.H>
// fapi2
#include <fapi2.H>
#include <vector>
#include <utility>

// mss lib
#include <mss.H>
#include <lib/power_thermal/throttle.H>
#include <lib/power_thermal/decoder.H>
#include <lib/utils/nimbus_find.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <generic/memory/lib/utils/power_thermal/gen_decoder.H>
#include <lib/dimm/nimbus_kind.H>


namespace mss
{
namespace power_thermal
{

const std::vector< std::pair<uint8_t , uint8_t> > throttle_traits<mss::mc_type::NIMBUS>::DIMM_TYPE_MAP =
{
    {fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_RDIMM, 0b00},
    {fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_UDIMM, 0b01},
    {fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_LRDIMM, 0b10},
    {ANY_TYPE, 0b11}
};

///
/// @brief Finds a value for the power curve slope attributes by matching the generated hashes
/// @param[in] i_slope vector of generated key-values from POWER_CURVE_SLOPE
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff the encoding was successful
/// @note populates iv_vddr_slope, iv_total_slop
///
template<>
fapi2::ReturnCode decoder<mss::mc_type::NIMBUS>::find_slope (
    const std::vector< const std::vector<uint64_t>* >& i_slope)
{
    using TT = throttle_traits<mss::mc_type::NIMBUS>;

    // For nimbus only one attribute is used to get slope (i_slope[0])
    // Find iterator to matching key (if it exists)
    const auto l_value_iterator  =  std::find_if((*i_slope[0]).begin(),
                                    (*i_slope[0]).end(),
                                    is_match<>(iv_gen_key));

    //Should have matched with the default ATTR value at least
    //The last value should always be the default value
    FAPI_ASSERT(l_value_iterator != (*i_slope[0]).end(),
                fapi2::MSS_NO_POWER_THERMAL_ATTR_FOUND()
                .set_GENERATED_KEY(iv_gen_key)
                .set_FUNCTION(SLOPE)
                .set_DIMM_TARGET(iv_kind.iv_target)
                .set_SIZE(iv_kind.iv_size)
                .set_DRAM_GEN(iv_kind.iv_dram_generation)
                .set_DIMM_TYPE(iv_kind.iv_dimm_type)
                .set_DRAM_WIDTH( iv_kind.iv_dram_width)
                .set_DRAM_DENSITY(iv_kind.iv_dram_density)
                .set_STACK_TYPE(iv_kind.iv_stack_type)
                .set_MFGID(iv_kind.iv_mfgid),
                "Couldn't find %s value for generated key:%08lx, for target %s. "
                "DIMM values for generated key are "
                "size is %d, gen is %d, type is %d, width is %d, density %d, stack %d, mfgid %d, dimms %d",
                "ATTR_MSS_MRW_POWER_CURVE_SLOPE",
                iv_gen_key,
                mss::c_str(iv_kind.iv_target),
                iv_kind.iv_size,
                iv_kind.iv_dram_generation,
                iv_kind.iv_dimm_type,
                iv_kind.iv_dram_width,
                iv_kind.iv_dram_density,
                iv_kind.iv_stack_type,
                iv_kind.iv_mfgid,
                iv_dimms_per_port);

    {
        const fapi2::buffer<uint64_t> l_temp(*l_value_iterator);
        l_temp.extractToRight<TT::VDDR_START, TT::VDDR_LENGTH>( iv_vddr_slope);
        l_temp.extractToRight<TT::TOTAL_START, TT::TOTAL_LENGTH>(iv_total_slope);
    }
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Finds a value for power curve intercept attributes by matching the generated hashes
/// @param[in] i_intercept vector of generated key-values for ATTR_MSS_MRW_POWER_CURVE_INTERCEPT
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff the encoding was successful
/// @note populates iv_vddr_intercept, iv_total_intercept
///
template<>
fapi2::ReturnCode decoder<mss::mc_type::NIMBUS>::find_intercept (
    const std::vector< const std::vector<uint64_t>* >& i_intercept)
{
    using TT = throttle_traits<mss::mc_type::NIMBUS>;

    // Find iterator to matching key (if it exists)
    const auto l_value_iterator  =  std::find_if((*i_intercept[0]).begin(),
                                    (*i_intercept[0]).end(),
                                    is_match<>(iv_gen_key));
    //Should have matched with the all default ATTR at least
    //The last value should always be the default value
    FAPI_ASSERT(l_value_iterator != (*i_intercept[0]).end(),
                fapi2::MSS_NO_POWER_THERMAL_ATTR_FOUND()
                .set_GENERATED_KEY(iv_gen_key)
                .set_FUNCTION(INTERCEPT)
                .set_DIMM_TARGET(iv_kind.iv_target)
                .set_SIZE(iv_kind.iv_size)
                .set_DRAM_GEN(iv_kind.iv_dram_generation)
                .set_DIMM_TYPE(iv_kind.iv_dimm_type)
                .set_DRAM_WIDTH( iv_kind.iv_dram_width)
                .set_DRAM_DENSITY(iv_kind.iv_dram_density)
                .set_STACK_TYPE(iv_kind.iv_stack_type)
                .set_MFGID(iv_kind.iv_mfgid),
                "Couldn't find %s value for generated key:%08lx, for target %s. "
                "DIMM values for generated key are "
                "size is %d, gen is %d, type is %d, width is %d, density %d, stack %d, mfgid %d, dimms %d",
                "ATTR_MSS_MRW_POWER_CURVE_INTERCEPT",
                iv_gen_key,
                mss::c_str(iv_kind.iv_target),
                iv_kind.iv_size,
                iv_kind.iv_dram_generation,
                iv_kind.iv_dimm_type,
                iv_kind.iv_dram_width,
                iv_kind.iv_dram_density,
                iv_kind.iv_stack_type,
                iv_kind.iv_mfgid,
                iv_dimms_per_port);

    {
        const fapi2::buffer<uint64_t> l_temp(*l_value_iterator);
        l_temp.extractToRight<TT::VDDR_START, TT::VDDR_LENGTH>( iv_vddr_intercept);
        l_temp.extractToRight<TT::TOTAL_START, TT::TOTAL_LENGTH>(iv_total_intercept);
    }
fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Finds a value from ATTR_MSS_MRW_THERMAL_MEMORY_POWER_LIMIT and stores in iv variable
/// @param[in] i_thermal_limits is a vector of the generated values from ATTR_MSS_MRW_THERMAL_POWER_LIMIT
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff the encoding was successful
/// @note populates thermal_power_limit.
///
template<>
fapi2::ReturnCode decoder<mss::mc_type::NIMBUS>::find_thermal_power_limit (
    const std::vector< const std::vector<uint64_t>* >& i_thermal_limits)
{
    using TT = throttle_traits<mss::mc_type::NIMBUS>;

    // Find iterator to matching key (if it exists)
    const auto l_value_iterator  =  std::find_if((*i_thermal_limits[0]).begin(),
                                    (*i_thermal_limits[0]).end(),
                                    is_match<>(iv_gen_key));

    fapi2::buffer<uint64_t> l_temp;

    //Should have matched with the all default ATTR at least
    //The last value should always be the default value
    FAPI_ASSERT(l_value_iterator != (*i_thermal_limits[0]).end(),
                fapi2::MSS_NO_POWER_THERMAL_ATTR_FOUND()
                .set_GENERATED_KEY(iv_gen_key)
                .set_FUNCTION(POWER_LIMIT)
                .set_DIMM_TARGET(iv_kind.iv_target)
                .set_SIZE(iv_kind.iv_size)
                .set_DRAM_GEN(iv_kind.iv_dram_generation)
                .set_DIMM_TYPE(iv_kind.iv_dimm_type)
                .set_DRAM_WIDTH( iv_kind.iv_dram_width)
                .set_DRAM_DENSITY(iv_kind.iv_dram_density)
                .set_STACK_TYPE(iv_kind.iv_stack_type)
                .set_MFGID(iv_kind.iv_mfgid),
                "Couldn't find %s value for generated key:%8lx, for target %s. "
                "DIMM values for generated key are "
                "size is %d, gen is %d, type is %d, width is %d, density %d, stack %d, mfgid %d, dimms %d",
                "ATTR_MSS_MRW_THERMAL_POWER_LIMIT",
                iv_gen_key,
                mss::c_str(iv_kind.iv_target),
                iv_kind.iv_size,
                iv_kind.iv_dram_generation,
                iv_kind.iv_dimm_type,
                iv_kind.iv_dram_width,
                iv_kind.iv_dram_density,
                iv_kind.iv_stack_type,
                iv_kind.iv_mfgid,
                iv_dimms_per_port);

    {
        const fapi2::buffer<uint64_t> l_temp(*l_value_iterator);
        l_temp.extractToRight<TT::THERMAL_POWER_START, TT::THERMAL_POWER_LENGTH>( iv_thermal_power_limit);
    }
fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief find the power curve attributes for each dimm on an MCS target
/// @param[in] i_targets vector of MCS targets on which dimm attrs will be set
/// @param[in] i_slope vector of generated hashes for encoding and values for MSS_MRW_POWER_SLOPE
/// @param[in] i_intercept vector of generated hashes for encoding and values for MSS_MRW_POWER_INTERCEPT
/// @param[in] i_thermal_power_limit vector of generated hashes for encoding and values for MSS_MRW_THERMAL_MEMORY_POWER_LIMIT
/// @param[out] o_vddr_slope the VDDR power curve slope for each dimm
/// @param[out] o_vddr_int the VDDR power curve intercept for each dimm
/// @param[out] o_total_slope the VDDR+VPP power curve slope for each dimm
/// @param[out] o_total_int the VDDR+VPP power curve intercept for each dimm
/// @param[out] o_thermal_power the thermal power limit for the dimm
/// @return FAPI2_RC_SUCCESS iff ok
/// @note used to set power curve attributes in calling function
/// @note decodes the attribute "encoding" to get the vddr and vddr/vpp power curves for a dimm
///
fapi2::ReturnCode get_power_attrs (const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_mcs,
                                   const std::vector< uint64_t >& i_slope,
                                   const std::vector< uint64_t >& i_intercept,
                                   const std::vector< uint64_t >& i_thermal_power_limit,
                                   uint16_t o_vddr_slope [PORTS_PER_MCS][MAX_DIMM_PER_PORT],
                                   uint16_t o_vddr_int [PORTS_PER_MCS][MAX_DIMM_PER_PORT],
                                   uint16_t o_total_slope [PORTS_PER_MCS][MAX_DIMM_PER_PORT],
                                   uint16_t o_total_int [PORTS_PER_MCS][MAX_DIMM_PER_PORT],
                                   uint32_t o_thermal_power [PORTS_PER_MCS][MAX_DIMM_PER_PORT])
{
    using TT = throttle_traits<mss::mc_type::NIMBUS>;

    for (const auto& l_dimm : find_targets <fapi2::TARGET_TYPE_DIMM> (i_mcs))
    {
        const auto l_mca_pos = mss::index (find_target<fapi2::TARGET_TYPE_MCA>(l_dimm));
        const auto l_dimm_pos = mss::index (l_dimm);

        mss::dimm::kind<> l_kind (l_dimm);
        mss::power_thermal::decoder<> l_decoder(l_kind);
        FAPI_TRY( l_decoder.generate_encoding(), "%s Error in get_power_attrs", mss::c_str(i_mcs) );

        // The first entry into these arrays must be valid
        // If we don't find any values, the attributes aren't found so go with some defaults
        if (i_slope.empty() || i_slope[0] == 0)
        {
            FAPI_INF("%s ATTR_MSS_MRW_PWR_SLOPE not found!!", mss::c_str(i_mcs));
            o_vddr_slope [l_mca_pos][l_dimm_pos] = TT::VDDR_SLOPE;
            o_total_slope [l_mca_pos][l_dimm_pos] = TT::TOTAL_SLOPE;
        }
        else
        {
            const std::vector< const std::vector<uint64_t>* > l_slope {&i_slope};
            FAPI_TRY( l_decoder.find_slope(l_slope), "%s Error in get_power_attrs", mss::c_str(i_mcs) );
            o_vddr_slope [l_mca_pos][l_dimm_pos] = l_decoder.iv_vddr_slope;
            o_total_slope [l_mca_pos][l_dimm_pos] = l_decoder.iv_total_slope;
        }

        if (i_intercept.empty() || i_intercept[0] == 0)
        {
            FAPI_INF("%s ATTR_MSS_MRW_PWR_INTERCEPT not found!!", mss::c_str(i_mcs));
            o_total_int [l_mca_pos][l_dimm_pos] = TT::TOTAL_INT;
            o_vddr_int [l_mca_pos][l_dimm_pos] = TT::VDDR_INT;
        }
        else
        {
            std::vector< const std::vector<uint64_t>* > l_intercept {&i_intercept};
            FAPI_TRY( l_decoder.find_intercept(l_intercept), "%s Error in get_power_attrs", mss::c_str(i_mcs) );
            o_vddr_int [l_mca_pos][l_dimm_pos] = l_decoder.iv_vddr_intercept;
            o_total_int [l_mca_pos][l_dimm_pos] = l_decoder.iv_total_intercept;
        }

        if (i_thermal_power_limit.empty() || i_thermal_power_limit[0] == 0)
        {
            FAPI_INF("%s ATTR_MSS_MRW_THERMAL_MEMORY_POWER_LIMIT not found!!", mss::c_str(i_mcs));
            o_thermal_power [l_mca_pos][l_dimm_pos] = TT::THERMAL_LIMIT;
        }
        else
        {
            std::vector< const std::vector<uint64_t>* > l_thermal_power_limit {&i_thermal_power_limit};
            FAPI_TRY( l_decoder.find_thermal_power_limit(l_thermal_power_limit),
                      "%s Error in get_power_attrs", mss::c_str(i_mcs) );
            o_thermal_power [l_mca_pos][l_dimm_pos] = l_decoder.iv_thermal_power_limit;
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

} //ns power_thermal
} // ns mss
