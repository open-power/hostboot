/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/freq/mss_limit_freq_by_config.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2025                        */
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
/// @file mss_limit_freq_by_config.H
/// @brief Limits frequency based upon system memory configuration
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef MSS_LIMIT_FREQ_BY_CONFIG_H
#define MSS_LIMIT_FREQ_BY_CONFIG_H

#include <vector>
#include <fapi2.H>
#include <generic/memory/lib/utils/freq/gen_mss_freq_traits.H>
#include <generic/memory/lib/utils/pos.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/pos.H>
#include <generic/memory/lib/utils/memory_size.H>
#include <generic/memory/lib/utils/bit_count.H>

namespace mss
{

///
/// @brief Attribute key information for limiting the frequency based upon the configuration
///
enum config_attr_keys
{
    SIZE_32GB = 1,
    SIZE_64GB = 2,
    SIZE_128GB = 3,
    SIZE_256GB = 4,
    SIZE_512GB = 5,
    CONFIG_DIMM_SIZE_MAX = SIZE_512GB,
    CONFIG_DIMM_SIZE_MIN = SIZE_32GB,
    SIZE0_START = 0,
    SIZE1_START = BITS_PER_NIBBLE,

    NUM_DIMMS_16 = 1,
    NUM_DIMMS_24 = 2,
    NUM_DIMMS_32 = 3,
    NUM_DIMMS_40 = 4,
    NUM_DIMMS_48 = 5,
    NUM_DIMMS_56 = 6,
    MIN_NUM_DIMMS = 17,
    NUM_DIMMS_MAX = NUM_DIMMS_56,
    NUM_DIMMS_START = BITS_PER_NIBBLE * 2,

    FREQ_3200 = 1,
    FREQ_4000 = 2,
    FREQ_4800 = 3,
    CONFIG_FREQ_MAX = FREQ_4800,
    FREQ_START = BITS_PER_NIBBLE * 3,

    CONFIG_UNUSED = 0,
    ATTR_SIZE = 8,
    MAX_DIFFERENT_SIZES = 2,
    SIZE_KEY_COMPARISON_MASK  = 0xff00,
    DDIMM_KEY_COMPARISON_MASK = 0x00f0,
};

namespace check
{
///
/// @brief Checks if the MRW attribute is valid
/// @param[in] i_config_attr the configuration attribute values
/// @param[out] o_is_config_limit_needed true if checking the configuration limit is necessary
/// @return FAPI2_RC_SUCCESS iff ok
///
inline fapi2::ReturnCode mrw_config_attr_validity(const uint16_t (&i_config_attr)[config_attr_keys::ATTR_SIZE],
        bool& o_is_config_limit_needed)
{
    o_is_config_limit_needed = false;

    // Loops through and checks each attribute element
    for(uint8_t l_index = 0; l_index < config_attr_keys::ATTR_SIZE; ++l_index)
    {
        // An unused attribute value does not need to be checked
        if(i_config_attr[l_index] == config_attr_keys::CONFIG_UNUSED)
        {
            FAPI_DBG("index:%u has an unused config value (0). Skipping validity check", l_index);
            continue;
        }

        // There's a valid value, so the algorithm needs to be run
        o_is_config_limit_needed = true;
        FAPI_DBG("index:%u has has a config value of 0x%04x", l_index, i_config_attr[l_index]);

        uint8_t l_size0 = 0;
        uint8_t l_size1 = 0;
        uint8_t l_num_dimms = 0;
        uint8_t l_freq = 0;

        const fapi2::buffer<uint16_t> l_temp(i_config_attr[l_index]);
        l_temp.extractToRight<SIZE0_START, BITS_PER_NIBBLE>(l_size0)
        .extractToRight<SIZE1_START, BITS_PER_NIBBLE>(l_size1)
        .extractToRight<NUM_DIMMS_START, BITS_PER_NIBBLE>(l_num_dimms)
        .extractToRight<FREQ_START, BITS_PER_NIBBLE>(l_freq);

        const bool l_is_size0_good = (l_size0 != config_attr_keys::CONFIG_UNUSED)
                                     && (l_size0 <= config_attr_keys::CONFIG_DIMM_SIZE_MAX);
        const bool l_is_size1_good = (l_size1 < l_size0);
        const bool l_is_num_dimms_good = (l_num_dimms != config_attr_keys::CONFIG_UNUSED)
                                         && (l_num_dimms <= config_attr_keys::NUM_DIMMS_MAX);
        const bool l_is_freq_good = (l_freq != config_attr_keys::CONFIG_UNUSED)
                                    && (l_freq <= config_attr_keys::CONFIG_FREQ_MAX);

        FAPI_ASSERT(l_is_size0_good && l_is_size1_good && l_is_num_dimms_good && l_is_freq_good,
                    fapi2::INVALID_MRW_FREQ_LIMIT_BY_CONFIG_ATTR()
                    .set_INDEX(l_index)
                    .set_VALUE(i_config_attr[l_index]),
                    "ATTR_MSS_MRW_CONFIG_FREQ_LIMIT has an invalid value at index:%u. Value:0x%04x", l_index, i_config_attr[l_index]);
    }

    FAPI_DBG("Configuration check is %s", o_is_config_limit_needed ? "needed" : "being skipped");

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

} // ns check

///
/// @brief Updates the scoreboard for a passed in frequency across all ports
/// @tparam MC mss::mc_type memory controller type
/// @tparam P mss::proc_type on which to operate
/// @tparam TT Traits associated with the processor type
/// @param[in] i_target target for which to get the DIMM configs
/// @param[in] i_max_freq maximum frequency for this config
/// @param[in,out] io_scoreboard scoreboard of port targets supporting each frequency
/// @return FAPI2_RC_SUCCESS iff ok
///
template<mss::mc_type MC, mss::proc_type P, typename TT = mss::frequency_traits<P>>
fapi2::ReturnCode limit_freq_in_scoreboard(const fapi2::Target<TT::FREQ_DOMAIN_TARGET_TYPE>& i_target,
        const uint32_t i_max_freq,
        freq_scoreboard& io_scoreboard)
{
    for( const auto& p : mss::find_targets<TT::PORT_TARGET_TYPE>(i_target) )
    {
        const auto l_port_pos = mss::relative_pos<MC, TT::FREQ_DOMAIN_TARGET_TYPE>(p);

        // Remove any frequencies that aren't in this port's list from the scoreboard
        io_scoreboard.remove_freqs_above_limit(l_port_pos, i_max_freq);

        uint32_t l_current_max_freq = 0;
        FAPI_TRY( io_scoreboard.max_supported_freq(l_port_pos, l_current_max_freq) );
        FAPI_INF_NO_SBE("%s after processing memory configuration limit, max freq is %d", mss::c_str(p), l_current_max_freq);
    }// port

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Converts the DIMM capacity from an OCMB into the bit position/attribute encoding
/// @param[in] i_target OCMB chip target associated with this DIMM size
/// @param[in] i_dimm_size capacity of the DIMM in gigabytes
/// @param[out] o_bit_pos the bit position
/// @return FAPI2_RC_SUCCESS iff ok
///
inline fapi2::ReturnCode convert_dimm_size_to_bit_pos(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const uint64_t i_dimm_size,
        uint8_t& o_bit_pos)
{
    switch(i_dimm_size)
    {
        case fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_32GB:
            {
                o_bit_pos = SIZE_32GB;
                break;
            }

        case fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_64GB:
            {
                o_bit_pos = SIZE_64GB;
                break;
            }

        case fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_128GB:
            {
                o_bit_pos = SIZE_128GB;
                break;
            }

        case fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_256GB:
            {
                o_bit_pos = SIZE_256GB;
                break;
            }

        case fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_512GB:
            {
                o_bit_pos = SIZE_512GB;
                break;
            }

        default:
            FAPI_ASSERT(false,
                        fapi2::MSS_FREQ_INVALID_SIZE_ENCODE()
                        .set_OCMB_TARGET(i_target)
                        .set_SIZE(i_dimm_size),
                        "%s has an invalid DIMM size of %u", mss::c_str(i_target), i_dimm_size);
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Updates the system configuration based upon the OCMB's
/// @tparam MC mss::mc_type memory controller type
/// @param[in] i_target target for which to get the DIMM configs
/// @param[in,out] io_num_ocmbs the number of OCMBs on this frequency domain
/// @param[in,out] io_config the configuration encoding buffer
/// @return FAPI2_RC_SUCCESS iff ok
///
template<mss::mc_type MC>
fapi2::ReturnCode update_config_info(const std::vector<fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>>& i_targets,
                                     uint64_t& io_num_ocmbs,
                                     fapi2::buffer<uint8_t>& io_config)
{
    for(const auto& l_ocmb : i_targets)
    {
        ++io_num_ocmbs;
        uint64_t l_size = 0;
        FAPI_TRY(eff_memory_size<MC>( l_ocmb, l_size ));

        // Zero size is invalid for this algorithm
        // Note: this is counted as an OCMB
        if(l_size == 0)
        {
            FAPI_DBG("%s has no DIMM size. Skipping...", mss::c_str(l_ocmb));
            continue;
        }

        // Grabs the bit to set in the configuration buffer
        uint8_t l_size_bit = 0;
        FAPI_TRY(convert_dimm_size_to_bit_pos(l_ocmb, l_size, l_size_bit));
        FAPI_TRY(io_config.setBit(l_size_bit));
        FAPI_DBG("%s has a DIMM size of %u GB. Bit pos:%u. Whole config after update: 0x%02x", mss::c_str(l_ocmb), l_size,
                 l_size_bit, io_config);
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Assembles the key from the DIMM config and total number of DIMMs
/// @param[in] i_config the DIMM config
/// @param[in] i_num_ocmb the number of OCMB (aka DDIMM)
/// @param[out] o_key the computed key
/// @return FAPI2_RC_SUCCESS iff ok
///
inline fapi2::ReturnCode compute_config_key(const fapi2::buffer<uint8_t>& i_config,
        const uint64_t i_num_ocmb,
        fapi2::buffer<uint16_t>& o_key)
{
    // 8 OCMB per encodes with 16+ OCMB starting out at an encode of 1
    constexpr uint16_t OCMB_PER_ENCODE = 8;
    constexpr uint16_t ENCODE_DECREMENT = 1;
    o_key.flush<0>();

    uint16_t l_config_pos = 0;

    for(uint8_t l_bit_pos = config_attr_keys::CONFIG_DIMM_SIZE_MAX;
        l_bit_pos >= config_attr_keys::CONFIG_DIMM_SIZE_MIN;
        --l_bit_pos)
    {
        // The bit pos equals the config num
        if(i_config.getBit(l_bit_pos))
        {
            FAPI_TRY(o_key.insertFromRight(l_bit_pos, l_config_pos, BITS_PER_NIBBLE));
            l_config_pos += BITS_PER_NIBBLE;
        }
    }

    o_key.insertFromRight<config_attr_keys::NUM_DIMMS_START, BITS_PER_NIBBLE>(((i_num_ocmb - ENCODE_DECREMENT) /
            OCMB_PER_ENCODE) -
            ENCODE_DECREMENT);

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Checks if a key and attribute match
/// @param[in] i_attr the attribute value to check
/// @param[in] i_key the key to check
/// @return true if the key and attribute match
/// @note This does a direct compare on the configured DDIMMs and checks for the attribute being greater than or equal to the key
///
inline bool does_key_match_attr(const uint16_t i_attr, const uint16_t i_key)
{
    return (i_attr & config_attr_keys::SIZE_KEY_COMPARISON_MASK)  == (i_key & SIZE_KEY_COMPARISON_MASK) &&
           (i_attr & config_attr_keys::DDIMM_KEY_COMPARISON_MASK) <= (i_key & DDIMM_KEY_COMPARISON_MASK);
}

///
/// @brief Finds a matching configuration from a provided key
/// @param[in] i_config_attr the configuration attribute values
/// @param[in] i_key the key to check
/// @return The index for the attribute. ATTR_SIZE if not found
///
inline uint8_t find_attr_index_from_key(const uint16_t (&i_config_attr)[config_attr_keys::ATTR_SIZE],
                                        const fapi2::buffer<uint16_t>& i_key)
{
    uint8_t l_index = 0;

    // First up, get an approximate match
    // This is where the DDIMMs configured exactly match, but the number of DDIMMs could be off
    for(; l_index < config_attr_keys::ATTR_SIZE; ++l_index)
    {
        // Note: we look for an exact match on which DDIMM sizes are plugged in a system and a greater than or equal to on the number of DDIMMs
        if(does_key_match_attr(i_config_attr[l_index], i_key))
        {
            FAPI_DBG("Found approximate matching key for configuration. Index:%u. Key:0x%04x. Attr value:0x%04x.",
                     l_index, i_key, i_config_attr[l_index]);
            break;
        }
    }

    // No match found? exit out
    if(l_index ==  config_attr_keys::ATTR_SIZE)
    {
        FAPI_DBG("No matching key found for configuration");
        return config_attr_keys::ATTR_SIZE;
    }

    // Now looks for the closest match
    // Why is this needed?
    // The attribute has a configuration of >X DDIMMs, if two or more configs are there that match >X, the algorithm needs to pick the closest one
    // For example:
    // System config: 128GB DDIMM, 33 DDIMMs plugged
    // Index: 0. 128GB DDIMM, >16 DDIMMs plugged -> 4000 frequency
    // Index: 0. 128GB DDIMM, >24 DDIMMs plugged -> 3200 frequency ---- closest match, select this


    // Already have the first match, so iterate from this index
    // The loop will stop if the delta is a 0, as that's the closest possible delta
    uint16_t l_closest_delta = (i_key & DDIMM_KEY_COMPARISON_MASK) - (i_config_attr[l_index] &
                               config_attr_keys::DDIMM_KEY_COMPARISON_MASK);
    uint8_t l_closest_index = l_index;

    for(; l_index < config_attr_keys::ATTR_SIZE && l_closest_delta != 0; ++l_index)
    {
        if(does_key_match_attr(i_config_attr[l_index], i_key))
        {
            const uint16_t l_current_delta = (i_key & DDIMM_KEY_COMPARISON_MASK) - (i_config_attr[l_index] &
                                             config_attr_keys::DDIMM_KEY_COMPARISON_MASK);

            if(l_current_delta < l_closest_delta)
            {
                FAPI_DBG("Found a closer matching key for configuration. Index:%u. Key:0x%04x. Attr value:0x%04x. prior delta:%u. new delta:%u",
                         l_index, i_key, i_config_attr[l_index], l_closest_delta, l_current_delta);
                l_closest_index = l_index;
                l_closest_delta = l_closest_delta;
            }
        }
    }

    FAPI_DBG("Found the closest match to the key as index %u, with a delta of %u. Key:0x%04x. Attr value:0x%04x.",
             l_closest_index, l_closest_delta, i_key, i_config_attr[l_index]);

    return l_closest_index;
}

///
/// @brief Computes the numeric frequency from a configuration limit attribute value
/// @param[in] i_config the configuration limit attribute value
/// @return The numeric DDR frequency
///
inline uint32_t compute_freq_from_config_attr(const fapi2::buffer<uint16_t>& i_config)
{
    // Encode | frequency value
    //      1 |            3200
    //      2 |            4000
    //      3 |            4800
    // Multiply encode by 800 and add 2400 gets the correct frequency
    constexpr uint32_t INTERCEPT = 2400;
    constexpr uint32_t ENCODE_TO_FREQ_SLOPE = 800;
    uint32_t l_freq_limit_encoded = 0;
    i_config.extractToRight<config_attr_keys::FREQ_START, BITS_PER_NIBBLE>(l_freq_limit_encoded);
    return INTERCEPT + (l_freq_limit_encoded * ENCODE_TO_FREQ_SLOPE);
}

///
/// @brief Update supported frequency scoreboard according system configuration limits
/// @tparam MC mss::mc_type memory controller type
/// @tparam P mss::proc_type on which to operate
/// @tparam TT Traits associated with the processor type
/// @param[in] i_target target for which to get the DIMM configs
/// @param[in] i_config_attr the configuration attribute values
/// @param[in] i_limit_attr the frequency limiter attribute
/// @param[in,out] io_scoreboard scoreboard of port targets supporting each frequency
/// @param[out] o_skip_algorithm true if the algorithm should be skipped, otherwise false
/// @return FAPI2_RC_SUCCESS iff ok
///
template<mss::mc_type MC, mss::proc_type P, typename TT = mss::frequency_traits<P>>
fapi2::ReturnCode is_limit_freq_by_config_needed(const fapi2::Target<TT::FREQ_DOMAIN_TARGET_TYPE>& i_target,
        const uint16_t (&i_config_attr)[config_attr_keys::ATTR_SIZE],
        const uint32_t i_limit_attr,
        freq_scoreboard& io_scoreboard,
        bool& o_skip_algorithm)
{
    const auto& SYSTEM_TARGET = fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>();
    bool l_is_config_limit_needed = false;
    o_skip_algorithm = false;

    // Run and no limit? skip the algorithm
    if(i_limit_attr == fapi2::ENUM_ATTR_MSS_CONFIG_FREQ_LIMIT_NO_LIMIT)
    {
        o_skip_algorithm = true;
        FAPI_INF_NO_SBE("ATTR_MSS_MRW_CONFIG_FREQ_LIMIT has been run and has no limits. Skipping limit_freq_by_config");
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Run and has a limit? just update the frequencies
    // Note: comparing that the code is NOT_RUN here as we know that it will be a limit in this case
    if(i_limit_attr != fapi2::ENUM_ATTR_MSS_CONFIG_FREQ_LIMIT_NOT_RUN)
    {
        o_skip_algorithm = true;
        FAPI_INF_NO_SBE("ATTR_MSS_MRW_CONFIG_FREQ_LIMIT has been run and has a limit of %u DRAM frequency. Updating the scoreboard for %s",
                        i_limit_attr, mss::c_str(i_target));
        return limit_freq_in_scoreboard<MC, P>(i_target, i_limit_attr, io_scoreboard);
    }

    // Checks the configuration attribute
    FAPI_TRY(check::mrw_config_attr_validity(i_config_attr, l_is_config_limit_needed));

    // If the config attribute does not need to be run, skip this algorithm
    if(!l_is_config_limit_needed)
    {
        o_skip_algorithm = true;
        FAPI_INF_NO_SBE("ATTR_MSS_MRW_CONFIG_FREQ_LIMIT has all 0 values. Skipping limit_freq_by_config and setting ATTR_MSS_CONFIG_FREQ_LIMIT to NO_LIMIT");
        return FAPI_ATTR_SET_CONST(fapi2::ATTR_MSS_CONFIG_FREQ_LIMIT, SYSTEM_TARGET,
                                   fapi2::ENUM_ATTR_MSS_CONFIG_FREQ_LIMIT_NO_LIMIT);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Update supported frequency scoreboard according system configuration limits
/// @tparam MC mss::mc_type memory controller type
/// @tparam P mss::proc_type on which to operate
/// @tparam TT Traits associated with the processor type
/// @param[in] i_target target for which to get the DIMM configs
/// @param[in] i_config_attr the configuration attribute values
/// @param[in] i_dimm_configs the bitmap of the DIMM configuration
/// @param[in] i_num_ocmb the number of OCMB in this system
/// @param[out] o_skip_algorithm true if the algorithm should be skipped, otherwise false
/// @return FAPI2_RC_SUCCESS iff ok
///
template<mss::mc_type MC, mss::proc_type P, typename TT = mss::frequency_traits<P>>
fapi2::ReturnCode limit_freq_by_config(const fapi2::Target<TT::FREQ_DOMAIN_TARGET_TYPE>& i_target,
                                       const uint16_t (&i_config_attr)[config_attr_keys::ATTR_SIZE],
                                       const fapi2::buffer<uint8_t>& i_dimm_configs,
                                       const uint64_t i_num_ocmb,
                                       freq_scoreboard& io_scoreboard)
{
    const auto& SYSTEM_TARGET = fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>();
    uint32_t l_max_freq = ~0;

    // Note: The documentation for this algorithm states that if there is no match to the configuration, then no limit is needed
    // As such, we weed out non-matching configs first

    // Exits if the DIMM configuration or number of DIMMs show that the algorithm is not needed
    // More than 2 configs? the attribute cannot handle this so skip it
    if(bit_count(uint8_t(i_dimm_configs)) > config_attr_keys::MAX_DIFFERENT_SIZES)
    {
        FAPI_INF_NO_SBE("More different DIMM sizes than the algorithm can support. Number of different sizes:%u Max for algorithm to run:%u. Skipping running limit_freq_by_config",
                        bit_count(uint8_t(i_dimm_configs)), config_attr_keys::MAX_DIFFERENT_SIZES);
        return FAPI_ATTR_SET_CONST(fapi2::ATTR_MSS_CONFIG_FREQ_LIMIT, SYSTEM_TARGET,
                                   fapi2::ENUM_ATTR_MSS_CONFIG_FREQ_LIMIT_NO_LIMIT);
    }

    // No configs? the attribute cannot handle this so skip it
    if(i_dimm_configs == 0)
    {
        FAPI_INF_NO_SBE("No DIMM configs present. Skipping running limit_freq_by_config");
        return FAPI_ATTR_SET_CONST(fapi2::ATTR_MSS_CONFIG_FREQ_LIMIT, SYSTEM_TARGET,
                                   fapi2::ENUM_ATTR_MSS_CONFIG_FREQ_LIMIT_NO_LIMIT);
    }

    // Less than 17 DDIMMs? the attribute cannot handle this so skip it
    if(i_num_ocmb < config_attr_keys::MIN_NUM_DIMMS)
    {
        FAPI_INF_NO_SBE("Minimum number of DIMMs to run the algorithm not met. Number of DDIMMs/OCMB:%u Min for algorithm to run:%u. Skipping running limit_freq_by_config",
                        i_num_ocmb, config_attr_keys::MIN_NUM_DIMMS);
        return FAPI_ATTR_SET_CONST(fapi2::ATTR_MSS_CONFIG_FREQ_LIMIT, SYSTEM_TARGET,
                                   fapi2::ENUM_ATTR_MSS_CONFIG_FREQ_LIMIT_NO_LIMIT);
    }

    // Checks if the key exists, if not exit as this configuration is not limited
    {
        // Assembles the configuration key
        fapi2::buffer<uint16_t> l_config_key;
        FAPI_TRY(compute_config_key(i_dimm_configs, i_num_ocmb, l_config_key));

        // Loops and compares
        const uint8_t l_index = find_attr_index_from_key(i_config_attr, l_config_key);

        // No matching config found? Print and exit
        if(l_index == config_attr_keys::ATTR_SIZE)
        {
            FAPI_INF_NO_SBE("No matching key found for DIMM config. Config: 0x%04x. Skipping limit_freq_by_config", l_config_key);
            return FAPI_ATTR_SET_CONST(fapi2::ATTR_MSS_CONFIG_FREQ_LIMIT, SYSTEM_TARGET,
                                       fapi2::ENUM_ATTR_MSS_CONFIG_FREQ_LIMIT_NO_LIMIT);
        }

        // Extracts and converts the frequency
        l_max_freq = compute_freq_from_config_attr(i_config_attr[l_index]);
    }

    // Limits the frequencies based upon the config algorithm
    FAPI_TRY((limit_freq_in_scoreboard<MC, P>(i_target, l_max_freq, io_scoreboard)));

    // Sets the current max frequency to run a simpler limit for future processors
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MSS_CONFIG_FREQ_LIMIT, SYSTEM_TARGET, l_max_freq));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Update supported frequency scoreboard according system configuration limits
/// @tparam MC mss::mc_type memory controller type
/// @tparam P mss::proc_type on which to operate
/// @tparam TT Traits associated with the processor type
/// @param[in] i_target target for which to get the DIMM configs
/// @param[in,out] io_scoreboard scoreboard of port targets supporting each frequency
/// @return FAPI2_RC_SUCCESS iff ok
///
template<mss::mc_type MC, mss::proc_type P, typename TT = mss::frequency_traits<P>>
fapi2::ReturnCode limit_freq_by_config(const fapi2::Target<TT::FREQ_DOMAIN_TARGET_TYPE>& i_target,
                                       freq_scoreboard& io_scoreboard)
{
    const auto& SYSTEM_TARGET = fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>();
    bool l_skip_algorithm = false;
    uint16_t l_config_attr[config_attr_keys::ATTR_SIZE] = {};
    uint32_t l_limit_attr = 0;
    uint64_t l_num_ocmb = 0;
    fapi2::buffer<uint8_t> l_dimm_configs;

    // Grabs the configuration attribute
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_CONFIG_FREQ_LIMIT, SYSTEM_TARGET, l_config_attr));

    // Checks if the frequency algorithm has been run or not
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_CONFIG_FREQ_LIMIT, SYSTEM_TARGET, l_limit_attr));

    // Checks if the algorithm can be skipped
    FAPI_TRY((is_limit_freq_by_config_needed<MC, P>(i_target,
              l_config_attr,
              l_limit_attr,
              io_scoreboard,
              l_skip_algorithm)));

    // Skip the algorithm
    if(l_skip_algorithm)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Grabs the DIMM configuration vector and number of DIMMs
    // Note: OCMB chips are used instead of DIMM's as at this time they are the same (OCMB chips are soldered on DDIMMs)
    //       if ISDIMM systems are used in the future, this algorithm will need an update
    {
        const auto& l_domains = mss::find_targets<TT::FREQ_DOMAIN_TARGET_TYPE>(SYSTEM_TARGET, fapi2::TARGET_STATE_PRESENT);

        for(const auto& l_domain : l_domains)
        {
            FAPI_TRY((update_config_info<MC>(mss::find_targets<fapi2::TARGET_TYPE_OCMB_CHIP>(l_domain, fapi2::TARGET_STATE_PRESENT),
                                             l_num_ocmb,
                                             l_dimm_configs)));
        }
    }

    // Runs the full algorithm and sets up the helper attribute
    FAPI_TRY((limit_freq_by_config<MC, P>(i_target,
                                          l_config_attr,
                                          l_dimm_configs,
                                          l_num_ocmb,
                                          io_scoreboard)));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

} // ns mss

#endif
