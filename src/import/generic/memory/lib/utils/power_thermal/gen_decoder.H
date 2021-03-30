/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/power_thermal/gen_decoder.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file gen_decoder.H
/// @brief Decoder for ATTR_MSS_MRW_PWR_CURVE_SLOPE and _INTERCEPT and THERMAL_POWER_LIMIT
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_GEN_POWER_DECODER__
#define _MSS_GEN_POWER_DECODER__

#include <fapi2.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <generic/memory/lib/utils/power_thermal/gen_throttle_traits.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/mss_generic_attribute_getters.H>

namespace mss
{

namespace power_thermal
{

constexpr uint32_t ANY_SIZE = 0xFFFFFFFF;
constexpr uint8_t  ANY_TYPE = 0xFF;
constexpr uint8_t  ANY_GEN = 0xFF;
constexpr uint8_t  ANY_WIDTH = 0xFF;
constexpr uint8_t  ANY_DENSITY = 0xFF;
constexpr uint8_t  ANY_STACK_TYPE = 0xFF;
constexpr uint16_t ANY_MFGID = 0xFFFF;
constexpr uint8_t  ANY_HEIGHT = 0xFF;
constexpr uint8_t  ANY_PORT = 0xFF;

//Currently needs to be in sorted order for lookup to work
static const std::vector< std::pair<uint32_t , uint8_t> > DIMM_SIZE_MAP =
{
    {4,   0b0000},
    {8,   0b0001},
    {16,  0b0010},
    {32,  0b0011},
    {64,  0b0100},
    {128, 0b0101},
    {256, 0b0110},
    {512, 0b0111},
    {ANY_SIZE, 0b1111}
};



static const std::vector< std::pair<uint8_t , uint8_t> > DRAM_GEN_MAP =
{
    {fapi2::ENUM_ATTR_MEM_EFF_DRAM_GEN_EMPTY, 0b00},
    {fapi2::ENUM_ATTR_MEM_EFF_DRAM_GEN_DDR3, 0b01},
    {fapi2::ENUM_ATTR_MEM_EFF_DRAM_GEN_DDR4, 0b10},
    {ANY_GEN, 0b11}
};

static const std::vector <std::pair<uint8_t, uint8_t> > DRAM_WIDTH_MAP =
{
    {fapi2::ENUM_ATTR_MEM_EFF_DRAM_WIDTH_X4, 0b000},
    {fapi2::ENUM_ATTR_MEM_EFF_DRAM_WIDTH_X8, 0b001},
    {fapi2::ENUM_ATTR_MEM_EFF_DRAM_WIDTH_X16, 0b010},
    {fapi2::ENUM_ATTR_MEM_EFF_DRAM_WIDTH_X32, 0b011},
    {ANY_WIDTH, 0b111}
};

static const std::vector< std::pair<uint8_t , uint8_t> > DRAM_DENSITY_MAP =
{
    {4, 0b000},
    {8, 0b001},
    {16, 0b010},
    {32, 0b011},
    {64, 0b100},
    {ANY_DENSITY, 0b111}
};

static const std::vector <std::pair<uint8_t, uint8_t> > DRAM_STACK_TYPE_MAP =
{
    {fapi2::ENUM_ATTR_MEM_EFF_PRIM_STACK_TYPE_SDP, 0b00},
    {fapi2::ENUM_ATTR_MEM_EFF_PRIM_STACK_TYPE_DDP_QDP, 0b01},
    {fapi2::ENUM_ATTR_MEM_EFF_PRIM_STACK_TYPE_3DS, 0b10},
    {ANY_STACK_TYPE, 0b11}
};

//Note, the first entries of the pairs need to be in sorted order!!
static const std::vector <std::pair<uint16_t, uint8_t> > DRAM_MFGID_MAP =
{
    //Kingston
    {0x0198, 0b011},
    //A-data
    {0x04CB, 0b101},
    //Micron
    {0x802C, 0b000},
    //HYNIX
    {0x80AD, 0b001},
    //SAMSUNG
    {0x80CE, 0b010},
    //Innodisk
    {0x86F1, 0b100},
    // ANY
    {ANY_MFGID, 0b111}
};

static const std::vector< std::pair<uint8_t , uint8_t> > DIMM_MODULE_HEIGHT_MAP =
{
    {fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_1U, 0b00},
    {fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_2U, 0b01},
    {fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_4U, 0b10},
    {ANY_HEIGHT, 0b11}
};

static const std::vector < std::pair< uint8_t, uint8_t> > DIMMS_PORT_MAP =
{
    //Num dimms per MCA, only 1 or 2 possible options. 0 is no-op
    {1, 0b00},
    {2, 0b01},
    {ANY_PORT, 0b11}
};

// Forward declaration
template<mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = throttle_traits<MC>>
fapi2::ReturnCode generate_wildcard_mask(const uint32_t i_hash, uint32_t& o_mask);


///
///@brief a compare functor for the decoder::find_attr functions below
/// @tparam MC mss::mc_type
///
template<mss::mc_type MC = DEFAULT_MC_TYPE>
struct is_match
{
    ///
    ///@brief functor constructor
    ///@param[in] i_gen_key the class object's constructed hash for the installed dimm, to be compared with the attr array
    ///
    is_match(const uint32_t i_gen_key) : iv_gen_key(i_gen_key) {}
    const fapi2::buffer<uint32_t> iv_gen_key;

    ///
    ///@brief Boolean compare used for find_if function
    ///
    bool operator()(const uint64_t i_hash)
    {
        // l_this_hash is the first half of the i_hash's bits
        const uint32_t l_this_hash = i_hash >> 32;
        uint32_t l_wildcard_mask = 0;

        // Get wildcard mask. If the decoding fails(value to key), we should continue
        generate_wildcard_mask<MC>(l_this_hash, l_wildcard_mask);

        // Mask the wildcard bits
        return ((l_this_hash | l_wildcard_mask) == (iv_gen_key | l_wildcard_mask));
    }
};

///
/// @brief Encode the attribute into a bit encoding
/// @tparam S *ATTR*_SIZE enum used for fapi2::buffer position
/// @tparam L *ATTR*_LEN enum used for fapi2::buffer position
/// @tparam T integral type of key
/// @tparam OT fapi2::buffer of some integral type
/// @param[in] i_target the DIMM the encoding is for
/// @param[in] i_attr the attribute key being used for the encoding
/// @param[in] i_map a vector of pairs of the ATTR values and encodings for each value, sorted
/// @param[out] o_buf the fapi2::buffer where the encoding is going into
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff attribute is found in map lookup
///
template<size_t S, size_t L, typename T, typename OT>
inline fapi2::ReturnCode encode ( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                  const T& i_attr,
                                  const std::vector<std::pair<T, OT> >& i_map,
                                  fapi2::buffer<uint32_t>& o_buf)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    //used to hold result from vector pair lookup
    OT l_encoding = 0;

    //Failing out if we don't find an encoding. All suported types should be encoded above
    FAPI_ASSERT( mss::find_value_from_key (i_map, i_attr, l_encoding),
                 fapi2::MSS_POWER_THERMAL_ENCODE_ERROR()
                 .set_ATTR(i_attr)
                 .set_DIMM_TARGET(i_target),
                 "Couldn't find encoding for power thermal encode for value: %x target: %s", i_attr, mss::c_str(i_target));
    o_buf.insertFromRight<S, L>(l_encoding);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decode the attribute into a bit encoding
/// @tparam S DRAM_GEN_SIZE enum used for fapi2::buffer position
/// @tparam L DRAM_GEN_LEN enum used for fapi2::buffer position
/// @tparam T integral type of key
/// @tparam OT fapi2::buffer of some integral type
/// @param[in] i_map a vector of pairs of the ATTR values and encodings for each value
/// @param[in] i_buf the fapi2::buffer that has the encoding to parse
/// @param[out] o_attr the attribute value from the encoding is going
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff attribute is found in map lookup
///
template<size_t S, size_t L, typename T, typename OT>
inline fapi2::ReturnCode decode (const std::vector<std::pair<T, OT> >& i_map,
                                 fapi2::buffer<uint32_t>& i_buf,
                                 T& o_attr )
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    //used to hold result from vector pair lookup
    OT l_encoding = 0;
    i_buf.extractToRight<S, L>(l_encoding);

    //Failing out if we don't find an decoding. All suported types should be encoded above
    FAPI_ASSERT( mss::find_key_from_value (i_map, l_encoding, o_attr),
                 fapi2::MSS_POWER_THERMAL_DECODE_ERROR()
                 .set_ATTR(l_encoding),
                 "Couldn't find encoding for power thermal decode");
fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief generates wildcard mask for the hash value
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff the encoding was successful
/// @tparam MC mss::mc_type
/// @tparam TT throttle_traits throttle traits for the given mc_type
/// @param[in] i_hash The encoded value
/// @param[out] o_mask The wildcard mask
///

template<mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = throttle_traits<MC>>
fapi2::ReturnCode generate_wildcard_mask(const uint32_t i_hash, uint32_t& o_mask)
{

    fapi2::buffer<uint32_t> l_mask;
    fapi2::buffer<uint32_t> l_hash = i_hash;
    uint8_t l_uint8_buf = 0;
    uint16_t l_uint16_buf = 0;
    uint32_t l_uint32_buf = 0;

    //DIMM_SIZE wildcard
    FAPI_TRY(( decode<TT::DIMM_SIZE_START, TT::DIMM_SIZE_LEN>
               (DIMM_SIZE_MAP, l_hash, l_uint32_buf)),
             "Failed to generate power thermal decoding for %s val %d",
             "DIMM_SIZE", l_hash );

    if(ANY_SIZE == l_uint32_buf)
    {
        l_mask.setBit<TT::DIMM_SIZE_START, TT::DIMM_SIZE_LEN>();
    }

    //DRAM_GEN wildcard
    FAPI_TRY(( decode<TT::DRAM_GEN_START, TT::DRAM_GEN_LEN>
               (DRAM_GEN_MAP, l_hash, l_uint8_buf)),
             "Failed to generate power thermal decoding for %s val %d",
             "DRAM_GEN", l_hash);

    if(ANY_GEN == l_uint8_buf)
    {
        l_mask.setBit<TT::DRAM_GEN_START, TT::DRAM_GEN_LEN>();
    }

    //DIMM_TYPE wildcard
    FAPI_TRY(( decode<TT::DIMM_TYPE_START, TT::DIMM_TYPE_LEN>
               (TT::DIMM_TYPE_MAP, l_hash, l_uint8_buf)),
             "Failed to generate power thermal decoding for %s val %d",
             "DIMM_TYPE", l_hash);

    if(ANY_TYPE == l_uint8_buf)
    {
        l_mask.setBit<TT::DIMM_TYPE_START, TT::DIMM_TYPE_LEN>();
    }

    //DRAM_WIDTH wildcard
    FAPI_TRY(( decode<TT::DRAM_WIDTH_START, TT::DRAM_WIDTH_LEN>
               (DRAM_WIDTH_MAP, l_hash, l_uint8_buf)),
             "Failed to generate power thermal decoding for %s val %d",
             "DRAM_WIDTH", l_hash);

    if(ANY_WIDTH == l_uint8_buf)
    {
        l_mask.setBit<TT::DRAM_WIDTH_START, TT::DRAM_WIDTH_LEN>();
    }

    //DRAM_DENSITY wildcard
    FAPI_TRY(( decode<TT::DRAM_DENSITY_START, TT::DRAM_DENSITY_LEN>
               (DRAM_DENSITY_MAP, l_hash, l_uint8_buf)),
             "Failed to generate power thermal decoding for %s val %d",
             "DRAM_DENSITY", l_hash);

    if(ANY_DENSITY == l_uint8_buf)
    {
        l_mask.setBit<TT::DRAM_DENSITY_START, TT::DRAM_DENSITY_LEN>();
    }

    //DRAM_STACK_TYPE wildcard
    FAPI_TRY(( decode<TT::DRAM_STACK_TYPE_START, TT::DRAM_STACK_TYPE_LEN>
               (DRAM_STACK_TYPE_MAP, l_hash, l_uint8_buf)),
             "Failed to generate power thermal decoding for %s val %d",
             "DRAM_STACK_TYPE", l_hash);

    if(ANY_STACK_TYPE == l_uint8_buf)
    {
        l_mask.setBit<TT::DRAM_STACK_TYPE_START, TT::DRAM_STACK_TYPE_LEN>();
    }

    //DRAM_MFGID wildcard
    FAPI_TRY(( decode<TT::DRAM_MFGID_START, TT::DRAM_MFGID_LEN>
               (DRAM_MFGID_MAP, l_hash, l_uint16_buf)),
             "Failed to generate power thermal decoding for %s val %d",
             "DRAM_MFG_ID", l_hash);

    if(ANY_MFGID == l_uint16_buf)
    {
        l_mask.setBit<TT::DRAM_MFGID_START, TT::DRAM_MFGID_LEN>();
    }


    if (TT::MC_TARGET_TYPE == fapi2::TARGET_TYPE_MCS)
    {
        //NUM DROPS PER PORT wildcard
        FAPI_TRY(( decode<TT::DIMMS_PER_PORT_START, TT::DIMMS_PER_PORT_LEN>
                   (DIMMS_PORT_MAP, l_hash, l_uint8_buf)),
                 "Failed to generate power thermal decoding for %s val %d",
                 "DIMMS_PER_PORT", l_hash);

        if(ANY_PORT == l_uint8_buf)
        {
            l_mask.setBit<TT::DIMMS_PER_PORT_START, TT::DIMMS_PER_PORT_LEN>();
        }
    }

    if (TT::MC_TARGET_TYPE == fapi2::TARGET_TYPE_OCMB_CHIP)
    {
        //MODUEL HEIGHT wildcard
        FAPI_TRY(( decode<TT::DIMM_MODULE_HEIGHT_START, TT::DIMM_MODULE_HEIGHT_LEN>
                   (DIMM_MODULE_HEIGHT_MAP, l_hash, l_uint8_buf)),
                 "Failed to generate power thermal decoding for %s val %d",
                 "DIMMS_MODULE_HEIGHT", l_hash);

        if(ANY_HEIGHT == l_uint8_buf)
        {
            l_mask.setBit<TT::DIMM_MODULE_HEIGHT_START, TT::DIMM_MODULE_HEIGHT_LEN>();
        }
    }

    o_mask = l_mask;

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @class decoder
/// @brief Decodes the power curve and thermal power limit attributes for eff_config_thermal
/// @tparam MC mss::mc_type
/// @tparam TT throttle_traits throttle traits for the given mc_type
///
template<mss::mc_type MC, typename TT = throttle_traits<MC>>
class decoder
{
    public:

        //IVs for all of the attributes per MCS
        const mss::dimm::kind<MC> iv_kind;

        //Left in here rather than calculating during encode for testing
        uint8_t iv_dimms_per_port;

        //Power thermal attributes, both total and vddr versions will be used in eff_config_thermal
        uint16_t iv_vddr_slope = 0;
        uint16_t iv_vddr_intercept = 0;
        uint16_t iv_total_slope = 0;
        uint16_t iv_total_intercept = 0;

        // Valid for OCMB only
        uint32_t iv_power_limit = 0 ;

        uint32_t iv_thermal_power_limit = 0;

        //Generated key, used to decode all three power curve attributes
        fapi2::buffer<uint32_t> iv_gen_key;

        ///
        /// @brief Constructor
        /// @param[in] dimm::kind to call power thermal stuff on
        ///
        decoder( const mss::dimm::kind<MC>& i_kind):
            iv_kind(i_kind)
        {
            iv_dimms_per_port = mss::count_dimm (find_target<TT::PORT_TARGET_TYPE>(iv_kind.iv_target));
        };

        //
        // @brief Default destructor
        //
        ~decoder() = default;

        ///
        /// @brief generates the 32 bit encoding for the power curve attributes
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff the encoding was successful
        /// @note populates iv_gen_key
        ///
        fapi2::ReturnCode generate_encoding ();


        ///
        /// @brief encodes dimm type into key, allowing special cases like MDS
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff the encoding was successful
        /// @note populates iv_gen_key
        ///
        fapi2::ReturnCode encode_dimm_type()
        {
            FAPI_TRY(( encode<TT::DIMM_TYPE_START, TT::DIMM_TYPE_LEN>
                       (iv_kind.iv_target, iv_kind.iv_dimm_type, TT::DIMM_TYPE_MAP, iv_gen_key)),
                     "Failed to generate power thermal encoding for %s val %d on target: %s",
                     "DIMM_TYPE", iv_kind.iv_dimm_type, mss::c_str(iv_kind.iv_target) );
        fapi_try_exit:
            return fapi2::current_err;
        }


        ///
        /// @brief Finds a value for the power curve slope attributes by matching the generated hashes
        /// @param[in] i_array is a vector of the attribute values
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff the encoding was successful
        /// @note populates iv_vddr_slope, iv_total_slope
        ///
        fapi2::ReturnCode find_slope (const std::vector< const std::vector<uint64_t>* >& i_slope);

        ///
        /// @brief Finds a value for power curve intercept attributes by matching the generated hashes
        /// @param[in] i_array is a vector of the attribute values
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff the encoding was successful
        /// @note populates iv_vddr_intercept, iv_total_intercept
        ///
        fapi2::ReturnCode find_intercept (const std::vector< const std::vector<uint64_t>* >& i_intercept);

        ///
        /// @brief Finds a value from ATTR_MSS_MRW_THERMAL_MEMORY_POWER_LIMIT and stores in iv variable
        /// @param[in] i_array is a vector of the attribute values
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff the encoding was successful
        /// @note populates iv_thermal_power_limit
        ///
        fapi2::ReturnCode find_thermal_power_limit (const std::vector< const std::vector<uint64_t>* >& i_thermal_limits);

        ///
        /// @brief Helper function to find the value from attribute
        /// @tparam FIELD_START the field start offset inside attribute
        /// @tparam FIELD_LEN the field length to extract
        /// @tparam FUNCTION the function of the field
        /// @tparam OT output type
        /// @param[in] i_array is a vector of the attribute values
        /// @param[in] i_attr_description the attribute description
        /// @param[out] o_value the output value
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff the encoding was successful
        /// @note populates iv_thermal_power_limit
        ///
        template<size_t FIELD_START, size_t FIELD_LEN, generic_ffdc_codes FUNCTION, typename OT>
        fapi2::ReturnCode get_power_thermal_value(const std::vector<uint64_t>& i_array,
                const char* const i_attr_description,
                OT& o_value);
};

///
/// @brief generates the 32 bit encoding for the power curve attributes
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff the encoding was successful
/// @note populates iv_gen_keys
///
template<mss::mc_type MC, typename TT>
fapi2::ReturnCode decoder<MC, TT>::generate_encoding()
{
    //DIMM_SIZE
    FAPI_TRY(( encode<TT::DIMM_SIZE_START, TT::DIMM_SIZE_LEN>
               (iv_kind.iv_target, iv_kind.iv_size, DIMM_SIZE_MAP, iv_gen_key)),
             "Failed to generate power thermal encoding for %s val %d on target: %s",
             "DIMM_SIZE", iv_kind.iv_size, mss::c_str(iv_kind.iv_target) );

    //DRAM_GEN
    FAPI_TRY(( encode<TT::DRAM_GEN_START, TT::DRAM_GEN_LEN>
               (iv_kind.iv_target, iv_kind.iv_dram_generation, DRAM_GEN_MAP, iv_gen_key)),
             "Failed to generate power thermal encoding for %s val %d on target: %s",
             "DRAM_GEN", iv_kind.iv_dram_generation, mss::c_str(iv_kind.iv_target) );

    //DIMM_TYPE
    FAPI_TRY(( encode_dimm_type()),
             "Failed to generate power thermal encoding for %s val %d on target: %s",
             "DIMM_TYPE", iv_kind.iv_dimm_type, mss::c_str(iv_kind.iv_target) );

    //DRAM WIDTH
    FAPI_TRY(( encode<TT::DRAM_WIDTH_START, TT::DRAM_WIDTH_LEN>
               (iv_kind.iv_target, iv_kind.iv_dram_width, DRAM_WIDTH_MAP, iv_gen_key)),
             "Failed to generate power thermal encoding for %s val %d on target: %s",
             "DRAM_WIDTH", iv_kind.iv_dram_width, mss::c_str(iv_kind.iv_target) );

    //DRAM DENSITY
    FAPI_TRY(( encode<TT::DRAM_DENSITY_START, TT::DRAM_DENSITY_LEN>
               (iv_kind.iv_target, iv_kind.iv_dram_density, DRAM_DENSITY_MAP, iv_gen_key)),
             "Failed to generate power thermal encoding for %s val %d on target: %s",
             "DRAM_DENSITY", iv_kind.iv_dram_density, mss::c_str(iv_kind.iv_target) );

    //DRAM STACK TYPE
    FAPI_TRY(( encode<TT::DRAM_STACK_TYPE_START, TT::DRAM_STACK_TYPE_LEN>
               (iv_kind.iv_target, iv_kind.iv_stack_type, DRAM_STACK_TYPE_MAP, iv_gen_key)),
             "Failed to generate power thermal encoding for %s val %d on target: %s",
             "DRAM_STACK_TYPE", iv_kind.iv_stack_type, mss::c_str(iv_kind.iv_target) );

    //DRAM MFG ID
    FAPI_TRY(( encode<TT::DRAM_MFGID_START, TT::DRAM_MFGID_LEN>
               (iv_kind.iv_target, iv_kind.iv_mfgid, DRAM_MFGID_MAP, iv_gen_key)),
             "Failed to generate power thermal encoding for %s val %d on target: %s",
             "DRAM_MFG_ID", iv_kind.iv_mfgid, mss::c_str(iv_kind.iv_target) );

    if (TT::MC_TARGET_TYPE == fapi2::TARGET_TYPE_MCS)
    {
        //NUM DROPS PER PORT
        FAPI_TRY(( encode<TT::DIMMS_PER_PORT_START, TT::DIMMS_PER_PORT_LEN>
                   (iv_kind.iv_target, iv_dimms_per_port, DIMMS_PORT_MAP, iv_gen_key)),
                 "Failed to generate power thermal encoding for %s val %d on target: %s",
                 "DIMMS_PER_PORT", iv_dimms_per_port, mss::c_str(iv_kind.iv_target) );
    }

    if (TT::MC_TARGET_TYPE == fapi2::TARGET_TYPE_OCMB_CHIP)
    {
        //DIMM_MODULE_HEIGHT
        FAPI_TRY(( encode<TT::DIMM_MODULE_HEIGHT_START, TT::DIMM_MODULE_HEIGHT_LEN>
                   (iv_kind.iv_target, iv_kind.iv_module_height, DIMM_MODULE_HEIGHT_MAP, iv_gen_key)),
                 "Failed to generate power thermal encoding for %s val %d on target: %s",
                 "DIMM_MODULE_HEIGHT", iv_kind.iv_module_height, mss::c_str(iv_kind.iv_target) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to find the value from attribute
/// @param[in] i_array is a vector of the attribute values
/// @param[in] i_attr_description the attribute description
/// @param[out] o_value the output value
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff the encoding was successful
/// @note populates iv_thermal_power_limit
///
template<mss::mc_type MC, typename TT>
template<size_t FIELD_START, size_t FIELD_LEN, generic_ffdc_codes FUNCTION, typename OT>
fapi2::ReturnCode decoder<MC, TT>::get_power_thermal_value(const std::vector<uint64_t>& i_array,
        const char* const i_attr_description,
        OT& o_value)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    // Find iterator to matching key (if it exists)
    auto l_value_iterator  =  std::find_if(i_array.begin(),
                                           i_array.end(),
                                           is_match<>(iv_gen_key));

    FAPI_ASSERT(l_value_iterator != i_array.end(),
                fapi2::MSS_NO_POWER_THERMAL_ATTR_FOUND()
                .set_GENERATED_KEY(iv_gen_key)
                .set_FUNCTION(FUNCTION)
                .set_DIMM_TARGET(iv_kind.iv_target)
                .set_SIZE(iv_kind.iv_size)
                .set_DRAM_GEN(iv_kind.iv_dram_generation)
                .set_DIMM_TYPE(iv_kind.iv_dimm_type)
                .set_DRAM_WIDTH( iv_kind.iv_dram_width)
                .set_DRAM_DENSITY(iv_kind.iv_dram_density)
                .set_STACK_TYPE(iv_kind.iv_stack_type)
                .set_MFGID(iv_kind.iv_mfgid)
                .set_MODULE_HEIGHT(iv_kind.iv_module_height),
                "Couldn't find %s value for generated key:0x%08lx, for target %s. "
                "DIMM values for generated key are "
                "size is %d, gen is %d, type is %d, width is %d, density %d, stack %d, mfgid %d, dimms %d, height %d",
                i_attr_description,
                iv_gen_key,
                mss::c_str(iv_kind.iv_target),
                iv_kind.iv_size,
                iv_kind.iv_dram_generation,
                iv_kind.iv_dimm_type,
                iv_kind.iv_dram_width,
                iv_kind.iv_dram_density,
                iv_kind.iv_stack_type,
                iv_kind.iv_mfgid,
                iv_dimms_per_port,
                iv_kind.iv_module_height
               );
    {
        const fapi2::buffer<uint64_t> l_temp(*l_value_iterator);
        l_temp.extractToRight<FIELD_START, FIELD_LEN>(o_value);
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // power_thermal
} // mss
#endif
