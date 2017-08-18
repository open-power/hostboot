/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/power_thermal/decoder.H $ */
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
/// @file decoder.H
/// @brief Decoder for ATTR_MSS_MRW_PWR_CURVE_SLOPE and _INTERCEPT and THERMAL_POWER_LIMIT
///
// *HWP HWP Owner: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_POWER_DECODER__
#define _MSS_POWER_DECODER__

#include <fapi2.H>
#include <mss.H>
#include <lib/dimm/kind.H>
#include <lib/utils/count_dimm.H>
namespace mss
{

namespace power_thermal
{

enum size_of_attrs : size_t
{
    SIZE_OF_POWER_CURVES_ATTRS = 100,
    SIZE_OF_THERMAL_ATTR = 10,
};

enum default_power
{
    //Values are the worst case defaults for power curves
    //They are the default/ catch-all values from the power curve attributes
    //Shouldn't be used if system is set up correctly and attributes are available
    //This will throttle the DIMMs to ~76% dram data bus utilization
    //(using the mrw regulator power limit of 1700 cW and thermal power limit here of 1940 cW).
    VDDR_SLOPE = 0x41A,
    VDDR_INT = 0x384,
    TOTAL_SLOPE = 0x44C,
    TOTAL_INT = 0x44C,
    THERMAL_LIMIT = 0x794,
};

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
};

static const std::vector< std::pair<uint8_t , uint8_t> > DIMM_TYPE_MAP =
{
    {fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM, 0b00},
    {fapi2::ENUM_ATTR_EFF_DIMM_TYPE_UDIMM, 0b01},
    {fapi2::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM, 0b10},
};

static const std::vector< std::pair<uint8_t , uint8_t> > DRAM_GEN_MAP =
{
    {fapi2::ENUM_ATTR_EFF_DRAM_GEN_EMPTY, 0b00},
    {fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR3, 0b01},
    {fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4, 0b10}
};

static const std::vector <std::pair<uint8_t, uint8_t> > DRAM_WIDTH_MAP =
{
    {fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4, 0b000},
    {fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X8, 0b001},
    {fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X16, 0b010},
    {fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X32, 0b011}
};

static const std::vector< std::pair<uint8_t , uint8_t> > DRAM_DENSITY_MAP =
{
    {4, 0b000},
    {8, 0b001},
    {16, 0b010},
    {32, 0b011},
    {64, 0b100},
};

static const std::vector <std::pair<uint8_t, uint8_t> > DRAM_STACK_TYPE_MAP =
{
    {fapi2::ENUM_ATTR_EFF_PRIM_STACK_TYPE_SDP, 0b00},
    {fapi2::ENUM_ATTR_EFF_PRIM_STACK_TYPE_DDP_QDP, 0b01},
    {fapi2::ENUM_ATTR_EFF_PRIM_STACK_TYPE_3DS, 0b10}
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
};

static const std::vector < std::pair< uint8_t, uint8_t> > DIMMS_PORT_MAP =
{
    //Num dimms per MCA, only 1 or 2 possible options. 0 is no-op
    {1, 0b00},
    {2, 0b01}
};

//Bit positions for different section of the attribute
//first 32 bits are the encoding, second are for values
enum DECODE_BUFFER_POS
{
    ENCODING_START = 0,
    ENCODING_LENGTH = 32,
    VDDR_START = 32,
    VDDR_LENGTH = 16,
    TOTAL_START = 48,
    TOTAL_LENGTH = 16,
    THERMAL_POWER_START = 32,
    THERMAL_POWER_LENGTH = 32,
};

//Positions and lengths of the encodings
enum ATTR_DECODE_INFO
{
    DIMM_SIZE_START = 0,
    DIMM_SIZE_LEN = 4,

    DRAM_GEN_START = 4,
    DRAM_GEN_LEN = 2,

    DIMM_TYPE_START = 6,
    DIMM_TYPE_LEN = 2,

    DRAM_WIDTH_START = 8,
    DRAM_WIDTH_LEN = 3,

    DRAM_DENSITY_START = 11,
    DRAM_DENSITY_LEN = 3,

    DRAM_STACK_TYPE_START = 14,
    DRAM_STACK_TYPE_LEN = 2,

    DRAM_MFGID_START = 16,
    DRAM_MFGID_LEN = 3,

    DIMMS_PER_PORT_START = 19,
    DIMMS_PER_PORT_LEN = 2,
};

///
/// @class decoder
/// @brief Decodes the power curve and thermal power limit attributes for eff_config_thermal
///
class decoder
{
    public:

        //IVs for all of the attributes per MCS
        const mss::dimm::kind iv_kind;

        //Left in here rather than calculating during encode for testing
        uint8_t iv_dimms_per_port;

        //Power thermal attributes, both total and vddr versions will be used in eff_config_thermal
        uint16_t iv_vddr_slope;
        uint16_t iv_vddr_intercept;
        uint16_t iv_total_slope;
        uint16_t iv_total_intercept;

        uint32_t iv_thermal_power_limit;
        //Generated key, used to decode all three power curve attributes
        fapi2::buffer<uint32_t> iv_gen_key;

        ///
        /// @brief Constructor
        /// @param[in] dimm::kind to call power thermal stuff on
        ///
        decoder( mss::dimm::kind& i_kind):
            iv_kind(i_kind)
        {
            iv_dimms_per_port = mss::count_dimm (find_target<fapi2::TARGET_TYPE_MCA>(iv_kind.iv_target));
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
        /// @brief Finds a value for the power curve slope attributes by matching the generated hashes
        /// @param[in] i_array is a vector of the attribute values
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff the encoding was successful
        /// @note populates iv_vddr_slope, iv_total_slope
        ///
        fapi2::ReturnCode find_slope (const std::vector<fapi2::buffer<uint64_t>>& i_slope);

        ///
        /// @brief Finds a value for power curve intercept attributes by matching the generated hashes
        /// @param[in] i_array is a vector of the attribute values
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff the encoding was successful
        /// @note populates iv_vddr_intercept, iv_total_intercept
        ///
        fapi2::ReturnCode find_intercept (const std::vector<fapi2::buffer<uint64_t>>& i_intercept);

        ///
        /// @brief Finds a value from ATTR_MSS_MRW_THERMAL_MEMORY_POWER_LIMIT and stores in iv variable
        /// @param[in] i_array is a vector of the attribute values
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff the encoding was successful
        /// @note populates iv_thermal_power_limit
        ///
        fapi2::ReturnCode find_thermal_power_limit (const std::vector<fapi2::buffer<uint64_t>>& i_thermal_limits);

};

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
/// @note used to get power curve attributes in calling function
/// @note decodes the attribute "encoding" to get the vddr and vddr/vpp power curves for a dimm
///
fapi2::ReturnCode get_power_attrs (const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_targets,
                                   const std::vector< fapi2::buffer< uint64_t > >& i_slope,
                                   const std::vector< fapi2::buffer< uint64_t > >& i_intercept,
                                   const std::vector< fapi2::buffer< uint64_t > >& i_thermal_power_limit,
                                   uint16_t o_vddr_slope       [PORTS_PER_MCS][MAX_DIMM_PER_PORT],
                                   uint16_t o_vddr_int         [PORTS_PER_MCS][MAX_DIMM_PER_PORT],
                                   uint16_t o_total_slope      [PORTS_PER_MCS][MAX_DIMM_PER_PORT],
                                   uint16_t o_total_int        [PORTS_PER_MCS][MAX_DIMM_PER_PORT],
                                   uint32_t o_thermal_power    [PORTS_PER_MCS][MAX_DIMM_PER_PORT]);
///
/// @brief Encode the attribute into a bit encoding
/// @tparam[in] S *ATTR*_SIZE enum used for fapi2::buffer position
/// @tparam[in] L *ATTR*_LEN enum used for fapi2::buffer position
/// @tparam[in] OT fapi2::buffer of some integral type
/// @tparam[in] T integral type of key
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
    //used to hold result from vector pair lookup
    OT l_encoding = 0;

    //Returns true if found, so need to negate for FAPI_TRY
    //Failing out if we don't find an encoding. All suported types should be encoded above
    FAPI_TRY( !mss::find_value_from_key (i_map, i_attr, l_encoding),
              "Couldn't find encoding for power thermal encode for value: %x target: %s", i_attr, mss::c_str(i_target));
    o_buf.insertFromRight<S, L>(l_encoding);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decode the attribute into a bit encoding
/// @tparam[in] S DRAM_GEN_SIZE enum used for fapi2::buffer position
/// @tparam[in] L DRAM_GEN_LEN enum used for fapi2::buffer position
/// @tparam[in] OT fapi2::buffer of some integral type
/// @tparam[in] T integral type of key
/// @param[in] i_target the DIMM the encoding is for
/// @param[in] i_map a vector of pairs of the ATTR values and encodings for each value
/// @param[in] i_buf the fapi2::buffer that has the encoding to parse
/// @param[out] o_attr the attribute value from the encoding is going
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff attribute is found in map lookup
///
template<size_t S, size_t L, typename T, typename OT>
inline fapi2::ReturnCode decode ( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                  const std::vector<std::pair<T, OT> >& i_map,
                                  fapi2::buffer<uint32_t>& i_buf,
                                  T& o_attr )
{
    //used to hold result from vector pair lookup
    OT l_encoding = 0;
    i_buf.extractToRight<S, L>(l_encoding);
    //Find_key_from_value returns fapi2 error
    FAPI_TRY( mss::find_key_from_value (i_map, l_encoding, o_attr),
              "Couldn't find encoding for power thermal decode for target: %s", mss::c_str(i_target));
fapi_try_exit:
    return fapi2::current_err;
}

} // power_thermal
} // mss
#endif

