/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/spd/spd_factory.C $ */
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
/// @file spd_factory.C
/// @brief SPD factory and functions
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

// std lib
#include <map>
#include <vector>

// fapi2
#include <fapi2.H>
#include <fapi2_spd_access.H>

// mss lib
#include <lib/spd/spd_factory.H>
#include <lib/spd/common/spd_decoder.H>

#include <lib/utils/checker.H>
#include <lib/utils/c_str.H>
#include <lib/utils/conversions.H>
#include <lib/utils/find.H>

using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_DIMM;

namespace mss
{
namespace spd
{

///
/// @brief       Decodes SPD Revision encoding level
/// @param[in]   i_target dimm target
/// @param[in]   i_spd_data SPD data
/// @param[out]  o_value encoding revision num
/// @return      FAPI2_RC_SUCCESS if okay
/// @note        Decodes SPD Byte 1 (3~0).
/// @note        Item JC-45-2220.01x
/// @note        Page 14-15
/// @note        DDR4 SPD Document Release 3
///
fapi2::ReturnCode rev_encoding_level(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                     const std::vector<uint8_t>& i_spd_data,
                                     uint8_t& o_value)
{
    // Buffer used for bit manipulation
    constexpr size_t BYTE_INDEX = 1;
    uint8_t l_raw_byte = i_spd_data[BYTE_INDEX];

    // Trace in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX.",
             c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    uint8_t l_field_bits = 0;
    fapi2::buffer<uint8_t> l_buffer(l_raw_byte);
    l_buffer.extractToRight<ENCODING_LEVEL_START, ENCODING_LEVEL_LEN>(l_field_bits);

    FAPI_INF("Field Bits value: %d", l_field_bits);

    // Check that value is valid
    constexpr size_t UNDEFINED = 0xF; // per JEDEC spec this value is undefined
    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              (l_field_bits != UNDEFINED),
              BYTE_INDEX,
              l_raw_byte,
              "Failed check on SPD rev encoding level") );

    // Update output only after check passes
    o_value = l_field_bits;

    // Print decoded info
    FAPI_INF("%s. Rev - Encoding Level : %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief       Decodes SPD Revision additions level
/// @param[in]   i_target dimm target
/// @param[in]  i_spd_data SPD data
/// @param[out]  o_value additions revision num
/// @return      FAPI2_RC_SUCCESS if okay
/// @note        Decodes SPD Byte 1 (bits 7~4).
/// @note        Item JC-45-2220.01x
/// @note        Page 14-15
/// @note        DDR4 SPD Document Release 3
///
fapi2::ReturnCode rev_additions_level(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                      const std::vector<uint8_t>& i_spd_data,
                                      uint8_t& o_value)
{
    // Buffer used for bit manipulation
    constexpr size_t BYTE_INDEX = 1;
    uint8_t l_raw_byte = i_spd_data[BYTE_INDEX];

    // Trace in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    fapi2::buffer<uint8_t> l_buffer(l_raw_byte);
    uint8_t l_field_bits = 0;
    l_buffer.extractToRight<ADDITIONS_LEVEL_START, ADDITIONS_LEVEL_LEN>(l_field_bits);

    FAPI_INF("Field Bits value: %d", l_field_bits);

    // Check that value is valid
    constexpr size_t UNDEFINED = 0xF; // per JEDEC spec this value is undefined

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              (l_field_bits != UNDEFINED),
              BYTE_INDEX,
              l_raw_byte,
              "Failed check on SPD rev encoding level") );

    // Update output only after check passes
    o_value = l_field_bits;

    // Print decoded info
    FAPI_INF("%s. Rev - Additions Level : %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decodes base module type (DIMM type) from SPD
/// @param[in]  i_target dimm target
/// @param[in]  i_spd_data SPD data
/// @param[out] o_value base module type
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       Decodes SPD Byte 3 (bits 3~0)
/// @note       Item JC-45-2220.01x
/// @note       Page 17
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode base_module_type(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                   const std::vector<uint8_t>& i_spd_data,
                                   uint8_t& o_value)
{
    // =========================================================
    // Byte 3 maps
    // Item JC-45-2220.01x
    // Page 17
    // DDR4 SPD Document Release 3
    // Byte 3 (0x003): Key Byte / Module Type
    // =========================================================
    static const std::vector<std::pair<uint8_t, uint8_t> > BASE_MODULE_TYPE_MAP =
    {
        //{key byte, dimm type}
        {1, fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM},
        {2, fapi2::ENUM_ATTR_EFF_DIMM_TYPE_UDIMM},
        {4, fapi2::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM}
        // All others reserved or not supported
    };

    // Buffer used for bit manipulation
    constexpr size_t BYTE_INDEX = 3;
    uint8_t l_raw_byte  = i_spd_data[BYTE_INDEX];

    // Trace in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    fapi2::buffer<uint8_t> l_spd_buffer(l_raw_byte);
    uint8_t l_field_bits = 0;
    l_spd_buffer.extractToRight<BASE_MODULE_START, BASE_MODULE_LEN>(l_field_bits);

    FAPI_INF("Field Bits value: %d", l_field_bits);

    // Check that value is valid
    bool l_is_val_found = find_value_from_key(BASE_MODULE_TYPE_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check on Base Module Type") );

    FAPI_INF("%s. Base Module Type: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief       Decodes DRAM Device Type
/// @param[in]   i_target dimm target
/// @param[in]   i_spd_data SPD data
/// @param[out]  o_value dram device type enumeration
/// @return      FAPI2_RC_SUCCESS if okay
/// @note        Decodes SPD Byte 2
/// @note        Item JC-45-2220.01x
/// @note        Page 16
/// @note        DDR4 SPD Document Release 3
///
fapi2::ReturnCode dram_device_type(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                   const std::vector<uint8_t>& i_spd_data,
                                   uint8_t& o_value)
{
    // =========================================================
    // Byte 2 maps
    // Item JC-45-2220.01x
    // Page 16
    // DDR4 SPD Document Release 3
    // Byte 2 (0x002): Key Byte / DRAM Device Type
    // =========================================================
    static const std::vector<std::pair<uint8_t, uint8_t> > DRAM_GEN_MAP =
    {
        //{key value, dram gen}
        {0x0B, fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR3},
        {0x0C, fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4}
        // Other key bytes reserved or not supported
    };

    constexpr size_t BYTE_INDEX = 2;
    uint8_t l_raw_byte = i_spd_data[BYTE_INDEX];

    // Trace in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(DRAM_GEN_MAP, l_raw_byte, o_value);

    FAPI_TRY( mss::check::spd:: fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_raw_byte,
              "Failed check on SPD dram device type") );
    // Print decoded info
    FAPI_INF("%s Device type : %d",
             c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief       Object factory to select correct decoder
/// @param[in]   i_target dimm target
/// @param[in]   i_spd_data SPD data
/// @param[out]  o_fact_obj shared pointer to the factory object
/// @return      FAPI2_RC_SUCCESS if okay
/// @note        Factory dependent on SPD revision & dimm type
///
fapi2::ReturnCode factory(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                          const std::vector<uint8_t>& i_spd_data,
                          std::shared_ptr<decoder>& o_fact_obj)
{
    if( i_spd_data.empty() )
    {
        // This won't work with no data
        return fapi2::FAPI2_RC_INVALID_PARAMETER;
    }

    const auto l_mcs = mss::find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );
    const auto l_dimm_num = index(i_target);
    uint8_t l_dimm_type = 0;

    {
        // Get dimm type & set attribute (needed by c_str)
        uint8_t l_dimm_types_mcs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

        FAPI_TRY( base_module_type(i_target, i_spd_data, l_dimm_type),
                  "Failed to find base module type" );
        FAPI_TRY( eff_dimm_type(l_mcs, &l_dimm_types_mcs[0][0]) );

        l_dimm_types_mcs[l_port_num][l_dimm_num] = l_dimm_type;
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_TYPE, l_mcs, l_dimm_types_mcs) );
    }

    {
        // Get dram generation & set attribute (needed by c_str)
        uint8_t l_dram_gen = 0;
        uint8_t l_dram_gen_mcs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};

        FAPI_TRY( eff_dram_gen(l_mcs, &l_dram_gen_mcs[0][0]) );
        FAPI_TRY( dram_device_type(i_target, i_spd_data, l_dram_gen),
                  "Failed to find base module type" );

        l_dram_gen_mcs[l_port_num][l_dimm_num] = l_dram_gen;

        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_GEN, l_mcs, l_dram_gen_mcs) );
    }

    {
        std::shared_ptr<dimm_module_decoder> l_module_decoder;
        uint8_t l_encoding_rev = 0;
        uint8_t l_additions_rev = 0;

        // Get revision levels
        FAPI_TRY( rev_encoding_level(i_target, i_spd_data, l_encoding_rev),
                  "Failed to find encoding level" );
        FAPI_TRY( rev_additions_level(i_target, i_spd_data,  l_additions_rev),
                  "Failed to find additons level" );

        // Get decoder object needed for current dimm type and spd rev
        switch(l_dimm_type)
        {
            // Each dimm type rev is independent
            case fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM:

                // SPD Revision format #.#
                // 1st # = encoding level
                // 2nd # = additions level
                switch(l_encoding_rev)
                {
                    // Skipping case 0 since we shouldn't be using pre-production revisions
                    case 1:
                        switch(l_additions_rev)
                        {
                            // Rev 1.0
                            case 0:
                                // Life starts out at base revision level
                                l_module_decoder = std::make_shared<rdimm_decoder_v1_0>(i_target, i_spd_data);
                                o_fact_obj = std::make_shared<decoder>( i_target, i_spd_data, l_module_decoder );
                                break;

                            case 1:
                                // Rev 1.1
                                // Changes to both the general section & rdimm section occured
                                l_module_decoder = std::make_shared<rdimm_decoder_v1_1>(i_target, i_spd_data);
                                o_fact_obj = std::make_shared<decoder_v1_1>( i_target, i_spd_data, l_module_decoder );
                                break;

                            default:
                                FAPI_TRY( mss::check::spd::invalid_factory_sel(i_target,
                                          l_dimm_type,
                                          l_encoding_rev,
                                          l_additions_rev,
                                          "Additions Level Unsupported!") );
                                break;
                        }//end additions

                        break;

                    default:
                        FAPI_TRY( mss::check::spd::invalid_factory_sel(i_target,
                                  l_dimm_type,
                                  l_encoding_rev,
                                  l_additions_rev,
                                  "Encoding Level Unsupported!") );
                        break;
                }// end encodings

                break;

            default:
                FAPI_TRY( mss::check::spd::invalid_factory_sel(i_target,
                          l_dimm_type,
                          l_encoding_rev,
                          l_additions_rev,
                          "DIMM Type Unsupported!") );
                break;

        } // end dimm type

        FAPI_INF("%s: Decoder created SPD revision %d.%d",
                 c_str(i_target),
                 l_encoding_rev,
                 l_additions_rev);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief       Creates factory object & SPD data caches
/// @param[in]   i_target controller target
/// @param[out]  o_factory_caches map of factory objects with a dimm position key
/// @return      FAPI2_RC_SUCCESS if okay
/// @note        This specialization is suited for creating a cache with platform
///              SPD data.
///
template<>
fapi2::ReturnCode populate_decoder_caches( const fapi2::Target<TARGET_TYPE_MCS>& i_target,
        std::map<uint32_t, std::shared_ptr<decoder> >& o_factory_caches,
        const std::shared_ptr<decoder>& i_pDecoder)
{
    // Input decoder for this version of populating cache would get overriden
    // so I don't bother with it here
    std::shared_ptr<decoder> l_pDecoder;

    for( const auto& l_dimm : find_targets<TARGET_TYPE_DIMM>(i_target) )
    {
        size_t l_size = 0;
        FAPI_TRY( fapi2::getSPD(l_dimm, nullptr, l_size) );

        {
            // "Container" for SPD data
            std::vector<uint8_t> l_spd(l_size);

            // Retrive SPD data
            FAPI_TRY( fapi2::getSPD(l_dimm, l_spd.data(), l_size) );

            // Retrieve factory object instance & populate spd data for that instance
            FAPI_TRY( factory(l_dimm, l_spd, l_pDecoder) );

            // Populate spd caches maps based on dimm pos
            o_factory_caches.emplace( std::make_pair( pos(l_dimm), l_pDecoder ) );
        }

    }// end dimm

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief       Creates factory object & SPD data caches
/// @param[in]   i_target the dimm target
/// @param[out]  o_factory_caches map of factory objects with a dimm position key
/// @return      FAPI2_RC_SUCCESS if okay
/// @note        This specialization is suited for creating a cache with custom
///              SPD data (e.g. testing custom SPD).
///
template<>
fapi2::ReturnCode populate_decoder_caches( const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        std::map<uint32_t, std::shared_ptr<decoder> >& o_factory_caches,
        const std::shared_ptr<decoder>& i_pDecoder)
{
    if(i_pDecoder == nullptr)
    {
        // This won't work w/a null parameter
        return fapi2::FAPI2_RC_INVALID_PARAMETER;
    }

    // Custom decoder provided (usually done for testing)
    // Populate custom spd caches maps one dimm at a time
    o_factory_caches.emplace( std::make_pair( pos(i_target), i_pDecoder ) );

    return fapi2::FAPI2_RC_SUCCESS;
}

}// spd
}// mss
