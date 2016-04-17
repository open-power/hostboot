/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/spd/spd_decoder.C $        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */


///
/// @file spd_decoder.C
/// @brief SPD decoder definitions
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP
#include <map>
#include <vector>

#include <fapi2.H>
#include <mss.H>
#include <lib/spd/spd_decoder.H>
#include <utils/conversions.H>
#include <utils/find.H>
#include <utils/fake_spd.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_DIMM;


namespace mss
{
namespace spd
{

// =========================================================
// Byte 0 maps
// Item JC-45-2220.01x
// Page 14
// DDR4 SPD Document Release 3
// Byte 0 (0x000): Number of Bytes Used / Number of Bytes in SPD Device
// =========================================================
static const std::vector<std::pair<uint8_t, uint16_t> > BYTES_USED_MAP =
{
    //{key byte, number of used bytes}
    {1, 128},
    {2, 256},
    {3, 384},
    {4, 512}
};


static const std::vector<std::pair<uint8_t, uint16_t> > BYTES_TOTAL_MAP =
{
    //{key byte, number of total bytes}
    {1, 256},
    {2, 512}
};

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
};

static const std::vector<std::pair<uint8_t, uint8_t> > HYBRID_MEDIA_MAP =
{
    //{key, value}
    {0, fapi2::ENUM_ATTR_EFF_HYBRID_MEMORY_TYPE_NONE},
    {1, fapi2::ENUM_ATTR_EFF_HYBRID_MEMORY_TYPE_NVDIMM}
};

static const std::vector<std::pair<uint8_t, uint8_t> > HYBRID_MAP =
{
    //{key byte, value}
    {0, fapi2::ENUM_ATTR_EFF_HYBRID_NOT_HYBRID},
    {1, fapi2::ENUM_ATTR_EFF_HYBRID_IS_HYBRID}
};

// =========================================================
// Byte 4 maps
// Item JC-45-2220.01x
// Page 18
// DDR4 SPD Document Release 3
// Byte 4 (0x004): SDRAM Density and Banks
// =========================================================
static const std::vector<std::pair<uint8_t, uint8_t> > SDRAM_DENSITY_MAP =
{
    // {key byte, capacity in GBs}
    {2, 1},
    {3, 2},
    {4, 4},
    {5, 8},
    {6, 16},
    {7, 32},
    {8, 12},
    {12, 24}
};

static const std::vector<std::pair<uint8_t, uint8_t> > BANK_ADDR_BITS_MAP =
{
    // {key byte, number of bank address bits}
    {0, 2},
    {1, 3}
};

static const std::vector<std::pair<uint8_t, uint8_t> > BANK_GROUP_BITS_MAP =
{
    // {key byte, number of bank groups bits}
    {0, 0},
    {1, 1},
    {2, 2}
};


// =========================================================
// Byte 5 maps
// Item JC-45-2220.01x
// Page 18
// DDR4 SPD Document Release 3
// Byte 5 (0x005): SDRAM Addressing
// =========================================================
static const std::vector<std::pair<uint8_t, uint8_t> > COLUMN_ADDRESS_BITS_MAP =
{
    //{key byte,col address bits}
    {0, 9},
    {1, 10},
    {2, 11},
    {3, 12}
};

static const std::vector<std::pair<uint8_t, uint8_t> > ROW_ADDRESS_BITS_MAP =
{
    //{key byte,row address bits}
    {0, 12},
    {1, 13},
    {2, 14},
    {3, 15},
    {4, 16},
    {5, 17},
    {6, 18}
};

// =========================================================
// Byte 6 maps
// Item JC-45-2220.01x
// Page 19
// DDR4 SPD Document Release 3
// Byte 6 (0x006): Primary SDRAM Package Type
// =========================================================
static const std::vector<std::pair<uint8_t, uint8_t> > PRIM_SIGNAL_LOADING_MAP =
{
    // {key byte, signal loading}
    {0, UNSPECIFIED},
    {1, MULTI_LOAD_STACK},
    {2, SINGLE_LOAD_STACK}
};

static const std::vector<std::pair<uint8_t, uint8_t> > PRIM_DIE_COUNT_MAP =
{
    // {key byte, number of die}
    {0, 1},
    {1, 2},
    {2, 3},
    {3, 4},
    {4, 5},
    {5, 6},
    {6, 7},
    {7, 8}

};

static const std::vector<std::pair<uint8_t, uint8_t> > PRIM_PACKAGE_TYPE_MAP =
{
    // {key byte, value}
    {0, MONOLITHIC},
    {1, NON_MONOLITHIC}
};

// =========================================================
// Byte 7 maps
// Item JC-45-2220.01x
// Page 20
// DDR4 SPD Document Release 3
// Byte 7 (0x007): SDRAM Optional Features
// =========================================================
static const std::vector<std::pair<uint8_t, uint32_t> > MAC_MAP =
{
    // {key byte, maximum activate count}
    {0, fapi2::ENUM_ATTR_EFF_DRAM_MAC_UNTESTED},
    {1, fapi2::ENUM_ATTR_EFF_DRAM_MAC_700K},
    {2, fapi2::ENUM_ATTR_EFF_DRAM_MAC_600K},
    {3, fapi2::ENUM_ATTR_EFF_DRAM_MAC_500K},
    {4, fapi2::ENUM_ATTR_EFF_DRAM_MAC_400K},
    {5, fapi2::ENUM_ATTR_EFF_DRAM_MAC_300K},
    {6, fapi2::ENUM_ATTR_EFF_DRAM_MAC_200K},
    {8, fapi2::ENUM_ATTR_EFF_DRAM_MAC_UNLIMITED}
};

// Multiplier with tREFI is not taken into account here
static const std::vector<std::pair<uint8_t, uint32_t> > TMAW_MAP =
{
    // {key byte, tMAW multiplier}
    {0, 8192},
    {1, 4096},
    {2, 2048}
};

// =========================================================
// Byte 9 maps
// Item JC-45-2220.01x
// Page 21
// DDR4 SPD Document Release 3
// Byte 9 (0x009): Other SDRAM Optional Features
// =========================================================
static const std::vector<std::pair<uint8_t, uint8_t> > SOFT_PPR_MAP =
{
    // {key byte, value }
    {0, fapi2::ENUM_ATTR_EFF_DRAM_SOFT_PPR_NOT_SUPPORTED},
    {1, fapi2::ENUM_ATTR_EFF_DRAM_SOFT_PPR_SUPPORTED}
};

static const std::vector<std::pair<uint8_t, uint8_t> > PPR_MAP =
{
    // {key byte, value }
    {0, fapi2::ENUM_ATTR_EFF_DRAM_PPR_NOT_SUPPORTED},
    {1, fapi2::ENUM_ATTR_EFF_DRAM_PPR_SUPPORTED}
};

// =========================================================
// Byte 10 maps
// Item JC-45-2220.01x
// Page 21-22
// DDR4 SPD Document Release 3
// Byte 10 (0x00A): Secondary SDRAM Package Type
// =========================================================
static const std::vector<std::pair<uint8_t, uint8_t> > SEC_SIGNAL_LOADING_MAP =
{
    // {key byte, signal loading}
    {0, UNSPECIFIED},
    {1, MULTI_LOAD_STACK},
    {2, SINGLE_LOAD_STACK}
};

static const std::vector<std::pair<uint8_t, uint8_t> > SEC_DIE_COUNT_MAP =
{
    // {key byte, number of die}
    {0, 1},
    {1, 2},
    {2, 3},
    {3, 4},
    {4, 5},
    {5, 6},
    {6, 7},
    {7, 8}

};

static const std::vector<std::pair<uint8_t, uint8_t> > SEC_PACKAGE_TYPE_MAP =
{
    // {key byte, value }
    {0, MONOLITHIC},
    {1, NON_MONOLITHIC}
};


// =========================================================
// Byte 11 maps
// Item JC-45-2220.01x
// Page 22-23
// DDR4 SPD Document Release 3
// Byte 11 (0x00B): Modle Nominal Voltage
// =========================================================
static const std::vector<std::pair<uint8_t, uint8_t> > ENDURANT_MAP =
{
    // {key byte, value }
    {0, NOT_ENDURANT},
    {1, ENDURANT}
};

static const std::vector<std::pair<uint8_t, uint8_t> > OPERABLE_MAP =
{
    // {key byte, value }
    {0, NOT_OPERABLE },
    {1, OPERABLE}
};

// =========================================================
// Byte 12 maps
// Item JC-45-2220.01x
// Page 23
// DDR4 SPD Document Release 3
// Byte 12 (0x00C): Module Organization
// =========================================================
static const std::vector<std::pair<uint8_t, uint8_t> > DEVICE_WIDTH_MAP =
{
    // {key byte, device width (bits)}
    {0, 4},
    {1, 8},
    {2, 16},
    {3, 32},
    // All others reserved
};

static const std::vector<std::pair<uint8_t, uint8_t> > NUM_PACKAGE_RANKS_MAP =
{
    // {key byte, num of package ranks per DIMM (package ranks)}
    {0, 1},
    {1, 2},
    {2, 3},
    {3, 4},
    {4, 5},
    {5, 6},
    {6, 7},
    {7, 8}
};

// =========================================================
// Byte 13 maps
// Item JC-45-2220.01x
// Page 27
// DDR4 SPD Document Release 3
// Byte 13 (0x00D): Module Memory Bus Width
// =========================================================
static const std::vector<std::pair<uint8_t, uint8_t> > BUS_WIDTH_MAP =
{
    // {key byte, bus width (in bits)
    {0, 8},
    {1, 16},
    {2, 32},
    {3, 64}
    // All others reserved
};

static const std::vector<std::pair<uint8_t, uint8_t> > BUS_WIDTH_EXT_MAP =
{
    {0, 0},
    {1, 8}
    // All others reserved
};

// =========================================================
// Byte 17 maps
// Item JC-45-2220.01x
// Page 29
// DDR4 SPD Document Release 3
// Byte 17 (0x011): Timebases
// =========================================================
// Created a maps of a single value in case mapping expands to more values
static const std::vector<std::pair<uint8_t, int64_t> > MEDIUM_TIMEBASE_MAP =
{
    // {key byte, medium timebase (in picoseconds)
    {0, 125}
    // All others reserved
};

static const std::vector<std::pair<uint8_t, int64_t> > FINE_TIMEBASE_MAP =
{
    // {key byte, fine timebase (in picoseconds)
    {0, 1}
    // All others reserved
};


/////////////////////////
// Non-member function implementations
/////////////////////////
//
//  Why not static member functions? Literature states
//  that static member functions may reduce class
//  encapsulation, hence, non-member functions are preferred.
//  But I can be convinced otherwise - AAM
/////////////////////////

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
    fapi2::buffer<uint8_t> l_buffer(l_raw_byte);

    // Trace in the front assists w/ debug
    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    uint8_t l_bit_fields = 0;
    l_buffer.extractToRight<ENCODING_LEVEL_START, ENCODING_LEVEL_LEN>(l_bit_fields);

    // Check that value is valid
    constexpr size_t UNDEFINED = 0xF; // per JEDEC spec this value is undefined
    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              (l_bit_fields != UNDEFINED),
              BYTE_INDEX,
              l_raw_byte,
              "Failed check on SPD rev encoding level") );

    // Update output only after check passes
    o_value = l_bit_fields;

    // Print decoded info
    FAPI_DBG("%s. Rev - Encoding Level : %d",
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
    fapi2::buffer<uint8_t> l_buffer(l_raw_byte);

    // Trace in the front assists w/ debug
    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    uint8_t l_bit_fields = 0;
    l_buffer.extractToRight<ADDITIONS_LEVEL_START, ADDITIONS_LEVEL_LEN>(l_bit_fields);

    // Check that value is valid
    constexpr size_t UNDEFINED = 0xF; // per JEDEC spec this value is undefined
    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              (l_bit_fields != UNDEFINED),
              BYTE_INDEX,
              l_raw_byte,
              "Failed check on SPD rev encoding level") );

    // Update output only after check passes
    o_value = l_bit_fields;

    // Print decoded info
    FAPI_DBG("%s. Rev - Additions Level : %d",
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
    // Buffer used for bit manipulation
    constexpr size_t BYTE_INDEX = 3;
    uint8_t l_raw_byte  = i_spd_data[BYTE_INDEX];
    fapi2::buffer<uint8_t> l_spd_buffer(l_raw_byte);

    // Trace in the front assists w/ debug
    FAPI_DBG("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    uint8_t l_field_bits = 0;
    l_spd_buffer.extractToRight<BASE_MODULE_START, BASE_MODULE_LEN>(l_field_bits);

    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Check that value is valid
    bool l_is_val_found = find_value_from_key(BASE_MODULE_TYPE_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check on Base Module Type") );

    FAPI_DBG("%s. Base Module Type: %d",
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
    constexpr size_t BYTE_INDEX = 2;
    uint8_t l_raw_byte = i_spd_data[BYTE_INDEX];

    // Trace in the front assists w/ debug
    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
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
    FAPI_DBG("%s Device type : %d",
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
    uint8_t l_dimm_type = 0;
    uint8_t l_dimm_types_mcs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    uint8_t l_dram_gen = 0;
    uint8_t l_dram_gen_mcs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {};
    uint8_t l_encoding_rev = 0;
    uint8_t l_additions_rev = 0;

    const auto l_mcs = mss::find_target<TARGET_TYPE_MCS>(i_target);
    const auto l_port_num = index( find_target<TARGET_TYPE_MCA>(i_target) );
    const auto l_dimm_num = index(i_target);

    if( i_spd_data.empty() )
    {
        // This won't work with no data
        return fapi2::FAPI2_RC_INVALID_PARAMETER;
    }

    // Get dimm type & set attribute (needed by c_str)
    FAPI_TRY( base_module_type(i_target, i_spd_data, l_dimm_type),
              "Failed to find base module type" );
    FAPI_TRY( eff_dimm_type(l_mcs, &l_dimm_types_mcs[0][0]) );

    l_dimm_types_mcs[l_port_num][l_dimm_num] = l_dimm_type;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_TYPE, l_mcs, l_dimm_types_mcs) );

    // Get dram generation & set attribute (needed by c_str)
    FAPI_TRY( eff_dram_gen(l_mcs, &l_dram_gen_mcs[0][0]) );
    FAPI_TRY( dram_device_type(i_target, i_spd_data, l_dram_gen),
              "Failed to find base module type" );

    l_dram_gen_mcs[l_port_num][l_dimm_num] = l_dram_gen;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_GEN, l_mcs, l_dram_gen_mcs) );

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
                case 1:
                    switch(l_additions_rev)
                    {
                        case 0:
                        case 1:
                            // Rev 1.0 or Rev 1.1
                            o_fact_obj = std::make_shared<decoder>();
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

    // If we get here than a correct object reference obtained
    // Save off SPD data
    o_fact_obj->iv_spd_data = i_spd_data;

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

    for( const auto& l_mca : i_target.getChildren<TARGET_TYPE_MCA>() )
    {
        for( const auto& l_dimm : l_mca.getChildren<TARGET_TYPE_DIMM>() )
        {
            size_t l_size = 0;
            FAPI_TRY( getSPD(l_dimm, nullptr, l_size) );

            {
                // "Container" for SPD data
                std::vector<uint8_t> l_spd;
                l_spd.resize(l_size);

                // Retrive SPD data
                FAPI_TRY( getSPD(l_dimm, l_spd.data(), l_size)) ;

                // Retrieve factory object instance & populate spd data for that instance
                FAPI_TRY( factory(l_dimm, l_spd, l_pDecoder) );

                // Populate spd caches maps based on dimm pos
                o_factory_caches.emplace(std::make_pair(mss::pos(l_dimm), l_pDecoder));
            }

        }// end dimm
    }// end mca


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

    // This shouldn't be null so there is a specific decoder we are wanting to populate
    std::shared_ptr<decoder> l_pDecoder(i_pDecoder);

    // Custom decoder provided (usually done for testing)
    // Populate custom spd caches maps one dimm at a time
    o_factory_caches.emplace(std::make_pair( mss::pos(i_target), l_pDecoder) );

    // TK - else what do we want here
    return fapi2::FAPI2_RC_SUCCESS;
}

/////////////////////////
// Member Method implementation
/////////////////////////

///
/// @brief      Decodes number of used SPD bytes
/// @param[in]  i_target dimm target
/// @param[out] o_value number of SPD bytes used
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       Decodes SPD Byte 0 bits(0~3)
/// @note       Item JC-45-2220.01x
/// @note       Page 14
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::number_of_used_bytes(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint16_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 0;
    uint8_t l_raw_byte = iv_spd_data[BYTE_INDEX];

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    uint8_t l_field_bits = 0;
    fapi2::buffer<uint8_t> l_spd_buffer(l_raw_byte);
    l_spd_buffer.extractToRight<BYTES_USED_START, BYTES_USED_LEN>(l_field_bits);

    FAPI_DBG("Field_Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(BYTES_USED_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check on SPD used bytes") );

    FAPI_DBG("%s. Bytes Used: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decodes total number of SPD bytes
/// @param[in]  i_target dimm target
/// @param[out] o_value number of total SPD bytes
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       Decodes SPD Byte 0 (bits 4~6)
/// @note       Item JC-45-2220.01x
/// @note       Page 14
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::number_of_total_bytes(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint16_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 0;
    uint8_t l_raw_byte = iv_spd_data[BYTE_INDEX];

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    uint8_t l_field_bits = 0;
    fapi2::buffer<uint8_t> l_spd_buffer(l_raw_byte);
    l_spd_buffer.extractToRight<BYTES_TOTAL_START, BYTES_TOTAL_LEN>(l_field_bits);

    FAPI_DBG("Field_Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(BYTES_TOTAL_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check on SPD total bytes") );

    FAPI_DBG("%s. Total Bytes: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decodes hybrid media field from SPD
/// @param[in]  i_target
/// @param[out] o_value enum representing hybrid memory type
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       Decodes SPD Byte 3 (bits 4~6)
/// @note       Item JC-45-2220.01x
/// @note       Page 17
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::hybrid_media(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                        uint8_t& o_value)

{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 3;
    uint8_t l_raw_byte  = iv_spd_data[BYTE_INDEX];

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    uint8_t l_field_bits = 0;
    fapi2::buffer<uint8_t> l_spd_buffer(l_raw_byte);
    l_spd_buffer.extractToRight<HYBRID_MEDIA_START, HYBRID_MEDIA_LEN>(l_field_bits);

    FAPI_DBG("Field_Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(HYBRID_MEDIA_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check on Hybrid Media type") );

    FAPI_DBG("%s. Hybrid Media: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decodes hybrid field from SPD
/// @param[in]  i_target
/// @param[out] o_value enum representing if module is hybrid
/// @return     fapi2::ReturnCode
/// @note       Decodes SPD Byte 3 (bit 7)
/// @note       Item JC-45-2220.01x
/// @note       Page 17
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::hybrid(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                  uint8_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 3;
    uint8_t l_raw_byte  = iv_spd_data[BYTE_INDEX];

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    uint8_t l_field_bits = 0;
    fapi2::buffer<uint8_t> l_spd_buffer(l_raw_byte);
    l_spd_buffer.extractToRight<HYBRID_START, HYBRID_LEN>(l_field_bits);

    FAPI_DBG("Field_Bits value: %d", l_field_bits);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              mss::find_value_from_key(HYBRID_MAP, l_field_bits, o_value),
              BYTE_INDEX,
              l_field_bits,
              "Failed check on hybrid field") );

    FAPI_DBG("%s. Hybrid: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decodes SDRAM density from SPD
/// @param[in]  i_target dimm target
/// @param[out] o_value SDRAM density in GBs
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 4 (bits 0~3)
/// @note       Item JC-45-2220.01x
/// @note       Page 18
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::sdram_density(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)

{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 4;
    uint8_t l_raw_byte  = iv_spd_data[BYTE_INDEX];

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    uint8_t l_field_bits = 0;
    fapi2::buffer<uint8_t> l_spd_buffer(iv_spd_data[BYTE_INDEX]);
    l_spd_buffer.extractToRight<SDRAM_CAPACITY_START, SDRAM_CAPACITY_LEN>(l_field_bits);

    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Check to assure SPD DRAM capacity (map) wont be at invalid values
    bool l_is_val_found = mss::find_value_from_key(SDRAM_DENSITY_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for SPD DRAM capacity") );
    FAPI_DBG("%s. SDRAM density: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decodes number of SDRAM banks from SPD
/// @param[in]  i_target dimm target
/// @param[out] o_value Number of SDRAM banks
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 4 (bits 4~5)
/// @note       Item JC-45-2220.01x
/// @note       Page 18
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::banks(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                 uint8_t& o_value)

{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 4;
    uint8_t l_raw_byte  = iv_spd_data[BYTE_INDEX];

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    uint8_t l_field_bits = 0;
    fapi2::buffer<uint8_t> l_spd_buffer(iv_spd_data[BYTE_INDEX]);
    l_spd_buffer.extractToRight<SDRAM_BANKS_START, SDRAM_BANKS_LEN>(l_field_bits);

    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Check to assure SPD DRAM capacity (map) wont be at invalid values
    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              mss::find_value_from_key(BANK_ADDR_BITS_MAP, l_field_bits, o_value),
              BYTE_INDEX,
              l_field_bits,
              "Failed check for SPD DRAM banks") );

    FAPI_DBG("%s. Banks: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decodes number of SDRAM bank groups from SPD
/// @param[in]  i_target dimm target
/// @param[out] o_value Number of SDRAM bank groups
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 4 (bits 6~7)
/// @note       Item JC-45-2220.01x
/// @note       Page 18
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::bank_groups(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                       uint8_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 4;
    uint8_t l_raw_byte  = iv_spd_data[BYTE_INDEX];

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    uint8_t l_field_bits = 0;
    fapi2::buffer<uint8_t> l_spd_buffer(iv_spd_data[BYTE_INDEX]);
    l_spd_buffer.extractToRight<BANK_GROUP_START, BANK_GROUP_LEN>(l_field_bits);

    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Check to assure SPD DRAM capacity (map) wont be at invalid values
    bool l_is_val_found = mss::find_value_from_key(BANK_GROUP_BITS_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for SPD DRAM bank groups") );
    FAPI_DBG("%s. Bank Groups: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decodes number of SDRAM column address bits
/// @param[in]  i_target dimm target
/// @param[out] o_value number of column address bits
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 5 (bits 2~0)
/// @note       Item JC-45-2220.01x
/// @note       Page 18
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::column_address_bits(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 5;
    uint8_t l_raw_byte  = iv_spd_data[BYTE_INDEX];

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    uint8_t l_field_bits = 0;
    fapi2::buffer<uint8_t> l_spd_buffer(iv_spd_data[BYTE_INDEX]);
    l_spd_buffer.extractToRight<COL_ADDRESS_START, COL_ADDRESS_LEN>(l_field_bits);

    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Check to assure SPD DRAM capacity (map) wont be at invalid values
    bool l_is_val_found = mss::find_value_from_key(COLUMN_ADDRESS_BITS_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for SDRAM Column Address Bits") );

    FAPI_DBG("%s. Number of Column Address Bits: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decodes number of SDRAM row address bits
/// @param[in]  i_target dimm target
/// @param[out] o_value number of row address bits
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 5 (bits 5~3)
/// @note       Item JC-45-2220.01x
/// @note       Page 18
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::row_address_bits(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 5;
    uint8_t l_raw_byte  = iv_spd_data[BYTE_INDEX];

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    uint8_t l_field_bits = 0;
    fapi2::buffer<uint8_t> l_spd_buffer(iv_spd_data[BYTE_INDEX]);
    l_spd_buffer.extractToRight<ROW_ADDRESS_START, ROW_ADDRESS_LEN>(l_field_bits);

    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Check to assure SPD DRAM capacity (map) wont be at invalid values
    bool l_is_val_found = mss::find_value_from_key(ROW_ADDRESS_BITS_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd:: fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for SDRAM Row Address Bits") );

    FAPI_DBG("%s. Number of Row Address Bits: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief      Decodes Primary SDRAM signal loading
/// @param[in]  i_target dimm target
/// @param[out] o_value enum representing signal loading type
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 6 (bits 1~0)
/// @note       Item JC-45-2220.01x
/// @note       Page 19
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::prim_sdram_signal_loading(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 6;
    uint8_t l_raw_byte  = iv_spd_data[BYTE_INDEX];

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    uint8_t l_field_bits = 0;
    fapi2::buffer<uint8_t> l_spd_buffer(l_raw_byte);
    l_spd_buffer.extractToRight<PRIM_SIGNAL_LOAD_START, PRIM_SIGNAL_LOAD_LEN>(l_field_bits);

    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(PRIM_SIGNAL_LOADING_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd:: fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for Primary SDRAM Signal Loading") );

    FAPI_DBG("%s. Primary SDRAM Signal Loading: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decodes Primary SDRAM die count
/// @param[in]  i_target dimm target
/// @param[out] o_value die count
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 6 (bits 6~4)
/// @note       Item JC-45-2220.01x
/// @note       Page 19
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::prim_sdram_die_count(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 6;
    uint8_t l_raw_byte  = iv_spd_data[BYTE_INDEX];

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    uint8_t l_field_bits = 0;
    fapi2::buffer<uint8_t> l_spd_buffer(l_raw_byte);
    l_spd_buffer.extractToRight<PRIM_DIE_COUNT_START, PRIM_DIE_COUNT_LEN>(l_field_bits);

    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(PRIM_DIE_COUNT_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd:: fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for SDRAM Row Address Bits") );

    FAPI_DBG("%s. Number of Row Address Bits: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decodes Primary SDRAM  package type
/// @param[in]  i_target dimm target
/// @param[out] o_value enum representing package type
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 6 (bit 7)
/// @note       Item JC-45-2220.01x
/// @note       Page 19
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::prim_sdram_package_type(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 6;
    uint8_t l_raw_byte  = iv_spd_data[BYTE_INDEX];

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    uint8_t l_field_bits = 0;
    fapi2::buffer<uint8_t> l_spd_buffer(l_raw_byte);
    l_spd_buffer.extractToRight<PRIM_PACKAGE_TYPE_START, PRIM_PACKAGE_TYPE_LEN>(l_field_bits);

    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(PRIM_PACKAGE_TYPE_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for SDRAM Row Address Bits") );

    FAPI_DBG("%s. Number of Row Address Bits: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief      Decode SDRAM Maximum activate count
/// @param[in]  i_target dimm target
/// @param[out] o_value enum representing max activate count
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 7 (bits 3~0)
/// @note       Item JC-45-2220.01x
/// @note       Page 20
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::maximum_activate_count(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint32_t& o_value)
{
    // Buffer used for bit manipulation
    constexpr size_t BYTE_INDEX = 7;
    uint8_t l_raw_byte  = iv_spd_data[BYTE_INDEX];

    // Trace in the front assists w/ debug
    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    uint8_t l_field_bits = 0;
    fapi2::buffer<uint8_t> l_spd_buffer(l_raw_byte);
    l_spd_buffer.extractToRight<MAC_START, MAC_LEN>(l_field_bits);

    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(MAC_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for SDRAM Maximum Active Count (MAC)") );

    FAPI_DBG("%s. Maximum Active Count (MAC): %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decode SDRAM Maximum activate window (multiplier), tREFI uknown at this point
/// @param[in]  i_target dimm target
/// @param[out] o_value max activate window multiplier
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 7 (bits 3~0)
/// @note       Item JC-45-2220.01x
/// @note       Page 20
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::maximum_activate_window_multiplier(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint32_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 7;
    uint8_t l_raw_byte  = iv_spd_data[BYTE_INDEX];

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    uint8_t l_field_bits = 0;
    fapi2::buffer<uint8_t> l_spd_buffer(l_raw_byte);
    l_spd_buffer.extractToRight<TMAW_START, TMAW_LEN>(l_field_bits);

    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(TMAW_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for Maximum Active Window (tMAW)") );

    FAPI_DBG("%s. Maximum Active Window multiplier: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decode Soft post package repair (soft PPR)
/// @param[in]  i_target dimm target
/// @param[out] o_value enum representing if soft PPR is supported
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 9 (bit 5)
/// @note       Item JC-45-2220.01x
/// @note       Page 21
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::soft_post_package_repair(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 9;
    uint8_t l_raw_byte  = iv_spd_data[BYTE_INDEX];

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    uint8_t l_field_bits = 0;
    fapi2::buffer<uint8_t> l_spd_buffer(l_raw_byte);
    l_spd_buffer.extractToRight<SOFT_PPR_START, SOFT_PPR_LEN>(l_field_bits);

    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(SOFT_PPR_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd:: fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for Soft PPR") );

    FAPI_DBG("%s. Soft Post Package Repair (Soft PPR): %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decode Post package repair (PPR)
/// @param[in]  i_target dimm target
/// @param[out] o_value enum representing if (hard) PPR is supported
/// @return     fapi2::ReturnCode
/// @note       SPD Byte 9 (bits 7~6)
/// @note       Item JC-45-2220.01x
/// @note       Page 21
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::post_package_repair(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // Buffer used for bit manipulation
    constexpr size_t BYTE_INDEX = 9;
    uint8_t l_raw_byte  = iv_spd_data[BYTE_INDEX];
    fapi2::buffer<uint8_t> l_spd_buffer(l_raw_byte);

    // Trace in the front assists w/ debug
    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    uint8_t l_field_bits = 0;
    l_spd_buffer.extractToRight<PPR_START, PPR_LEN>(l_field_bits);

    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(PPR_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for PPR") );

    FAPI_DBG("%s. Post Package Repair (PPR): %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief      Decodes Secondary SDRAM signal loading
/// @param[in]  i_target dimm target
/// @param[out] o_value enum representing signal loading type
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 10 (bits 1~0)
/// @note       Item JC-45-2220.01x
/// @note       Page 22
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::sec_sdram_signal_loading(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 10;
    uint8_t l_raw_byte  = iv_spd_data[BYTE_INDEX];

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    uint8_t l_field_bits = 0;
    fapi2::buffer<uint8_t> l_spd_buffer(l_raw_byte);
    l_spd_buffer.extractToRight<SEC_SIGNAL_LOAD_START, SEC_SIGNAL_LOAD_LEN>(l_field_bits);

    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(SEC_SIGNAL_LOADING_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for SDRAM Row Address Bits") );

    FAPI_DBG("%s. Number of Row Address Bits: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decodes Secondary DRAM Density Ratio
/// @param[in]  i_target dimm target
/// @param[out] o_value raw bits from SPD
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 10 (bits 3~2)
/// @note       Item JC-45-2220.01x
/// @note       Page 22
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::sec_dram_density_ratio(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // Buffer used for bit manipulation
    constexpr size_t BYTE_INDEX = 10;
    uint8_t l_raw_byte  = iv_spd_data[BYTE_INDEX];

    // Trace in the front assists w/ debug
    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    uint8_t l_field_bits = 0;
    fapi2::buffer<uint8_t> l_spd_buffer(l_raw_byte);
    l_spd_buffer.extractToRight<DENSITY_RATIO_START, DENSITY_RATIO_LEN>(l_field_bits);

    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Find map value
    constexpr size_t UNDEFINED = 3; // JEDEC map doesn't go beyond 3

    FAPI_TRY( mss::check::spd:: fail_for_invalid_value(i_target,
              l_field_bits < UNDEFINED,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for DRAM Density Ratio") );

    FAPI_DBG("%s. DRAM Density Ratio: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief      Decodes Secondary SDRAM die count
/// @param[in]  i_target dimm target
/// @param[out] o_value die count
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 10 (bits 6~4)
/// @note       Item JC-45-2220.01x
/// @note       Page 22
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::sec_sdram_die_count(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // Buffer used for bit manipulation
    constexpr size_t BYTE_INDEX = 5;
    uint8_t l_raw_byte  = iv_spd_data[BYTE_INDEX];
    fapi2::buffer<uint8_t> l_spd_buffer(l_raw_byte);

    // Trace in the front assists w/ debug
    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    uint8_t l_field_bits = 0;
    l_spd_buffer.extractToRight<SEC_DIE_COUNT_START, SEC_DIE_COUNT_LEN>(l_field_bits);

    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(SEC_DIE_COUNT_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for Secondary Die Count") );

    FAPI_DBG("%s. Secondary Die Count: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decodes Secondary SDRAM package type
/// @param[in]  i_target dimm target
/// @param[out] o_value  enum representing package type
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 10 (bit 7)
/// @note       Item JC-45-2220.01x
/// @note       Page 22
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::sec_sdram_package_type(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // Buffer used for bit manipulation
    constexpr size_t BYTE_INDEX = 5;
    uint8_t l_raw_byte  = iv_spd_data[BYTE_INDEX];

    // Trace in the front assists w/ debug
    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    uint8_t l_field_bits = 0;
    fapi2::buffer<uint8_t> l_spd_buffer(l_raw_byte);
    l_spd_buffer.extractToRight<SEC_PACKAGE_TYPE_START, SEC_PACKAGE_TYPE_LEN>(l_field_bits);

    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(SEC_PACKAGE_TYPE_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for Secondary Package Type") );

    FAPI_DBG("%s. Secondary Package Type: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief      Decode Module Nominal Voltage, VDD
/// @param[in]  i_target dimm target
/// @param[out] o_value enum representing if 1.2V is operable
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 11 (bit 0)
/// @note       Item JC-45-2220.01x
/// @note       Page 23
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::operable_nominal_voltage(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 11;
    uint8_t l_raw_byte  = iv_spd_data[BYTE_INDEX];

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    uint8_t l_field_bits = 0;
    fapi2::buffer<uint8_t> l_spd_buffer(l_raw_byte);
    l_spd_buffer.extractToRight<OPERABLE_START, OPERABLE_LEN>(l_field_bits);

    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(OPERABLE_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for Operable nominal voltage") );

    FAPI_DBG("%s. Operable: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decode Module Nominal Voltage, VDD
/// @param[in]  i_target dimm target
/// @param[out] o_value enum representing if 1.2V is endurant
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 11 (bit 1)
/// @note       Item JC-45-2220.01x
/// @note       Page 23
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::endurant_nominal_voltage(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 11;
    uint8_t l_raw_byte  = iv_spd_data[BYTE_INDEX];

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    uint8_t l_field_bits = 0;
    fapi2::buffer<uint8_t> l_spd_buffer(l_raw_byte);
    l_spd_buffer.extractToRight<ENDURANT_START, ENDURANT_LEN>(l_field_bits);

    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(ENDURANT_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for Endurant nominal voltage") );

    FAPI_DBG("%s. Endurant: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decodes SDRAM device width
/// @param[in]  i_target dimm target
/// @param[out] o_value device width in bits
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 12 (bits 2~0)
/// @note       Item JC-45-2220.01x
/// @note       Page 23
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::device_width(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                        uint8_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 12;
    uint8_t l_raw_byte  = iv_spd_data[BYTE_INDEX];

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    fapi2::buffer<uint8_t> l_spd_buffer(l_raw_byte);
    uint8_t l_field_bits = 0;
    l_spd_buffer.extractToRight<SDRAM_WIDTH_START, SDRAM_WIDTH_LEN>(l_field_bits);

    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(DEVICE_WIDTH_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for Device Width") );

    FAPI_DBG("%s. Device Width: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief      Decodes number of package ranks per DIMM
/// @param[in]  i_target dimm target
/// @param[out] o_value number of package ranks per DIMM
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 12 (bits 5~3)
/// @note       Item JC-45-2220.01x
/// @note       Page 23
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::num_package_ranks_per_dimm(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 12;
    uint8_t l_raw_byte  = iv_spd_data[BYTE_INDEX];

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    fapi2::buffer<uint8_t> l_spd_buffer(l_raw_byte);
    uint8_t l_field_bits = 0;

    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(NUM_PACKAGE_RANKS_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for Num Package Ranks Per DIMM") );

    FAPI_DBG("%s. Num Package Ranks per DIMM: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decodes Rank Mix
/// @param[in]  i_target dimm target
/// @param[out] o_value rank mix value from SPD
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 12 (bit 6)
/// @note       Item JC-45-2220.01x
/// @note       Page 23
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::rank_mix(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                    uint8_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 12;
    uint8_t l_raw_byte  = iv_spd_data[BYTE_INDEX];

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    uint8_t l_field_bits = 0;
    fapi2::buffer<uint8_t> l_spd_buffer(l_raw_byte);
    l_spd_buffer.extractToRight<RANK_MIX_START, RANK_MIX_LEN>(l_field_bits);

    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Find map value
    constexpr size_t INVALID_VALUE = 2;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              (l_field_bits < INVALID_VALUE),
              BYTE_INDEX,
              l_field_bits,
              "Failed check for Rank Mix") );

    // Update output after check passes
    o_value = l_field_bits;

    FAPI_DBG("%s. Rank Mix: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief      Decodes primary bus width
/// @param[in]  i_target dimm target
/// @param[out] o_value primary bus width in bits
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 13 (bits 2~0)
/// @note       Item JC-45-2220.01x
/// @note       Page 27
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::prim_bus_width(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{

    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 13;
    uint8_t l_raw_byte  = iv_spd_data[BYTE_INDEX];

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    fapi2::buffer<uint8_t> l_spd_buffer(l_raw_byte);
    uint8_t l_field_bits = 0;
    l_spd_buffer.extractToRight<BUS_WIDTH_START, BUS_WIDTH_LEN>(l_field_bits);

    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(BUS_WIDTH_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for Primary Bus Width") );

    FAPI_DBG("%s. Primary Bus Width: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decodes bus width extension
/// @param[in]  i_target dimm target
/// @param[out] o_value bus width extension in bits
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 13 (bits 2~0)
/// @note       Item JC-45-2220.01x
/// @note       Page 28
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::bus_width_extension(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 13;
    uint8_t l_raw_byte  = iv_spd_data[BYTE_INDEX];

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    uint8_t l_field_bits = 0;
    fapi2::buffer<uint8_t> l_spd_buffer(l_raw_byte);
    l_spd_buffer.extractToRight<BUS_EXT_WIDTH_START, BUS_EXT_WIDTH_LEN>(l_field_bits);

    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(BUS_WIDTH_EXT_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for Bus Width Extension") );

    FAPI_DBG("%s. Bus Width Extension (bits): %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief      Decode Module Thermal Sensor
/// @param[in]  i_target dimm target
/// @param[out] o_value thermal sensor value from SPD
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 14 (bit 7)
/// @note       Item JC-45-2220.01x
/// @note       Page 28
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::thermal_sensor(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 14;
    uint8_t l_raw_byte  = iv_spd_data[BYTE_INDEX];

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    uint8_t l_field_bits = 0;
    fapi2::buffer<uint8_t> l_spd_buffer(l_raw_byte);
    l_spd_buffer.extractToRight<THERM_SENSOR_START, THERM_SENSOR_LEN>(l_field_bits);

    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Check for valid value
    constexpr size_t INVALID_VALUE = 2; // single bit value 0 or 1
    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_field_bits < INVALID_VALUE,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for Thermal Sensor") );

    // Update output after check passes
    o_value = l_field_bits;

    FAPI_DBG("%s. Thermal Sensor: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decode Extended Base Module Type
/// @param[in]  i_target dimm target
/// @param[out] o_value raw data from SPD
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 15 (bits 3~0)
/// @note       Item JC-45-2220.01x
/// @note       Page 28
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::extended_base_module_type(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 15;
    uint8_t l_raw_byte  = iv_spd_data[BYTE_INDEX];

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    uint8_t l_field_bits = 0;
    fapi2::buffer<uint8_t> l_spd_buffer(l_raw_byte);

    l_spd_buffer.extractToRight<EXT_MOD_TYPE_START, EXT_MOD_TYPE_LEN>(l_field_bits);

    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Check for valid value
    // Currently reserved to 0b000
    constexpr size_t RESERVED = 0;
    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_field_bits == RESERVED,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for Extended Base Module Type") );

    // Update output for check passes
    o_value = l_field_bits;

    FAPI_DBG("%s. Extended Base Module Type: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief      Decode Fine Timebase
/// @param[in]  i_target dimm target
/// @param[out] o_value fine_timebase from SPD in picoseconds
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 17 (bits 1~0)
/// @note       Item JC-45-2220.01x
/// @note       Page 29
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::fine_timebase(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 17;
    uint8_t l_raw_byte  = iv_spd_data[BYTE_INDEX];

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    uint8_t l_field_bits = 0;
    fapi2::buffer<uint8_t> l_spd_buffer(l_raw_byte);
    l_spd_buffer.extractToRight<FINE_TIMEBASE_START, FINE_TIMEBASE_LEN>(l_field_bits);

    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(FINE_TIMEBASE_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for Fine Timebase") );

    FAPI_DBG("%s. Fine Timebase: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decode Medium Timebase
/// @param[in]  i_target dimm target
/// @param[out] o_value  medium timebase from SPD in picoseconds
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 17 (bits 3~2)
/// @note       Item JC-45-2220.01x
/// @note       Page 29
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::medium_timebase(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 17;
    uint8_t l_raw_byte  = iv_spd_data[BYTE_INDEX];

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_raw_byte);

    // Extracting desired bits
    uint8_t l_field_bits = 0;
    fapi2::buffer<uint8_t> l_spd_buffer(l_raw_byte);
    l_spd_buffer.extractToRight<MED_TIMEBASE_START, MED_TIMEBASE_LEN>(l_field_bits);

    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(MEDIUM_TIMEBASE_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for Medium Timebase") );

    FAPI_DBG("%s. Medium Timebase: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief      Decodes SDRAM Minimum Cycle Time in MTB
/// @param[in]  i_target dimm target
/// @param[out] o_value tCKmin in MTB units
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 18
/// @note       Item JC-45-2220.01x
/// @note       Page 31-32
/// @note       DDR4 SPD Document Release 3
/// @warning    If tCKmin cannot be divided evenly by the MTB,
///             this byte must be rounded up to the next larger
///             integer and the Fine Offset for tCKmin (SPD byte 125)
///             used for correction to get the actual value.
///
fapi2::ReturnCode decoder::min_cycle_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // Explicit conversion
    constexpr size_t BYTE_INDEX = 18;
    int64_t l_timing_val = int64_t(iv_spd_data[BYTE_INDEX]);

    // Trace in the front assists w/ debug
    FAPI_DBG("%s SPD data at Byte %d: %d.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_timing_val);

    // Check if value is valid
    constexpr int64_t TIMING_LOWER_BOUND = 1; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 255; // from JEDEC

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             BYTE_INDEX,
             l_timing_val,
             "Failed check on the min cycle time (tckmin) in MTB") );

    // Update output after check passes
    o_value = l_timing_val;

    FAPI_DBG("%s. Minimum Cycle Time (tCKmin) in MTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decodes SDRAM Maximum Cycle Time in MTB
/// @param[in]  i_target dimm target
/// @param[out] o_value tCKmax in MTB units
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 19
/// @note       Item JC-45-2220.01x
/// @note       Page 32
/// @note       DDR4 SPD Document Release 3
/// @warning    If tCKmax cannot be divided evenly by the MTB,
///             this byte must be rounded up to the next larger
///             integer and the Fine Offset for tCKmax (SPD byte 124)
///             used for correction to get the actual value.
///
fapi2::ReturnCode decoder::max_cycle_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // Explicit conversion
    constexpr size_t BYTE_INDEX = 19;
    int64_t l_timing_val = int64_t(iv_spd_data[BYTE_INDEX]);

    // Trace in the front assists w/ debug
    FAPI_DBG("%s SPD data at Byte %d: %d.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_timing_val);

    // Check for valid value
    constexpr int64_t TIMING_LOWER_BOUND = 1; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 255; // from JEDEC

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             BYTE_INDEX,
             l_timing_val,
             "Failed check on the max cycle time (tckmax) in MTB") );

    // Update output after check passes
    o_value = l_timing_val;

    FAPI_DBG("%s. Maximum Cycle Time (tCKmax) in MTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief      Decode CAS Latencies Supported
/// @param[in]  i_target dimm target
/// @param[out] o_value bitmap of supported CAS latencies
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Bytes 20-23
/// @note       Item JC-45-2220.01x
/// @note       Page 33-34
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::supported_cas_latencies(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint64_t& o_value)
{
    // Trace print in the front assists w/ debug
    constexpr size_t FIRST_BYTE = 20;
    uint8_t first_raw_byte = iv_spd_data[FIRST_BYTE];
    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             c_str(i_target),
             FIRST_BYTE,
             first_raw_byte);

    constexpr size_t SEC_BYTE = 21;
    uint8_t sec_raw_byte = iv_spd_data[SEC_BYTE];
    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             c_str(i_target),
             SEC_BYTE,
             sec_raw_byte);

    constexpr size_t THIRD_BYTE = 22;
    uint8_t third_raw_byte = iv_spd_data[THIRD_BYTE];
    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             c_str(i_target),
             THIRD_BYTE,
             third_raw_byte);

    constexpr size_t FOURTH_BYTE = 23;
    uint8_t fourth_raw_byte = iv_spd_data[FOURTH_BYTE];
    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             c_str(i_target),
             FOURTH_BYTE,
             fourth_raw_byte);

    // Buffers used for bit manipulation
    // Combine Bytes to create bitmap - right aligned
    fapi2::buffer<uint64_t> l_buffer;

    l_buffer.insertFromRight<CAS_BYTE_1_START, CAS_BYTE_1_LEN>(first_raw_byte)
    .insertFromRight<CAS_BYTE_2_START, CAS_BYTE_2_LEN>(sec_raw_byte)
    .insertFromRight<CAS_BYTE_3_START, CAS_BYTE_3_LEN>(third_raw_byte)
    .insertFromRight<CAS_BYTE_4_START, CAS_BYTE_4_LEN>(fourth_raw_byte);

    // According to the JEDEC spec:
    // Byte 23 bit 6 is reserved and must be coded as 0.
    // Should we warn instead of fail because in last revision this was a reserved byte coded as 0x00
    constexpr size_t BIT_START = 33; // relative position of bit 6 in byte 23 relative to uint64_t
    constexpr size_t BIT_LEN = 1;
    constexpr size_t OUTPUT_START = 0;
    constexpr size_t OUTPUT_LEN  = 64;

    // Check for a valid value
    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              !(l_buffer.getBit<BIT_START, BIT_LEN>()),
              FOURTH_BYTE,
              fourth_raw_byte,
              "Failed check on CAS latencies supported") );

    // Update output value only if range check passes
    l_buffer.extractToRight<OUTPUT_START, OUTPUT_LEN>(o_value);

    FAPI_DBG("%s. CAS latencies supported (bitmap): 0x%llX",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief      Decodes SDRAM Minimum CAS Latency Time in MTB
/// @param[in]  i_target dimm target
/// @param[out] o_value tAAmin in MTB units
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 24
/// @note       Item JC-45-2220.01x
/// @note       Page 34
/// @note       DDR4 SPD Document Release 3
/// @warning    If tAAmin cannot be divided evenly by the MTB,
///             this byte must be rounded up to the next larger
///             integer and the Fine Offset for tAAmin (SPD byte 123)
///             used for correction to get the actual value.
///
fapi2::ReturnCode decoder::min_cas_latency_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // Explicit conversion
    constexpr size_t BYTE_INDEX = 24;
    int64_t l_timing_val = int64_t(iv_spd_data[BYTE_INDEX]);

    // Trace in the front assists w/ debug
    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_timing_val);

    // Check for valid value
    constexpr int64_t TIMING_LOWER_BOUND = 1; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 255; // from JEDEC

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             BYTE_INDEX,
             l_timing_val,
             "Failed check on the Minimum CAS Latency Time (tAAmin) in MTB") );

    // Only update output if it passes check
    o_value = l_timing_val;

    FAPI_DBG("%s. Minimum CAS Latency Time (tAAmin) in MTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decodes SDRAM Minimum RAS to CAS Delay Time in MTB
/// @param[in]  i_target dimm target
/// @param[out] o_value tRCDmin in MTB units
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 25
/// @note       Item JC-45-2220.01x
/// @note       Page 35
/// @note       DDR4 SPD Document Release 3
/// @warning    If tRCDmin cannot be divided evenly by the MTB,
///             this byte must be rounded up to the next larger
///             integer and the Fine Offset for tRCDmin (SPD byte 122)
///             used for correction to get the actual value
///
fapi2::ReturnCode decoder::min_ras_to_cas_delay_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,

        int64_t& o_value)
{
    // Explicit conversion
    constexpr size_t BYTE_INDEX = 25;
    int64_t l_timing_val = int64_t(iv_spd_data[BYTE_INDEX]);

    // Trace in the front assists w/ debug
    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_timing_val);

    // Find valid value
    constexpr int64_t TIMING_LOWER_BOUND = 1; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 255; // from JEDEC

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             BYTE_INDEX,
             l_timing_val,
             "Failed check on the Minimum RAS to CAS Delay Time (tRCDmin) in MTB") );

    // Only update output if it passes check
    o_value = l_timing_val;

    FAPI_DBG("%s. Minimum RAS to CAS Delay Time (tRCDmin) in MTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decodes SDRAM Minimum Row Precharge Delay Time in MTB
/// @param[in]  i_target dimm target
/// @param[out] o_value tRPmin in MTB units
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 26
/// @note       Item JC-45-2220.01x
/// @note       Page 36-37
/// @note       DDR4 SPD Document Release 3
/// @warning    If tRPmin cannot be divided evenly by the MTB,
//              this byte must be rounded up to the next larger
///             integer and the Fine Offset for tRPmin (SPD byte 121)
///             used for correction to get the actual value
///
fapi2::ReturnCode decoder::min_row_precharge_delay_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // Explicit conversion
    constexpr size_t BYTE_INDEX = 26;
    int64_t l_timing_val = int64_t(iv_spd_data[BYTE_INDEX]);

    // Trace in the front assists w/ debug
    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_timing_val);

    // Check for valid value
    constexpr int64_t TIMING_LOWER_BOUND = 1; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 255; // from JEDEC

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             BYTE_INDEX,
             l_timing_val,
             "Failed check on the Minimum Row Precharge Delay Time (tRPmin) in MTB") );

    // Only update output if it passes check
    o_value = l_timing_val;

    FAPI_DBG("%s. Minimum Row Precharge Delay Time (tRPmin) in MTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief      Decodes SDRAM Minimum Active to Precharge Delay Time in MTB
/// @param[in]  i_target dimm target
/// @param[out] o_value tRASmin in MTB units
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 27 (bits 3~0) & Byte 28 (bits 7~0)
/// @note       Item JC-45-2220.01x
/// @note       Page 38
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::min_active_to_precharge_delay_time(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // Lambda expression to retrieve tRASmin's most significant nibble (MSN)
    auto tRASmin_MSN = [](const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                          const std::vector<uint8_t>& i_data)
    {
        // Trace in the front assists w/ debug
        constexpr size_t BYTE_INDEX = 27;

        FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
                 mss::c_str(i_target),
                 BYTE_INDEX,
                 i_data[BYTE_INDEX]);

        // Extracting desired bits
        uint8_t l_out = 0;
        fapi2::buffer<uint8_t> l_buffer(i_data[BYTE_INDEX]);
        l_buffer.extractToRight<TRASMIN_MSN_START, TRASMIN_MSN_LEN>(l_out);

        return l_out;
    };

    // Lambda expression to retrieve tRASmin's least significant byte (LSB)
    auto tRASmin_LSB = [](const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                          const std::vector<uint8_t>& i_data)
    {
        // Trace in the front assists w/ debug
        constexpr size_t BYTE_INDEX = 28;

        FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
                 mss::c_str(i_target),
                 BYTE_INDEX,
                 i_data[BYTE_INDEX]);

        // Extracting desired bits
        uint8_t l_out = 0;
        fapi2::buffer<uint8_t> l_buffer(i_data[BYTE_INDEX]);
        l_buffer.extractToRight<TRASMIN_LSB_START, TRASMIN_LSB_LEN>(l_out);

        return l_out;
    };


    // Combining bits to create timing value (in a buffer)
    constexpr size_t MSN_START = 52;
    constexpr size_t MSN_LEN = 4;
    constexpr size_t LSB_START = 56;
    constexpr size_t LSB_LEN = 8;

    fapi2::buffer<int64_t> l_buffer;

    l_buffer.insertFromRight<MSN_START, MSN_LEN>( tRASmin_MSN(i_target, iv_spd_data) ).
    insertFromRight<LSB_START, LSB_LEN>( tRASmin_LSB(i_target, iv_spd_data) );

    // Extract timing value from the buffer into an integral type
    constexpr size_t OUTPUT_START = 0;
    constexpr size_t OUTPUT_LEN  = 64;
    int64_t l_timing_val = 0;

    l_buffer.extractToRight<OUTPUT_START, OUTPUT_LEN>(l_timing_val);

    // JEDEC spec limits for this timing value
    constexpr int64_t TIMING_LOWER_BOUND = 1; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 4095; // from JEDEC

    // best we can do?
    // I had to combine parts from two different bytes.
    // But byte 28 of the JEDEC spec explains how to piece this together - AAM
    constexpr size_t ERROR_BYTE_INDEX = 28;

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             ERROR_BYTE_INDEX,
             l_timing_val,
             "Failed check on the Minimum Active to Precharge Delay Time (tRASmin) in MTB") );

    // Update output only after check passes
    o_value = l_timing_val;

    FAPI_DBG("%s. Minimum Active to Precharge Delay Time (tRASmin) in MTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief      Decodes SDRAM Minimum Active to Active/Refresh Delay Time in MTB
/// @param[in]  i_target dimm target
/// @param[out] o_value tRCmin in MTB units
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 27 (bits 7~4) & SPD Byte 29 (bits 7~0)
/// @note       Item JC-45-2220.01x
/// @note       Page 38
/// @note       DDR4 SPD Document Release 3
/// @warning    If tRCmin cannot be divided evenly by the MTB,
///             this byte must be rounded up to the next larger
///             integer and the Fine Offset for tRCmin (SPD byte 120)
///             used for correction to get the actual value.
///
fapi2::ReturnCode decoder::min_active_to_active_refresh_delay_time(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // Lambda expression to retrieve tRCmin's most significant nibble (MSN)
    auto tRCmin_MSN = [](const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                         const std::vector<uint8_t>& i_data)
    {
        // Trace in the front assists w/ debug
        constexpr size_t BYTE_INDEX = 27;

        FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
                 mss::c_str(i_target),
                 BYTE_INDEX,
                 i_data[BYTE_INDEX]);

        // Extracting desired bits
        uint8_t l_out = 0;
        fapi2::buffer<uint8_t> l_buffer(i_data[BYTE_INDEX]);

        l_buffer.extractToRight<TRCMIN_MSN_START, TRCMIN_MSN_LEN>(l_out);

        return l_out;
    };

    // Lambda expression to retrieve tRCmin's least significant byte (LSB)
    auto tRCmin_LSB = [](const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                         const std::vector<uint8_t>& i_data)
    {
        // Trace in the front assists w/ debug
        constexpr size_t BYTE_INDEX = 29;

        FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
                 mss::c_str(i_target),
                 BYTE_INDEX,
                 i_data[BYTE_INDEX]);

        // Extracting desired bits
        uint8_t l_out = 0;
        fapi2::buffer<uint8_t> l_buffer(i_data[BYTE_INDEX]);
        l_buffer.extractToRight<TRCMIN_LSB_START, TRCMIN_LSB_LEN>(l_out);

        return l_out;
    };

    // Combining bits to create timing value (in a buffer)
    constexpr size_t MSN_START = 52;
    constexpr size_t MSN_LEN = 4;
    constexpr size_t LSB_START = 56;
    constexpr size_t LSB_LEN = 8;

    fapi2::buffer<int64_t> l_buffer;

    l_buffer.insertFromRight<MSN_START, MSN_LEN>( tRCmin_MSN(i_target, iv_spd_data) ).
    insertFromRight<LSB_START, LSB_LEN>( tRCmin_LSB(i_target, iv_spd_data) );

    // Extract timing value from the buffer into an integral type
    constexpr size_t OUTPUT_START = 0;
    constexpr size_t OUTPUT_LEN  = 64;
    int64_t l_timing_val = 0;

    l_buffer.extractToRight<OUTPUT_START, OUTPUT_LEN>(l_timing_val);

    // JEDEC spec limits for this timing value
    constexpr int64_t TIMING_LOWER_BOUND = 1; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 4095; // from JEDEC

    // best we can do?
    // I had to combine parts from two different bytes.
    // But byte 29 of the JEDEC spec explains how to piece this together - AAM
    constexpr size_t ERROR_BYTE_INDEX = 29;

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             ERROR_BYTE_INDEX,
             l_timing_val,
             "Failed check on the Minimum Active to Active/Refresh Delay Time (tRCmin) in MTB") );

    // Update output only after check passes
    o_value = l_timing_val;

    FAPI_DBG("%s. Minimum Active to Active/Refresh Delay Time (tRCmin) in MTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief      Decodes SDRAM Minimum Refresh Recovery Delay Time 1
/// @param[in]  i_target dimm target
/// @param[out] o_value tRFC1min in MTB units
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 30 & Byte 31
/// @note       Item JC-45-2220.01x
/// @note       Page 39-40
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::min_refresh_recovery_delay_time_1(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // Lambda expression to retrieve tRFC1min's most significant byte (MSB)
    auto tRFC1min_MSB = [](const fapi2::Target<TARGET_TYPE_DIMM>& i_target, const std::vector<uint8_t>& i_data)
    {
        // Trace in the front assists w/ debug
        constexpr size_t BYTE_INDEX = 31;

        FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
                 mss::c_str(i_target),
                 BYTE_INDEX,
                 i_data[BYTE_INDEX]);

        // Extracting desired bits
        uint8_t l_out = 0;
        fapi2::buffer<uint8_t> l_buffer(i_data[BYTE_INDEX]);

        l_buffer.extractToRight<TRFC1MIN_MSB_START, TRFC1MIN_MSB_LEN>(l_out);

        return l_out;
    };

    // Lambda expression to retrieve tRFC1min's least significant byte (LSB)
    auto tRFC1min_LSB = [](const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                           const std::vector<uint8_t>& i_data)
    {
        // Trace in the front assists w/ debug
        constexpr size_t BYTE_INDEX = 30;

        FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
                 mss::c_str(i_target),
                 BYTE_INDEX,
                 i_data[BYTE_INDEX]);

        // Extracting desired bits
        uint8_t l_out = 0;
        fapi2::buffer<uint8_t> l_buffer(i_data[BYTE_INDEX]);

        l_buffer.extractToRight<TRFC1MIN_LSB_START, TRFC1MIN_LSB_LEN>(l_out);

        return l_out;
    };

    // Combining bits to create timing value (in a buffer)
    constexpr size_t MSB_START = 48;
    constexpr size_t MSB_LEN = 8;
    constexpr size_t LSB_START = 56;
    constexpr size_t LSB_LEN = 8;

    fapi2::buffer<int64_t> l_buffer;

    l_buffer.insertFromRight<MSB_START, MSB_LEN>( tRFC1min_MSB(i_target, iv_spd_data) ).
    insertFromRight<LSB_START, LSB_LEN>( tRFC1min_LSB(i_target, iv_spd_data) );

    // Extract timing value from the buffer into an integral type
    constexpr size_t OUTPUT_START = 0;
    constexpr size_t OUTPUT_LEN  = 64;
    int64_t l_timing_val = 0;

    l_buffer.extractToRight<OUTPUT_START, OUTPUT_LEN>(l_timing_val);

    // JEDEC spec limits for this timing value
    constexpr int64_t TIMING_LOWER_BOUND = 1; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 65535; // from JEDEC

    // best we can do?
    // I had to combine parts from two different bytes.
    // Chose one of them (byte 30) to for error printout of this decode
    constexpr size_t ERROR_BYTE_INDEX = 30;

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             ERROR_BYTE_INDEX,
             l_timing_val,
             "Failed check on the Minimum Refresh Recovery Delay Time 1 (tRFC1min) in MTB") );

    // Update output only after check passes
    o_value = l_timing_val;

    FAPI_DBG("%s. Minimum Refresh Recovery Delay Time 1 (tRFC1min) in MTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decodes SDRAM Minimum Refresh Recovery Delay Time 2
/// @param[in]  i_target dimm target
/// @param[out] o_value tRFC2min in MTB units
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 32 & Byte 33
/// @note       Item JC-45-2220.01x
/// @note       Page 40
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::min_refresh_recovery_delay_time_2(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // Lambda expression to retrieve tRFC2min's most significant byte (MSB)
    auto tRFC2min_MSB = [](const fapi2::Target<TARGET_TYPE_DIMM>& i_target, const std::vector<uint8_t>& i_data)
    {
        // Trace in the front assists w/ debug
        constexpr size_t BYTE_INDEX = 33;

        FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
                 mss::c_str(i_target),
                 BYTE_INDEX,
                 i_data[BYTE_INDEX]);

        // Extracting desired bits
        uint8_t l_out = 0;
        fapi2::buffer<uint8_t> l_buffer(i_data[BYTE_INDEX]);
        l_buffer.extractToRight<TRFC2MIN_MSB_START, TRFC2MIN_MSB_LEN>(l_out);

        return l_out;
    };

    // Lambda expression to retrieve tRFC2min's least significant byte (LSB)
    auto tRFC2min_LSB = [](const fapi2::Target<TARGET_TYPE_DIMM>& i_target, const std::vector<uint8_t>& i_data)
    {
        // Trace in the front assists w/ debug
        constexpr size_t BYTE_INDEX = 32;

        FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
                 mss::c_str(i_target),
                 BYTE_INDEX,
                 i_data[BYTE_INDEX]);

        // Extracting desired bits
        uint8_t l_out = 0;
        fapi2::buffer<uint8_t> l_buffer(i_data[BYTE_INDEX]);

        l_buffer.extractToRight<TRFC2MIN_LSB_START, TRFC2MIN_LSB_LEN>(l_out);

        return l_out;
    };

    // Combining bits to create timing value (in a buffer)
    constexpr size_t MSB_START = 48;
    constexpr size_t MSB_LEN = 8;
    constexpr size_t LSB_START = 56;
    constexpr size_t LSB_LEN = 8;

    fapi2::buffer<int64_t> l_buffer;

    l_buffer.insertFromRight<MSB_START, MSB_LEN>( tRFC2min_MSB(i_target, iv_spd_data) ).
    insertFromRight<LSB_START, LSB_LEN>( tRFC2min_LSB(i_target, iv_spd_data) );

    // Extract timing value from the buffer into an integral type
    constexpr size_t OUTPUT_START = 0;
    constexpr size_t OUTPUT_LEN  = 64;
    int64_t l_timing_val = 0;

    l_buffer.extractToRight<OUTPUT_START, OUTPUT_LEN>(l_timing_val);

    // JEDEC spec limits for this timing value
    constexpr int64_t TIMING_LOWER_BOUND = 1; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 65535; // from JEDEC

    // best we can do?
    // I had to combine parts from two different bytes.
    // Chose one of them (byte 33) to for error printout of this decode
    constexpr size_t ERROR_BYTE_INDEX = 33;

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             ERROR_BYTE_INDEX,
             l_timing_val,
             "Failed check on the Minimum Refresh Recovery Delay Time 2 (tRFC2min) in MTB") );

    // Update output only after check passes
    o_value = l_timing_val;

    FAPI_DBG("%s. Minimum Refresh Recovery Delay Time 2 (tRFC2min) in MTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decodes SDRAM Minimum Refresh Recovery Delay Time 4
/// @param[in]  i_target dimm target
/// @param[out] o_value tRFC4min in MTB units
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 34 & Byte 35
/// @note       Item JC-45-2220.01x
/// @note       Page 40
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::min_refresh_recovery_delay_time_4(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // Lambda expression to retrieve tRFC4min's most significant byte (MSB)
    auto tRFC4min_MSB = [](const fapi2::Target<TARGET_TYPE_DIMM>& i_target, const std::vector<uint8_t>& i_data)
    {
        // Trace in the front assists w/ debug
        constexpr size_t BYTE_INDEX = 35;

        FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
                 mss::c_str(i_target),
                 BYTE_INDEX,
                 i_data[BYTE_INDEX]);

        // Extracting desired bits
        uint8_t l_out = 0;
        fapi2::buffer<uint8_t> l_buffer(i_data[BYTE_INDEX]);

        l_buffer.extractToRight<TRFC4MIN_MSB_START, TRFC4MIN_MSB_LEN>(l_out);

        return l_out;
    };

    // Lambda expression to retrieve tRFC4min's least significant byte (LSB)
    auto tRFC4min_LSB = [](const fapi2::Target<TARGET_TYPE_DIMM>& i_target, const std::vector<uint8_t>& i_data)
    {
        // Trace in the front assists w/ debug
        constexpr size_t BYTE_INDEX = 34;

        FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
                 mss::c_str(i_target),
                 BYTE_INDEX,
                 i_data[BYTE_INDEX]);

        // Extracting desired bits
        uint8_t l_out = 0;
        fapi2::buffer<uint8_t> l_buffer(i_data[BYTE_INDEX]);

        l_buffer.extractToRight<TRFC4MIN_LSB_START, TRFC4MIN_LSB_LEN>(l_out);

        return l_out;
    };

    // Combining bits to create timing value (in a buffer)
    constexpr size_t MSB_START = 48;
    constexpr size_t MSB_LEN = 8;
    constexpr size_t LSB_START = 56;
    constexpr size_t LSB_LEN = 8;

    fapi2::buffer<int64_t> l_buffer;

    l_buffer.insertFromRight<MSB_START, MSB_LEN>( tRFC4min_MSB(i_target, iv_spd_data) ).
    insertFromRight<LSB_START, LSB_LEN>( tRFC4min_LSB(i_target, iv_spd_data) );

    // Extract timing value from the buffer into an integral type
    constexpr size_t OUTPUT_START = 0;
    constexpr size_t OUTPUT_LEN  = 64;
    int64_t l_timing_val = 0;

    l_buffer.extractToRight<OUTPUT_START, OUTPUT_LEN>(l_timing_val);

    // JEDEC spec limits for this timing value
    constexpr int64_t TIMING_LOWER_BOUND = 1; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 65535; // from JEDEC

    // best we can do?
    // I had to combine parts from two different bytes.
    // Chose one of them (byte 34) for error printout of this decode
    constexpr size_t ERROR_BYTE_INDEX = 34;

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             ERROR_BYTE_INDEX,
             l_timing_val,
             "Failed check on the Minimum Refresh Recovery Delay Time 4 (tRFC4min) in MTB") );

    // Update output only after check passes
    o_value = l_timing_val;

    FAPI_DBG("%s. Minimum Refresh Recovery Delay Time 4 (tRFC4min) in MTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decodes SDRAM Minimum Four Activate Window Delay Time
/// @param[in]  i_target dimm target
/// @param[out] o_value tFAWmin in MTB units
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 36 (bits 3~0) & Byte 37 (bits 7~0)
/// @note       Item JC-45-2220.01x
/// @note       Page 42
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::min_tfaw(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                    int64_t& o_value)
{
    // Lambda expression to retrieve tFAWmin's most significant nibble (MSN)
    auto tFAWmin_MSN = [](const fapi2::Target<TARGET_TYPE_DIMM>& i_target, const std::vector<uint8_t>& i_data)
    {
        // Trace in the front assists w/ debug
        constexpr size_t BYTE_INDEX = 36;

        FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
                 mss::c_str(i_target),
                 BYTE_INDEX,
                 i_data[BYTE_INDEX]);

        // Extracting desired bits
        uint8_t l_out = 0;
        fapi2::buffer<uint8_t> l_buffer(i_data[BYTE_INDEX]);

        l_buffer.extractToRight<TFAWMIN_MSN_START, TFAWMIN_MSN_LEN>(l_out);

        return l_out;
    };

    // Lambda expression to retrieve tFAWmin's least significant byte (LSB)
    auto tFAWmin_LSB = [](const fapi2::Target<TARGET_TYPE_DIMM>& i_target, const std::vector<uint8_t>& i_data)
    {
        // Trace in the front assists w/ debug
        constexpr size_t BYTE_INDEX = 37;

        FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
                 mss::c_str(i_target),
                 BYTE_INDEX,
                 i_data[BYTE_INDEX]);

        // Extracting desired bits
        uint8_t l_out = 0;
        fapi2::buffer<uint8_t> l_buffer(i_data[BYTE_INDEX]);

        l_buffer.extractToRight<TFAWMIN_LSB_START, TFAWMIN_LSB_LEN>(l_out);

        return l_out;
    };

    // Combining bits to create timing value (in a buffer)
    constexpr size_t MSN_START = 52;
    constexpr size_t MSN_LEN = 4;
    constexpr size_t LSB_START = 56;
    constexpr size_t LSB_LEN = 8;

    fapi2::buffer<int64_t> l_buffer;

    l_buffer.insertFromRight<MSN_START, MSN_LEN>( tFAWmin_MSN(i_target, iv_spd_data) ).
    insertFromRight<LSB_START, LSB_LEN>( tFAWmin_LSB(i_target, iv_spd_data) );

    // Extract timing value from the buffer into an integral type
    constexpr size_t OUTPUT_START = 0;
    constexpr size_t OUTPUT_LEN  = 64;
    int64_t l_timing_val = 0;

    l_buffer.extractToRight<OUTPUT_START, OUTPUT_LEN>(l_timing_val);

    // JEDEC spec limits for this timing value
    constexpr int64_t TIMING_LOWER_BOUND = 1; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 65535; // from JEDEC

    // best we can do?
    // I had to combine parts from two different bytes.
    // Chose one of them (byte 37) to for error printout of this decode
    constexpr size_t ERROR_BYTE_INDEX = 37;

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             ERROR_BYTE_INDEX,
             l_timing_val,
             "Failed check on the Minimum Four Activate Window Delay Time (tFAWmin) in MTB") );

    // Update output only after check passes
    o_value = l_timing_val;

    FAPI_DBG("%s. Minimum Four Activate Window Delay Time (tFAWmin) in MTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decodes Minimum Activate to Activate Delay Time - Different Bank Group
/// @param[in]  i_target dimm target
/// @param[out] o_value tRRD_Smin MTB units
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 38
/// @note       Item JC-45-2220.01x
/// @note       Page 43
/// @note       DDR4 SPD Document Release 3
/// @warning    If tRRD_Smin cannot be divided evenly by the MTB,
///             this byte must be rounded up to the next larger
///             integer and the Fine Offset for tRRD_Smin (SPD byte 119)
///             used for correction to get the actual value.
///
fapi2::ReturnCode decoder::min_trrd_s(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                      int64_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 38;

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             iv_spd_data[BYTE_INDEX]);

    // Retrieve Minimum Activate to Activate Delay Time - Different Bank Group
    // explicit conversion to int64_t
    int64_t l_timing_val = int64_t(iv_spd_data[BYTE_INDEX]);

    // Find valid value
    constexpr int64_t TIMING_LOWER_BOUND = 1; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 255; // from JEDEC

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             BYTE_INDEX,
             l_timing_val,
             "Failed check on Minimum Activate to Activate Delay Time - Different Bank Group (tRRD_Smin) in MTB") );

    // Update output value only if range check passes
    o_value = l_timing_val;

    FAPI_DBG("%s. Minimum Activate to Activate Delay Time - Different Bank Group (tRRD_Smin) in MTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decodes Minimum Activate to Activate Delay Time - Same Bank Group
/// @param[in]  i_target dimm target
/// @param[out] o_value tRRD_Lmin MTB units
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 39
/// @note       Item JC-45-2220.01x
/// @note       Page 43-44
/// @note       DDR4 SPD Document Release 3
/// @warning    If tRRD_Lmin cannot be divided evenly by the MTB,
///             this byte must be rounded up to the next larger
///             integer and the Fine Offset for tRRD_Lmin (SPD byte 118)
///             used for correction to get the actual value.
///
fapi2::ReturnCode decoder::min_trrd_l(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                      int64_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 39;

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             iv_spd_data[BYTE_INDEX]);

    // Retrieve Minimum Activate to Activate Delay Time - Same Bank Group
    // explicit conversion to int64_t
    int64_t l_timing_val = int64_t(iv_spd_data[BYTE_INDEX]);

    // Find valid value
    constexpr int64_t TIMING_LOWER_BOUND = 1; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 255; // from JEDEC

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             BYTE_INDEX,
             l_timing_val,
             "Failed check on Minimum Activate to Activate Delay Time - Same Bank Group (tRRD_Lmin) in MTB") );

    // Update output value only if range check passes
    o_value = l_timing_val;

    FAPI_DBG("%s. Minimum Activate to Activate Delay Time - Same Bank Group (tRRD_Lmin) in MTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decodes Minimum CAS to CAS Delay Time - Same Bank Group
/// @param[in]  i_target dimm target
/// @param[out] o_value tCCD_Lmin MTB units
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 40
/// @note       Item JC-45-2220.01x
/// @note       Page 44-45
/// @note       DDR4 SPD Document Release 3
/// @warning    If tCCD_Lmin cannot be divided evenly by the MTB,
///             this byte must be rounded up to the next larger
///             integer and the Fine Offset for tCCD_Lmin (SPD byte 117)
///             used for correction to get the actual value.
///
fapi2::ReturnCode decoder::min_tccd_l(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                      int64_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 40;

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             iv_spd_data[BYTE_INDEX]);

    // Retrieve Minimum CAS to CAS Delay Time - Same Bank Group
    // explicit conversion to int64_t
    int64_t l_timing_val = int64_t(iv_spd_data[BYTE_INDEX]);

    // Check for valid value
    constexpr int64_t TIMING_LOWER_BOUND = 1; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 255; // from JEDEC

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             BYTE_INDEX,
             l_timing_val,
             "Failed check on Minimum CAS to CAS Delay Time - Same Bank Group (tCCD_Lmin) in MTB") );

    // Update output value only if range check passes
    o_value = l_timing_val;

    FAPI_DBG("%s. Minimum CAS to CAS Delay Time - Same Bank Group (tCCD_Lmin) in MTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decodes Minimum Write Recovery Time
/// @param[in]  i_target dimm target
/// @param[out] o_value tWRmin in MTB units
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 41 (bits 3~0) & Byte 42 (bits 7~0)
/// @note       Item JC-45-2220.01x
/// @note       Page 40
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::min_write_recovery_time(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // Lambda expression to retrieve tWRmin's most nibble byte (MSN)
    auto tWRmin_MSN = [](const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                         const std::vector<uint8_t>& i_data)
    {
        // Trace in the front assists w/ debug
        constexpr size_t BYTE_INDEX = 41;

        FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
                 mss::c_str(i_target),
                 BYTE_INDEX,
                 i_data[BYTE_INDEX]);

        // Extracting desired bits
        uint8_t l_out = 0;
        fapi2::buffer<uint8_t> l_buffer(i_data[BYTE_INDEX]);

        l_buffer.extractToRight<TWRMIN_MSN_START, TWRMIN_MSN_LEN>(l_out);

        return l_out;
    };

    // Lambda expression to retrieve tWRmin's least significant byte (LSB)
    auto tWRmin_LSB = [](const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                         const std::vector<uint8_t>& i_data)
    {
        // Trace in the front assists w/ debug
        constexpr size_t BYTE_INDEX = 42;

        FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
                 mss::c_str(i_target),
                 BYTE_INDEX,
                 i_data[BYTE_INDEX]);

        // Extracting desired bits
        uint8_t l_out = 0;
        fapi2::buffer<uint8_t> l_buffer(i_data[BYTE_INDEX]);

        l_buffer.extractToRight<TWRMIN_LSB_START, TWRMIN_LSB_LEN>(l_out);

        return l_out;
    };

    // Combining bits to create timing value (in a buffer)
    constexpr size_t MSN_START = 52;
    constexpr size_t MSN_LEN = 4;
    constexpr size_t LSB_START = 56;
    constexpr size_t LSB_LEN = 8;

    fapi2::buffer<int64_t> l_buffer;
    l_buffer.insertFromRight<MSN_START, MSN_LEN>( tWRmin_MSN(i_target, iv_spd_data) ).
    insertFromRight<LSB_START, LSB_LEN>( tWRmin_LSB(i_target, iv_spd_data) );

    // Extract timing value from the buffer into an integral type
    constexpr size_t OUTPUT_START = 0;
    constexpr size_t OUTPUT_LEN  = 64;
    int64_t l_timing_val = 0;

    l_buffer.extractToRight<OUTPUT_START, OUTPUT_LEN>(l_timing_val);

    // JEDEC spec limits for this timing value
    // This value used to be reserved to 0 - before spec update
    // constexpr int64_t TIMING_LOWER_BOUND = 1; // from JEDEC

    constexpr int64_t TIMING_LOWER_BOUND = 0;
    constexpr int64_t TIMING_UPPER_BOUND = 4095; // from JEDEC

    // best we can do?
    // I had to combine parts from two different bytes.
    // Chose one of them (byte 42) to for error printout of this decode
    constexpr size_t ERROR_BYTE_INDEX = 42;

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             ERROR_BYTE_INDEX,
             l_timing_val,
             "Failed check on the Minimum Write Recovery Time (tWRmin) in MTB") );

    // Update output only after check passes
    o_value = l_timing_val;

    FAPI_DBG("%s. Minimum Write Recovery Time (tWRmin) in MTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief      Decodes Minimum Write to Read Time - Different Bank Group
/// @param[in]  i_target dimm target
/// @param[out] o_value tWRT_Smin in MTB units
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 43 (bits 3~0) & Byte 44 (bits 7~0)
/// @note       Item JC-45-2220.01x
/// @note       Page 40
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::min_twtr_s(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                      int64_t& o_value)
{
    // Lambda expression to retrieve tWRT_Smin's most nibble byte (MSN)
    auto tWRT_Smin_MSN = [](const fapi2::Target<TARGET_TYPE_DIMM>& i_target, const std::vector<uint8_t>& i_data)
    {
        // Trace in the front assists w/ debug
        constexpr size_t BYTE_INDEX = 43;

        FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
                 mss::c_str(i_target),
                 BYTE_INDEX,
                 i_data[BYTE_INDEX]);

        // Extracting desired bits
        uint8_t l_out = 0;
        fapi2::buffer<uint8_t> l_buffer(i_data[BYTE_INDEX]);

        l_buffer.extractToRight<TWTRMIN_S_MSN_START, TWTRMIN_S_MSN_LEN>(l_out);

        return l_out;
    };

    // Lambda expression to retrieve tWRT_Smin's least significant byte (LSB)
    auto tWRT_Smin_LSB = [](const fapi2::Target<TARGET_TYPE_DIMM>& i_target, const std::vector<uint8_t>& i_data)
    {
        // Trace in the front assists w/ debug
        constexpr size_t BYTE_INDEX = 44;

        FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
                 mss::c_str(i_target),
                 BYTE_INDEX,
                 i_data[BYTE_INDEX]);

        // Extracting desired bits
        uint8_t l_out = 0;
        fapi2::buffer<uint8_t> l_buffer(i_data[BYTE_INDEX]);

        l_buffer.extractToRight<TWTRMIN_S_LSB_START, TWTRMIN_S_LSB_LEN>(l_out);

        return l_out;
    };

    // Combining bits to create timing value (in a buffer)
    constexpr size_t MSN_START = 52;
    constexpr size_t MSN_LEN = 4;
    constexpr size_t LSB_START = 56;
    constexpr size_t LSB_LEN = 8;

    fapi2::buffer<int64_t> l_buffer;

    l_buffer.insertFromRight<MSN_START, MSN_LEN>( tWRT_Smin_MSN(i_target, iv_spd_data) ).
    insertFromRight<LSB_START, LSB_LEN>( tWRT_Smin_LSB(i_target, iv_spd_data) );

    // Extract timing value from the buffer into an integral type
    constexpr size_t OUTPUT_START = 0;
    constexpr size_t OUTPUT_LEN  = 64;
    int64_t l_timing_val = 0;

    l_buffer.extractToRight<OUTPUT_START, OUTPUT_LEN>(l_timing_val);


    // JEDEC spec limits for this timing value

    // This value used to be reserved to 0 - before spec update - AAM
    // constexpr int64_t TIMING_LOWER_BOUND = 1; // from JEDEC
    constexpr int64_t TIMING_LOWER_BOUND = 0;
    constexpr int64_t TIMING_UPPER_BOUND = 4095; // from JEDEC

    // best we can do?
    // I had to combine parts from two different bytes.
    // Chose one of them (byte 44) to for error printout of this decode
    constexpr size_t ERROR_BYTE_INDEX = 44;

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             ERROR_BYTE_INDEX,
             l_timing_val,
             "Failed check on the Minimum Write to Read Time - Different Bank Group (tWRT_Smin) in MTB") );

    // Update output only after check passes
    o_value = l_timing_val;

    FAPI_DBG("%s. Minimum Write to Read Time - Different Bank Group (tWRT_Smin) in MTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decodes Minimum Write to Read Time - Same Bank Group
/// @param[in]  i_target dimm target
/// @param[out] o_value tWRT_Lmin in MTB units
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 43 (bits 7~4) & Byte 45 (bits 7~0)
/// @note       Item JC-45-2220.01x
/// @note       Page 46
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::min_twtr_l(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                      int64_t& o_value)
{
    // Lambda expression to retrieve tWRT_Lmin's most nibble byte (MSN)
    auto tWRT_Lmin_MSN = [](const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                            const std::vector<uint8_t>& i_data)
    {
        // Trace in the front assists w/ debug
        constexpr size_t BYTE_INDEX = 43;

        FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
                 mss::c_str(i_target),
                 BYTE_INDEX,
                 i_data[BYTE_INDEX]);

        // Extracting desired bits
        uint8_t l_out = 0;
        fapi2::buffer<uint8_t> l_buffer(i_data[BYTE_INDEX]);

        l_buffer.extractToRight<TWTRMIN_L_MSN_START, TWTRMIN_L_MSN_LEN>(l_out);

        return l_out;
    };

    // Lambda expression to retrieve tWRT_Lmin's least significant byte (LSB)
    auto tWRT_Lmin_LSB = [](const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                            const std::vector<uint8_t>& i_data)
    {
        // Trace in the front assists w/ debug
        constexpr size_t BYTE_INDEX = 45;

        FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
                 mss::c_str(i_target),
                 BYTE_INDEX,
                 i_data[BYTE_INDEX]);

        // Extracting desired bits
        uint8_t l_out = 0;
        fapi2::buffer<uint8_t> l_buffer(i_data[BYTE_INDEX]);

        l_buffer.extractToRight<TWTRMIN_L_LSB_START, TWTRMIN_L_LSB_LEN>(l_out);

        return l_out;
    };

    // Combining bits to create timing value (in a buffer)
    constexpr size_t MSN_START = 52;
    constexpr size_t MSN_LEN = 4;
    constexpr size_t LSB_START = 56;
    constexpr size_t LSB_LEN = 8;

    fapi2::buffer<int64_t> l_buffer;

    l_buffer.insertFromRight<MSN_START, MSN_LEN>( tWRT_Lmin_MSN(i_target, iv_spd_data) ).
    insertFromRight<LSB_START, LSB_LEN>( tWRT_Lmin_LSB(i_target, iv_spd_data) );

    // Extract timing value from the buffer into an integral type
    constexpr size_t OUTPUT_START = 0;
    constexpr size_t OUTPUT_LEN  = 64;
    int64_t l_timing_val = 0;

    l_buffer.extractToRight<OUTPUT_START, OUTPUT_LEN>(l_timing_val);

    // JEDEC spec limits for this timing value
    // This value used to be reserved to 0 - before spec update
    //constexpr int64_t TIMING_LOWER_BOUND = 1  // from JEDEC
    constexpr int64_t TIMING_LOWER_BOUND = 0;
    constexpr int64_t TIMING_UPPER_BOUND = 4095; // from JEDEC

    // best we can do?
    // I had to combine parts from two different bytes.
    // Chose one of them (byte 45) to for error printout of this decode
    constexpr size_t ERROR_BYTE_INDEX = 45;

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             ERROR_BYTE_INDEX,
             l_timing_val,
             "Failed check on the Minimum Write to Read Time - Same Bank Group (tWRT_Lmin) in MTB") );

    // Update output only after check passes
    o_value = l_timing_val;

    FAPI_DBG("%s. Minimum Write to Read Time - Same Bank Group (tWRT_Lmin) in MTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decodes Fine Offset for Minimum CAS to CAS Delay Time - Same Bank Group
/// @param[in]  i_target dimm target
/// @param[out] o_value tCCD_Lmin offset in FTB units
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 117
/// @note       Item JC-45-2220.01x
/// @note       Page 52
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::fine_offset_min_tccd_l(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 117;

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             iv_spd_data[BYTE_INDEX]);

    // Retrieve Fine Offset for Minimum CAS to CAS Delay Time
    // int8_t conversion - allows me to get a negative offset
    // then implicit conversion to int64_t
    int64_t l_timing_val = int8_t(iv_spd_data[BYTE_INDEX]);

    // Check for valid value
    constexpr int64_t TIMING_LOWER_BOUND = -128; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 127; // from JEDEC

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             BYTE_INDEX,
             l_timing_val,
             "Failed check on the fine offset for min RAS to CAS Delay Time (tCCD_Lmin)") );

    // Update output value only if range check passes
    o_value = l_timing_val;

    FAPI_DBG("%s. Fine offset for Minimum RAS to CAS Delay Time (tCCD_Lmin) in FTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decodes Fine Offset for Minimum Activate to Activate Delay Time - Same Bank Group
/// @param[in]  i_target dimm target
/// @param[out] o_value tRRD_Lmin offset in FTB units
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 118
/// @note       Item JC-45-2220.01x
/// @note       Page 52
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::fine_offset_min_trrd_l(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 118;

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             iv_spd_data[BYTE_INDEX]);

    // Retrieve Fine Offset for Minimum Activate to Activate Delay Time
    // int8_t conversion - allows me to get a negative offset
    // then implicit conversion to int64_t
    int64_t l_timing_val = int8_t(iv_spd_data[BYTE_INDEX]);

    // Check for valid value
    constexpr int64_t TIMING_LOWER_BOUND = -128; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 127; // from JEDEC

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             BYTE_INDEX,
             l_timing_val,
             "Failed check on the fine offset for Minimum Activate to Activate Delay Time (tRRD_Lmin)") );

    // Update output value only if range check passes
    o_value = l_timing_val;

    FAPI_DBG("%s. Fine offset for Minimum Activate to Activate Delay Time (tRRD_Lmin) in FTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decodes Fine Offset for Minimum Activate to Activate Delay Time - Different Bank Group
/// @param[in]  i_target dimm target
/// @param[out] o_value tRRD_Smin offset in FTB units
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 119
/// @note       Item JC-45-2220.01x
/// @note       Page 52
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::fine_offset_min_trrd_s(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 119;

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             iv_spd_data[BYTE_INDEX]);

    // Retrieve Fine Offset for Minimum Activate to Activate Delay Time - Different Bank Group
    // int8_t conversion - allows me to get a negative offset
    // then implicit conversion to int64_t
    int64_t l_timing_val = int8_t(iv_spd_data[BYTE_INDEX]);

    // Check for valid value
    constexpr int64_t TIMING_LOWER_BOUND = -128; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 127; // from JEDEC

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             BYTE_INDEX,
             l_timing_val,
             "Failed check on the fine offset for Minimum Activate to Activate Delay Time - Different Bank Group (tRRD_Smin)") );

    // Update output value only if range check passes
    o_value = l_timing_val;

    FAPI_DBG("%s. Fine offset for Minimum Activate to Activate Delay Time - Different Bank Group (tRRD_Smin) in FTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decodes Fine Offset for Minimum Active to Active/Refresh Delay Time
/// @param[in]  i_target dimm target
/// @param[out] o_value tRCmin offset in FTB units
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 120
/// @note       Item JC-45-2220.01x
/// @note       Page 52
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::fine_offset_min_trc(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 120;

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             iv_spd_data[BYTE_INDEX]);

    // Retrieve Fine Offset for Minimum Active to Active/Refresh Delay Time
    // int8_t conversion - allows me to get a negative offset
    // then implicit conversion to int64_t
    int64_t l_timing_val = int8_t(iv_spd_data[BYTE_INDEX]);

    // Check for vali value
    constexpr int64_t TIMING_LOWER_BOUND = -128; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 127; // from JEDEC

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             BYTE_INDEX,
             l_timing_val,
             "Failed check on the fine offset for Minimum Active to Active/Refresh Delay Time (tRCmin)") );

    // Update output value only if range check passes
    o_value = l_timing_val;

    FAPI_DBG("%s. Fine offset for Minimum Active to Active/Refresh Delay Time (tRCmin) in FTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decodes Fine Offset for Minimum Row Precharge Delay Time
/// @param[in]  i_target dimm target
/// @param[out] o_value tRPmin offset in FTB units
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 121
/// @note       Item JC-45-2220.01x
/// @note       Page 52
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::fine_offset_min_trp(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 121;

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             iv_spd_data[BYTE_INDEX]);

    // Retrieve Fine Offset for Minimum Row Precharge Delay Time
    // int8_t conversion - allows me to get a negative offset
    // then implicit conversion to int64_t
    int64_t l_timing_val = int8_t(iv_spd_data[BYTE_INDEX]);

    // Check for valid value
    constexpr int64_t TIMING_LOWER_BOUND = -128; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 127; // from JEDEC

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             BYTE_INDEX,
             l_timing_val,
             "Failed check on the fine offset for Minimum Row Precharge Delay Time (tRPmin)") );

    // Update output value only if range check passes
    o_value = l_timing_val;

    FAPI_DBG("%s. Fine offset for Minimum Row Precharge Delay Time (tRPmin) in FTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}
///
/// @brief      Decodes Fine Offset for SDRAM Minimum RAS to CAS Delay Time
/// @param[in]  i_target dimm target
/// @param[out] o_value tRCDmin offset in FTB units
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 122
/// @note       Item JC-45-2220.01x
/// @note       Page 52
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::fine_offset_min_trcd(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 122;

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             iv_spd_data[BYTE_INDEX]);

    // Retrieve Fine Offset for SDRAM Minimum RAS to CAS Delay Time
    // int8_t conversion - allows me to get a negative offset
    // then implicit conversion to int64_t
    int64_t l_timing_val = int8_t(iv_spd_data[BYTE_INDEX]);

    // Check for valid value
    constexpr int64_t TIMING_LOWER_BOUND = -128; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 127; // from JEDEC

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             BYTE_INDEX,
             l_timing_val,
             "Failed check on the fine offset for min RAS to CAS Delay Time (tRCDmin)") );

    // Update output value only if range check passes
    o_value = l_timing_val;

    FAPI_DBG("%s. Fine offset for Minimum RAS to CAS Delay Time (tRCDmin) in FTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decodes Fine Offset for SDRAM Minimum CAS Latency Time
/// @param[in]  i_target dimm target
/// @param[out] o_value tAAmin offset in FTB units
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 123
/// @note       Item JC-45-2220.01x
/// @note       Page 52
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::fine_offset_min_taa(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 125;

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             iv_spd_data[BYTE_INDEX]);

    // Retrieve Fine Offset for SDRAM Minimum CAS Latency Time
    // int8_t conversion - allows me to get a negative offset
    // then implicit conversion to int64_t
    int64_t l_timing_val = int8_t(iv_spd_data[BYTE_INDEX]);

    // Check for valid value
    constexpr int64_t TIMING_LOWER_BOUND = -128; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 127; // from JEDEC

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             BYTE_INDEX,
             l_timing_val,
             "Failed check on the Fine offset for Minimum CAS Latency Time (tAAmin)") );

    // Update output value only if range check passes
    o_value = l_timing_val;

    FAPI_DBG("%s. Fine offset for Minimum CAS Latency Time (tAAmin) in FTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decodes Fine Offset for SDRAM Maximum Cycle Time
/// @param[in]  i_target dimm target
/// @param[out] o_value tCKmax offset in FTB units
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 124
/// @note       Item JC-45-2220.01x
/// @note       Page 52
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::fine_offset_max_tck(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 124;

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             iv_spd_data[BYTE_INDEX]);

    // Retrieve Fine Offset for SDRAM Maximum Cycle Time
    // int8_t conversion - allows me to get a negative offset
    // then implicit conversion to int64_t
    int64_t l_timing_val = int8_t(iv_spd_data[BYTE_INDEX]);

    // Check for valid value
    constexpr int64_t TIMING_LOWER_BOUND = -128; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 127; // from JEDEC

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             BYTE_INDEX,
             l_timing_val,
             "Failed check on the fine offset for max cycle time (tckmax)") );

    // Update output value only if range check passes
    o_value = l_timing_val;

    FAPI_DBG("%s. Fine offset for Maximum Cycle Time (tCKmax) in FTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief      Decodes Fine Offset for SDRAM Minimum Cycle Time
/// @param[in]  i_target dimm target
/// @param[out] o_value tCKmin offset in FTB units
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 125
/// @note       Item JC-45-2220.01x
/// @note       Page 52
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::fine_offset_min_tck(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 125;

    FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             iv_spd_data[BYTE_INDEX]);

    // Retrieve Fine Offset for SDRAM Minimum Cycle Time
    // int8_t conversion - allows me to get a negative offset
    // then implicit conversion to int64_t
    int64_t l_timing_val = int8_t(iv_spd_data[BYTE_INDEX]);

    // Check for valid value
    constexpr int64_t TIMING_LOWER_BOUND = -128; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 127; // from JEDEC

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             BYTE_INDEX,
             l_timing_val,
             "Failed check on the Fine offset for Minimum Cycle Time (tCKmin)") );

    // Update output value only if range check passes
    o_value = l_timing_val;

    FAPI_DBG("%s. Fine offset for Minimum Cycle Time (tCKmin) in FTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief      Decodes Cyclical Redundancy Code (CRC) for Base Configuration Section
/// @param[in]  i_target dimm target
/// @param[out] o_value crc value from SPD
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       SPD Byte 127 & Byte 126
/// @note       Item JC-45-2220.01x
/// @note       Page 53
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::cyclical_redundancy_code(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        uint16_t& o_value)
{
    // Lambda expression to retrieve crc's most significant byte (MSB)
    auto crc_MSB = [](const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                      const std::vector<uint8_t>& i_data)
    {
        constexpr size_t BYTE_INDEX = 127;
        uint8_t l_out = 0;

        // Trace in the front assists w/ debug
        FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
                 mss::c_str(i_target),
                 BYTE_INDEX,
                 i_data[BYTE_INDEX]);

        fapi2::buffer<uint8_t> l_buffer(i_data[BYTE_INDEX]);

        // Extracting desired bits
        l_buffer.extractToRight<CRC_MSB_START, CRC_MSB_LEN>(l_out);

        return l_out;
    };

    // Lambda expression to retrieve crc's least significant byte (LSB)
    auto crc_LSB = [](const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                      const std::vector<uint8_t>& i_data)
    {
        constexpr size_t BYTE_INDEX = 126;
        uint8_t l_out = 0;

        // Trace in the front assists w/ debug
        FAPI_DBG("%s SPD data at Byte %d: 0x%llX.",
                 mss::c_str(i_target),
                 BYTE_INDEX,
                 i_data[BYTE_INDEX]);

        fapi2::buffer<uint8_t> l_buffer(i_data[BYTE_INDEX]);

        // Extracting desired bits
        l_buffer.extractToRight<CRC_LSB_START, CRC_LSB_LEN>(l_out);

        return l_out;
    };

    fapi2::buffer<uint16_t> l_buffer;
    // Combining bits to create timing value (in a buffer)
    constexpr size_t MSN_START = 0;
    constexpr size_t MSN_LEN = 8;
    constexpr size_t LSB_START = 8;
    constexpr size_t LSB_LEN = 8;

    l_buffer.insertFromRight<MSN_START, MSN_LEN>( crc_MSB(i_target, iv_spd_data) ).
    insertFromRight<LSB_START, LSB_LEN>( crc_LSB(i_target, iv_spd_data) );

    // Extract timing value from the buffer into an integral type
    constexpr size_t OUTPUT_START = 0;
    constexpr size_t OUTPUT_LEN  = 16;

    // This value isn't bounded in the SPD document
    l_buffer.extractToRight<OUTPUT_START, OUTPUT_LEN>(o_value);

    FAPI_DBG("%s. Cyclical Redundancy Code (CRC): %d",
             mss::c_str(i_target),
             o_value);

    // Returns "happy" until we can figure out a way to test this - AAM
    return fapi2::FAPI2_RC_SUCCESS;
}

}//spd namespace
}// mss namespace
