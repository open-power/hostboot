/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/power_thermal/decoder.C $ */
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
/// @file decoder.C
/// @brief Decode MSS_MRW_PWR_CURVE_SLOPE, PWR_CURVE_INTERCEPT, and THERMAL_POWER_LIMIT
///
// *HWP HWP Owner: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

// fapi2
#include <fapi2.H>
#include <vector>
#include <utility>

// mss lib
#include <mss.H>
#include <lib/power_thermal/throttle.H>
#include <lib/power_thermal/decoder.H>
#include <lib/utils/find.H>
#include <c_str.H>
#include <lib/utils/count_dimm.H>
#include <lib/dimm/kind.H>


using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_DIMM;
using fapi2::TARGET_TYPE_MCBIST;

namespace mss
{
namespace power_thermal
{

///
/// @brief generates the 32 bit encoding for the power curve attributes
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff the encoding was successful
/// @note populates iv_gen_keys
///
fapi2::ReturnCode decoder::generate_encoding()
{
    //DIMM_SIZE
    FAPI_TRY(( encode<DIMM_SIZE_START, DIMM_SIZE_LEN>
               (iv_kind.iv_target, iv_kind.iv_size, DIMM_SIZE_MAP, iv_gen_key)),
             "Failed to generate power thermal encoding for %s val %d on target: %s",
             "DIMM_SIZE", iv_kind.iv_size, c_str(iv_kind.iv_target) );

    //DRAM_GEN
    FAPI_TRY(( encode<DRAM_GEN_START, DRAM_GEN_LEN>
               (iv_kind.iv_target, iv_kind.iv_dram_generation, DRAM_GEN_MAP, iv_gen_key)),
             "Failed to generate power thermal encoding for %s val %d on target: %s",
             "DRAM_GEN", iv_kind.iv_dram_generation, c_str(iv_kind.iv_target) );

    //DIMM_TYPE
    FAPI_TRY(( encode<DIMM_TYPE_START, DIMM_TYPE_LEN>
               (iv_kind.iv_target, iv_kind.iv_dimm_type, DIMM_TYPE_MAP, iv_gen_key)),
             "Failed to generate power thermal encoding for %s val %d on target: %s",
             "DIMM_TYPE", iv_kind.iv_dimm_type, c_str(iv_kind.iv_target) );

    //DRAM WIDTH
    FAPI_TRY(( encode<DRAM_WIDTH_START, DRAM_WIDTH_LEN>
               (iv_kind.iv_target, iv_kind.iv_dram_width, DRAM_WIDTH_MAP, iv_gen_key)),
             "Failed to generate power thermal encoding for %s val %d on target: %s",
             "DRAM_WIDTH", iv_kind.iv_dram_width, c_str(iv_kind.iv_target) );

    //DRAM DENSITY
    FAPI_TRY(( encode<DRAM_DENSITY_START, DRAM_DENSITY_LEN>
               (iv_kind.iv_target, iv_kind.iv_dram_density, DRAM_DENSITY_MAP, iv_gen_key)),
             "Failed to generate power thermal encoding for %s val %d on target: %s",
             "DRAM_DENSITY", iv_kind.iv_dram_density, c_str(iv_kind.iv_target) );

    //DRAM STACK TYPE
    FAPI_TRY(( encode<DRAM_STACK_TYPE_START, DRAM_STACK_TYPE_LEN>
               (iv_kind.iv_target, iv_kind.iv_stack_type, DRAM_STACK_TYPE_MAP, iv_gen_key)),
             "Failed to generate power thermal encoding for %s val %d on target: %s",
             "DRAM_STACK_TYPE", iv_kind.iv_stack_type, c_str(iv_kind.iv_target) );

    //DRAM MFG ID
    FAPI_TRY(( encode<DRAM_MFGID_START, DRAM_MFGID_LEN>
               (iv_kind.iv_target, iv_kind.iv_mfgid, DRAM_MFGID_MAP, iv_gen_key)),
             "Failed to generate power thermal encoding for %s val %d on target: %s",
             "DRAM_MFG_ID", iv_kind.iv_mfgid, c_str(iv_kind.iv_target) );

    //NUM DROPS PER PORT
    FAPI_TRY(( encode<DIMMS_PER_PORT_START, DIMMS_PER_PORT_LEN>
               (iv_kind.iv_target, iv_dimms_per_port, DIMMS_PORT_MAP, iv_gen_key)),
             "Failed to generate power thermal encoding for %s val %d on target: %s",
             "DIMMS_PER_PORT", iv_dimms_per_port, c_str(iv_kind.iv_target) );

fapi_try_exit:
    return fapi2::current_err;
}
///
///@brief a compare functor for the decoder::find_attr functions below
///@note AND's the input hash with the generated hash from the DIMM to see if they match
///@note Using an AND instead of == because not all DIMM configs have power slopes, so defaults are needed
///
struct is_match
{
    ///
    ///@brief functor constructor
    ///@param[in] i_gen_key the class object's constructed hash for the installed dimm, to be compared with the attr array
    ///
    is_match(const fapi2::buffer<uint32_t> i_gen_key) : iv_gen_key(i_gen_key) {}
    const fapi2::buffer<uint32_t> iv_gen_key;

    ///
    ///@brief Boolean compare used for find_if function
    ///
    bool operator()(const fapi2::buffer<uint64_t> i_hash)
    {
        uint32_t l_temp = 0;
        i_hash.extractToRight<ENCODING_START, ENCODING_LENGTH>(l_temp);
        return ((l_temp & iv_gen_key) == iv_gen_key);
    }
};

///
/// @brief Finds a value for the power curve slope attributes by matching the generated hashes
/// @param[in] i_slope vector of generated key-values from POWER_CURVE_SLOPE
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff the encoding was successful
/// @note populates iv_vddr_slope, iv_total_slop
///
fapi2::ReturnCode decoder::find_slope (const std::vector<fapi2::buffer<uint64_t>>& i_slope)
{
    // Find iterator to matching key (if it exists)
    const auto l_value_iterator  =  std::find_if(i_slope.begin(),
                                    i_slope.end(),
                                    is_match(iv_gen_key));

    //Should have matched with the default ATTR value at least
    //The last value should always be the default value
    FAPI_ASSERT(l_value_iterator != i_slope.end(),
                fapi2::MSS_NO_POWER_THERMAL_ATTR_FOUND()
                .set_GENERATED_KEY(iv_gen_key),
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

    l_value_iterator->extractToRight<VDDR_START, VDDR_LENGTH>( iv_vddr_slope);
    l_value_iterator->extractToRight<TOTAL_START, TOTAL_LENGTH>(iv_total_slope);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Finds a value for power curve intercept attributes by matching the generated hashes
/// @param[in] i_intercept vector of generated key-values for ATTR_MSS_MRW_POWER_CURVE_INTERCEPT
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff the encoding was successful
/// @note populates iv_vddr_intercept, iv_total_intercept
///
fapi2::ReturnCode decoder::find_intercept (const std::vector<fapi2::buffer<uint64_t>>& i_intercept)
{
    // Find iterator to matching key (if it exists)
    const auto l_value_iterator  =  std::find_if(i_intercept.begin(),
                                    i_intercept.end(),
                                    is_match(iv_gen_key));

    //Should have matched with the all default ATTR at least
    //The last value should always be the default value
    FAPI_ASSERT(l_value_iterator != i_intercept.end(),
                fapi2::MSS_NO_POWER_THERMAL_ATTR_FOUND()
                .set_GENERATED_KEY(iv_gen_key),
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

    l_value_iterator->extractToRight<VDDR_START, VDDR_LENGTH>( iv_vddr_intercept);
    l_value_iterator->extractToRight<TOTAL_START, TOTAL_LENGTH>(iv_total_intercept);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Finds a value from ATTR_MSS_MRW_THERMAL_MEMORY_POWER_LIMIT and stores in iv variable
/// @param[in] i_thermal_limits is a vector of the generated values from ATTR_MSS_MRW_THERMAL_POWER_LIMIT
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff the encoding was successful
/// @note populates thermal_power_limit
///
fapi2::ReturnCode decoder::find_thermal_power_limit (const std::vector<fapi2::buffer<uint64_t>>& i_thermal_limits)
{
    // Find iterator to matching key (if it exists)
    const auto l_value_iterator  =  std::find_if(i_thermal_limits.begin(),
                                    i_thermal_limits.end(),
                                    is_match(iv_gen_key));

    //Should have matched with the all default ATTR at least
    //The last value should always be the default value
    FAPI_ASSERT(l_value_iterator != i_thermal_limits.end(),
                fapi2::MSS_NO_POWER_THERMAL_ATTR_FOUND()
                .set_GENERATED_KEY(iv_gen_key),
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

    l_value_iterator->extractToRight<THERMAL_POWER_START, THERMAL_POWER_LENGTH>( iv_thermal_power_limit);

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
                                   const std::vector< fapi2::buffer< uint64_t > >& i_slope,
                                   const std::vector< fapi2::buffer< uint64_t > >& i_intercept,
                                   const std::vector< fapi2::buffer< uint64_t > >& i_thermal_power_limit,
                                   uint16_t o_vddr_slope [PORTS_PER_MCS][MAX_DIMM_PER_PORT],
                                   uint16_t o_vddr_int [PORTS_PER_MCS][MAX_DIMM_PER_PORT],
                                   uint16_t o_total_slope[PORTS_PER_MCS][MAX_DIMM_PER_PORT],
                                   uint16_t o_total_int [PORTS_PER_MCS][MAX_DIMM_PER_PORT],
                                   uint32_t o_thermal_power [PORTS_PER_MCS][MAX_DIMM_PER_PORT])
{
    for (const auto& l_dimm : find_targets <fapi2::TARGET_TYPE_DIMM> (i_mcs))
    {
        const auto l_mca_pos = mss::index (find_target<TARGET_TYPE_MCA>(l_dimm));
        const auto l_dimm_pos = mss::index (l_dimm);

        mss::dimm::kind l_kind (l_dimm);
        mss::power_thermal::decoder l_decoder(l_kind);
        FAPI_TRY( l_decoder.generate_encoding() );

        // The first entry into these arrays must be valid
        // If we don't find any values, the attributes aren't found so go with some defaults
        if (i_slope.empty() || i_slope[0] == 0)
        {
            FAPI_INF("ATTR_MSS_MRW_PWR_SLOPE not found!!");
            o_vddr_slope [l_mca_pos][l_dimm_pos] = default_power::VDDR_SLOPE;
            o_total_slope [l_mca_pos][l_dimm_pos] = default_power::TOTAL_SLOPE;
        }
        else
        {
            FAPI_TRY( l_decoder.find_slope(i_slope) );
            o_vddr_slope [l_mca_pos][l_dimm_pos] = l_decoder.iv_vddr_slope;
            o_total_slope [l_mca_pos][l_dimm_pos] = l_decoder.iv_total_slope;
        }

        if (i_intercept.empty() || i_intercept[0] == 0)
        {
            FAPI_INF("ATTR_MSS_MRW_PWR_INTERCEPT not found!!");
            o_total_int [l_mca_pos][l_dimm_pos] = default_power::TOTAL_INT;
            o_vddr_int [l_mca_pos][l_dimm_pos] = default_power::VDDR_INT;
        }
        else
        {
            FAPI_TRY( l_decoder.find_intercept(i_intercept) );
            o_vddr_int [l_mca_pos][l_dimm_pos] = l_decoder.iv_vddr_intercept;
            o_total_int [l_mca_pos][l_dimm_pos] = l_decoder.iv_total_intercept;
        }

        if (i_thermal_power_limit.empty() || i_thermal_power_limit[0] == 0)
        {
            FAPI_INF("ATTR_MSS_MRW_THERMAL_MEMORY_POWER_LIMIT not found!!");
            o_thermal_power [l_mca_pos][l_dimm_pos] = default_power::THERMAL_LIMIT;
        }
        else
        {
            FAPI_TRY( l_decoder.find_thermal_power_limit(i_thermal_power_limit) );
            o_thermal_power [l_mca_pos][l_dimm_pos] = l_decoder.iv_thermal_power_limit;
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

} //ns power_thermal
} // ns mss
