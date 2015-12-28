/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/spd/spd_decoder.C $        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
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

#include <fapi2.H>
#include "../mss.H"
#include "../utils/conversions.H"
#include "spd_decoder.H"

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_DIMM;


namespace mss
{
namespace spd
{

// Note: IBM's implementation of std::maps are not thread safe

// =========================================================
// Byte 0 maps
// Item JC-45-2220.01x
// Page 14
// DDR4 SPD Document Release 3
// Byte 0 (0x000): Number of Bytes Used / Number of Bytes in SPD Device

static const uint16_t bytes_used_map[] =
{
    // Shifting index by 1 first since first key value is undefined
    // Key values < 1 and > 3 aren't supported or reserved

    // Undefined
    128,
    256,
    384,
    512,
    //...
    // All other bits reserved
};

static const uint16_t bytes_total_map[] =
{
    // Shifting index by 1 first since first key value is undefined
    // Key values < 1 and > 2 aren't supported or reserved

    // Undefined
    256,
    512,
    //...
    // All other bits reserved
};

// =========================================================
// Byte 2 maps
// Item JC-45-2220.01x
// Page 16
// DDR4 SPD Document Release 3
// Byte 2 (0x002): Key Byte / DRAM Device Type

static const uint8_t dram_gen_map[] =
{
    // Initial and ending index values are not supported or reserved
    // Shifting index by 11 since initial dram gen types aren't supported (by IBM)
    // Key values < 12 and > 13  are not supported or reserved

    // Reserved
    // Fast page mode is not supported
    // EDO is not supported
    // Pipelined Nibbleis not supported
    // SDRAM
    // ROM is not supported
    // DDR SGRAM is not supported
    // DDR SDRAM is not supported
    // DDR2 SDRAM is not supported
    // DDR2 SDRAM FB-DIMM is not supported
    // DDR2 SDRAM FB-DIMM PROBE is not supported
    fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR3,
    fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
    //...
    // All other bits reserved
};

// =========================================================
// Byte 3 maps
// Item JC-45-2220.01x
// Page 17
// DDR4 SPD Document Release 3
// Byte 3 (0x003): Key Byte / Module Type

static const uint8_t base_module_type_map[] =
{

    // Initial and ending index values are not supported or reserved
    // Index shifted by 1 since first module type isn't supported (by IBM)
    // Key values < 1 and > 4 are not supported or reserved

    // Extending DIMM not supported
    fapi2::ENUM_ATTR_SPD_MODULE_TYPE_RDIMM,
    fapi2::ENUM_ATTR_SPD_MODULE_TYPE_UDIMM,
    fapi2::ENUM_ATTR_SPD_MODULE_TYPE_SO_DIMM,
    fapi2::ENUM_ATTR_SPD_MODULE_TYPE_LRDIMM,
    // Mini-RDIMM not supported
    // Mini-UDIMM not supported
    // Reserved
    // 72b-SO-RDIMM not supported
    // 72b-SO-UDIMM not supported
    // Reserved
    // Reserved
    // 16b-SO-DIMM
    // 32b-SO-DIMM
    // Reserved
    // Reserved
};

// =========================================================
// Byte 4 maps
// Item JC-45-2220.01x
// Page 18
// DDR4 SPD Document Release 3
// Byte 4 (0x004): SDRAM Density and Banks

static const uint8_t sdram_capacity_map[] =
{
    // Initial and ending index values are not supported or reserved
    // Index shifted by 2 since first module type isn't supported (by IBM)
    // Key values < 2 and > 9 are not supported or reserved

    // 256 Mbs is not supported
    // 512 Mbs is not supported
    //   // Units (Gigabits)
    1,   // Gb
    2,   // Gb
    4,   // Gb
    8,   // Gb
    16,  // Gb
    32,  // Gb
    12,  // Gb
    24,  // Gb
    //...
    //All others reserved
};

static const uint8_t sdram_banks_map[] =
{
    // Key values > 1 are not supported or reserved

    4, // banks address bits (2 address bits)
    8, // banks address bits (3 address bits)
    //...
    // All others Reserved
};

static const uint8_t sdram_bankgroups_map[] =
{
    // Key values > 2 are not supported or reserved

    0,  // No bank groups (0 bank group bits)
    2,  // 2 bank groups (1 bank group bit)
    4,  // 4 bank groups (2 bank group bits)
    //Reserved
};

// =========================================================
// Byte 5 maps
// Item JC-45-2220.01x
// Page 18
// DDR4 SPD Document Release 3
// Byte 5 (0x005): SDRAM Addressing

static const uint8_t column_address_map[] =
{
    9,  // Column address bits 000
    10, // Column address bits 001
    11, // Column address bits 010
    12, // Column address bits 011
    // All others reserved
};

static const uint8_t row_address_map[] =
{
    12, // Row address bits 000
    13, // Row address bits 001
    14, // Row address bits 010
    15, // Row address bits 011
    16, // Row address bits 100
    17, // Row address bits 101
    18, // Row address bits 110
    // All others reserved
};

// =========================================================
// Byte 6 maps
// Item JC-45-2220.01x
// Page 19
// DDR4 SPD Document Release 3
// Byte 6 (0x006): Primary SDRAM Package Type

static const uint8_t die_count_map[] =
{
    1, // 000 = Single die
    2, // 001 = 2 die
    3, // 010 = 3 die
    4, // 011 = 4 die
    5, // 100 = 5 die
    6, // 101 = 6 die
    7, // 110 = 7 die
    8, // 111 = 8 die
};

static const uint8_t package_type_map[] =
{
    fapi2::ENUM_ATTR_EFF_STACK_TYPE_SDP,
    uint8_t(~0),
    uint8_t(~0),
    uint8_t(~0),
    uint8_t(~0),
    fapi2::ENUM_ATTR_EFF_STACK_TYPE_DDP_QDP,
    fapi2::ENUM_ATTR_EFF_STACK_TYPE_3DS,
};

// =========================================================
// Byte 7 maps
// Item JC-45-2220.01x
// Page 20
// DDR4 SPD Document Release 3
// Byte 7 (0x007): SDRAM Optional Features

uint16_t static const MAC_map[] =
{
    fapi2::ENUM_ATTR_EFF_DRAM_MAC_UNTESTED, // Untested MAC
    fapi2::ENUM_ATTR_EFF_DRAM_MAC_700K,     // 700K
    fapi2::ENUM_ATTR_EFF_DRAM_MAC_600K,     // 600K
    fapi2::ENUM_ATTR_EFF_DRAM_MAC_500K,     // 500K
    fapi2::ENUM_ATTR_EFF_DRAM_MAC_400K,     // 400K
    fapi2::ENUM_ATTR_EFF_DRAM_MAC_300K,     // 300K
    fapi2::ENUM_ATTR_EFF_DRAM_MAC_200K,     // 200K
    uint16_t(~0),                           // Reserved
    fapi2::ENUM_ATTR_EFF_DRAM_MAC_UNLIMITED,// Unlimited MAC
    // All others reserved
};

uint16_t static const tMAW_map[] =
{
    8192,
    4096,
    2048,
};

// =========================================================
// Byte 9 maps
// Item JC-45-2220.01x
// Page 21
// DDR4 SPD Document Release 3
// Byte 9 (0x009): Other SDRAM Optional Features
static const uint8_t ppr_map[]
{
    fapi2::ENUM_ATTR_EFF_DRAM_PPR_NOT_SUPPORTED,
    fapi2::ENUM_ATTR_EFF_DRAM_PPR_SUPPORTED,
    //...
    // Reserved
};

static const uint8_t soft_ppr_map[]
{
    fapi2::ENUM_ATTR_EFF_DRAM_SOFT_PPR_NOT_SUPPORTED,
    fapi2::ENUM_ATTR_EFF_DRAM_SOFT_PPR_SUPPORTED,
};

// =========================================================
// Byte 6 maps
// Item JC-45-2220.01x
// Page 19
// DDR4 SPD Document Release 3
// Byte 6 (0x006): Primary SDRAM Package Type

static const uint8_t sec_die_count_map[] =
{
    1, // 000 = Single die
    2, // 001 = 2 die
    3, // 010 = 3 die
    4, // 011 = 4 die
    5, // 100 = 5 die
    6, // 101 = 6 die
    7, // 110 = 7 die
    8, // 111 = 8 die
};

static const uint8_t sec_package_type_map[] =
{
    fapi2::ENUM_ATTR_EFF_STACK_TYPE_SDP,
    uint8_t(~0),
    uint8_t(~0),
    uint8_t(~0),
    uint8_t(~0),
    fapi2::ENUM_ATTR_EFF_STACK_TYPE_DDP_QDP,
    fapi2::ENUM_ATTR_EFF_STACK_TYPE_3DS,
};

// =========================================================
// Byte 12 maps
// Item JC-45-2220.01x
// Page 23
// DDR4 SPD Document Release 3
// Byte 12 (0x00C): Module Organization
static const uint8_t device_type_map[] =
{
    //  // Units
    4,  // bits
    8,  // bits
    16, // bits
    32, // bits
    // All others reserved
};

static const uint8_t num_pkgs_ranks_per_dimm_map[] =
{
    //  // Units
    1,  // package rank
    2,  // package ranks
    3,  // package ranks
    4,  // package ranks
    5,  // package ranks
    6,  // package ranks
    7,  // package ranks
    8   // package ranks
    // All others reserved
};

// =========================================================
// Byte 12 maps
// Item JC-45-2220.01x
// Page 23
// DDR4 SPD Document Release 3
// Byte 13 (0x00D): Module Memory Bus Width
static const uint8_t prim_bus_width_map[] =
{
    //  // Units
    8,  // bits
    16, // bits
    32, // bits
    64, // bits
    // All others reserved
};

static const uint8_t bus_width_ext_map[] =
{
    //  // Units
    0,  // bits
    8,  // bits
    // All others reserved
};

// =========================================================
// Byte 17 maps
// Item JC-45-2220.01x
// Page 29
// DDR4 SPD Document Release 3
// Byte 17 (0x011): Timebases

// Created a maps of a single value in case mapping expands to more values
static const uint8_t medium_timebase_map[] =
{
    //  // Units
    125,  // ps
    // All others reserved
};

static const uint8_t fine_timebase_map[] =
{
    //  // Units
    1,  // ps
    // All others reserved
};


// =========================================================
//  Function implementations
// =========================================================
namespace check
{
///
/// @brief      Checks that stack type conforms to JEDEC table
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       Consumed in (Byte 7) sdram_package_type(...)
///             Item JC-45-2220.01x
///             Page 20 (Terminology table)
///             DDR4 SPD Document Release 3
bool stack_type(const uint8_t i_stack_type, const uint8_t i_die_count)
{
    const size_t STACK_SDP = 0;
    const size_t STACK_DDP_QDP = 5;
    const size_t STACK_3DS = 6;

    const size_t SINGLE_DIE_PACKAGE = 1;
    const size_t DUAL_DIE_PACKAGE = 2;
    const size_t QUAD_DIE_PACKAGE = 4;

    const size_t TWO_SDRAM_DIE = 2;
    const size_t EIGHT_SDRAM_DIE = 8;

    // Use const or enums
    switch(i_stack_type)
    {
        case STACK_SDP:
            //SDP has single die
            return i_die_count == SINGLE_DIE_PACKAGE;
            break;

        case STACK_DDP_QDP:
            //DDP has 2 die, QDP has 4 die
            return (i_die_count == DUAL_DIE_PACKAGE) || (i_die_count == QUAD_DIE_PACKAGE);
            break;

        case STACK_3DS:
            //3DS has 2 - 8 dies
            return (i_die_count >= TWO_SDRAM_DIE) && (i_die_count <= EIGHT_SDRAM_DIE);
            break;

        default:
            return false; // Doesn't meet JEDEC spec
    }
}// stack_type()

} // check namespace

///
/// @brief      Calculates timing value
/// @param[in]  const int64_t& i_spd_timing_mtb,
///                        const int64_t& i_spd_timing_ftb,
///                        const int64_t& multiplier_mtb,
///                        const int64_t& multiplier_ftb
/// @return     int64_t, (timing value)
inline int64_t calc_timing(const int64_t& i_spd_timing_mtb,
                           const int64_t& i_spd_timing_ftb,
                           const int64_t& multiplier_mtb,
                           const int64_t& multiplier_ftb)
{
    int64_t timing_val = i_spd_timing_mtb * multiplier_mtb;
    int64_t offset = (i_spd_timing_ftb * multiplier_ftb);
    int64_t remainder_val = timing_val % multiplier_mtb;

    if( remainder_val == 0)
    {
        // If the timing value can be expressed as an integer number
        // of MTB units, return that
        return timing_val;
    }
    else
    {
        // Else round up and incorporate correction factor
        return (++timing_val) + offset;
    }
}

///
/// @brief Decodes SPD number of bytes
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
///             size_t i_read_spd_size
/// @return     fapi2::ReturnCode
/// @note       Decodes SPD Byte 0
///
fapi2::ReturnCode decoder::number_of_bytes(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data,
        const size_t i_read_spd_size)
{
    // Immutable constants
    const size_t BYTE_INDEX = 0;

    // SPD Bytes used mapping limits
    const size_t BYTES_USED_MAP_OFFSET = 1;
    const size_t BYTES_USED_MIN_VALID_KEY = 1; // All previous keys are not supported or reserved
    const size_t BYTES_USED_MAX_VALID_KEY = 4; // The rest are not supported or reserved

    // Total SPD bytes mapping limits
    const size_t BYTES_TOTAL_MAP_OFFSET = 1;
    const size_t BYTES_TOTAL_MIN_VALID_KEY = 1; // All previous keys are not supported or reserved
    const size_t BYTES_TOTAL_MAX_VALID_KEY = 2; // The rest are not supported or reserved

    // Byte variables used for decoding
    uint8_t l_spd_bytes_used = 0;
    uint8_t l_spd_bytes_total = 0;
    uint8_t l_reserved = 0;
    uint16_t l_total_bytes_map_val = 0;
    uint16_t l_used_bytes_map_val = 0;

    // Buffers used for bit manipulation
    fapi2::buffer<uint8_t> l_spd_buffer(i_spd_data[BYTE_INDEX]);

    // Trace in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte 0: 0x%llX.",
             mss::c_str(i_target_dimm),
             i_spd_data[BYTE_INDEX]);

    // Decoding 1st nibble, bits 3~0 (SPD Bytes Used)
    l_spd_buffer.extractToRight<BYTES_USED_START, BYTES_USED_LEN>(l_spd_bytes_used);

    // Check to assure SPD Bytes Used (map) wont be at invalid values
    FAPI_TRY( mss::check::spd::valid_value_fail(i_target_dimm,
              (l_spd_bytes_used >= BYTES_USED_MIN_VALID_KEY) &&
              (l_spd_bytes_used <= BYTES_USED_MAX_VALID_KEY),
              BYTE_INDEX,
              l_spd_bytes_used,
              "Failed check on Used SPD bytes") );

    // Decoding bits 6~4 (SPD Bytes Total)
    l_spd_buffer.extractToRight<BYTES_TOTAL_START, BYTES_TOTAL_LEN>(l_spd_bytes_total);

    // Check to assure SPD Bytes Total (map) wont be at invalid values
    FAPI_TRY( mss::check::spd::valid_value_fail(i_target_dimm,
              (l_spd_bytes_total >= BYTES_TOTAL_MIN_VALID_KEY) &&
              (l_spd_bytes_total <= BYTES_TOTAL_MAX_VALID_KEY),
              BYTE_INDEX,
              l_spd_bytes_total,
              "Failed check on total SPD bytes" ) );

    // Decoding bit 7 (Reserved bit)
    l_spd_buffer.extractToRight<BYTES_RESERVED_START, BYTES_RESERVED_LEN>(l_reserved);

    // Hold map values in temp variables
    l_used_bytes_map_val = bytes_used_map[l_spd_bytes_used - BYTES_USED_MAP_OFFSET];
    l_total_bytes_map_val = bytes_total_map[l_spd_bytes_total - BYTES_TOTAL_MAP_OFFSET];

    // Size of input SPD read should match size it claims to be based on the SPD spec
    //  "Used SPD bytes" wasn't used since manufacturers may not use all available bytes
    FAPI_TRY( mss::check::spd::valid_value_fail(i_target_dimm,
              l_total_bytes_map_val == i_read_spd_size,
              BYTE_INDEX,
              l_total_bytes_map_val,
              "Failed SPD size check") );

    FAPI_INF("%s. Bytes Used: %d, Total Bytes: %d, Reserved : %d",
             mss::c_str(i_target_dimm),
             l_used_bytes_map_val,
             l_total_bytes_map_val,
             l_reserved);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes SPD Revision
/// @param[in]      const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///                 uint8_t* i_spd_data
/// @param[in, out] uint8_t io_revision_num
/// @return         fapi2::ReturnCode
/// @note           Decodes SPD Byte 1
///
fapi2::ReturnCode decoder::revision(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
                                    const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX = 1;
    const size_t UNDEFINED = 0xFF; // per JEDEC spec

    // Byte variables used for decoding
    uint8_t l_revision_num = 0;

    // Verify SPD revision is not undefined.  Value is defined by the JEDEC spec
    l_revision_num = i_spd_data[BYTE_INDEX];

    FAPI_TRY( mss::check::spd::valid_value_fail(i_target_dimm,
              (l_revision_num != UNDEFINED),
              BYTE_INDEX,
              l_revision_num,
              "Failed check on SPD revision") );
    // Print decoded info
    FAPI_INF("%s. SPD data at Byte %d: 0x%llX, Revision number : %d",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX],
             l_revision_num);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decodes DRAM Device Type
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       Decodes SPD Byte 2
///
fapi2::ReturnCode decoder::dram_device_type(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX = 2;

    // dram generation mapping limits
    const size_t MIN_VALID_KEY = 12; // All previous keys are not supported or reserved
    const size_t MAX_VALID_KEY = 13; // The rest are not supported or reserved
    const size_t MAP_OFFSET = 11; // SPD DRAM device type map has an index offset of 11 (simplifies array)
    //                              //since initial map values are not supported or reserved (ignored for now)

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Byte variables used for decoding
    uint8_t l_device_type = 0;

    // Attribute variables used to set decoded vals
    uint8_t l_device_gen[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Check to assure SPD DRAM device type (map) wont be at invalid values
    l_device_type = i_spd_data[BYTE_INDEX];

    FAPI_TRY( mss::check::spd::valid_value_fail(i_target_dimm,
              (l_device_type >= MIN_VALID_KEY) &&
              (l_device_type <= MAX_VALID_KEY),
              BYTE_INDEX,
              l_device_type,
              "Unsupported/reserved key value retried from SPD") );

    // Retrive entire MCS level attribute
    FAPI_TRY(eff_dram_gen(l_target_mcs, &l_device_gen[0][0]));

    // Update attribute to decoded byte values
    l_device_gen[PORT_NUM][DIMM_NUM] = dram_gen_map[l_device_type - MAP_OFFSET];

    // Update MCS level attribute
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_GEN, l_target_mcs, l_device_gen));

    // Print decoded info
    FAPI_INF("%s SPD data at Byte %d: 0x%llX. Device type : %d",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX],
             l_device_gen[PORT_NUM][DIMM_NUM]);

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief      Decodes SPD module type
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       Decodes SPD Byte 3
///
fapi2::ReturnCode decoder::module_type(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
                                       const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX = 3;

    // Base module mapping limits             // since first index is not supported
    const size_t BASE_MODULE_MAP_OFFSET = 1;  // base_module_type_map has an index offset of 1
    const size_t MIN_VALID_KEY = 1; // All previous keys are not supported or reserved
    const size_t MAX_VALID_KEY = 4; // The rest are not supported or reserved

    // Hybrid Media limit
    const size_t MAX_HYBRID_MEDIA_KEY = 1; // All other key values reserved

    // Hybrid
    const size_t MAX_HYBRID_KEY = 1; // Nothing else exits afterwards

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Byte variables used for decoding
    uint8_t l_base_module_type  = 0;
    uint8_t l_hybrid_media = 0;
    uint8_t l_hybrid = 0;

    // Attribute variables used to set decoded vals
    uint8_t l_module_type[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Buffer used for bit manipulation
    fapi2::buffer<uint8_t> l_spd_buffer(i_spd_data[BYTE_INDEX]);

    // Trace in the front assists w/ debug
    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Decoding bits 3~0
    l_spd_buffer.extractToRight<BASE_MODULE_START, BASE_MODULE_LEN>(l_base_module_type);

    // Check to assure SPD DRAM base module type (map) wont be at invalid values
    FAPI_TRY( mss::check::spd::valid_value_fail(i_target_dimm,
              (l_base_module_type >= MIN_VALID_KEY) &&
              (l_base_module_type <= MAX_VALID_KEY),
              BYTE_INDEX,
              l_base_module_type,
              "Failed check for SPD DRAM base module type") );

    // Decoding bits 6~4
    l_spd_buffer.extractToRight<HYBRID_MEDIA_START, HYBRID_MEDIA_LEN>(l_hybrid_media);

    // Check to assure SPD DRAM hybrid media is valid
    FAPI_TRY( mss::check::spd::valid_value_fail(i_target_dimm,
              l_hybrid_media <= MAX_HYBRID_MEDIA_KEY,
              BYTE_INDEX,
              l_hybrid_media,
              "Failed check for SPD DRAM hybrid media") );

    // Decoding bit 7
    l_spd_buffer.extractToRight<HYBRID_START, HYBRID_LEN>(l_hybrid);


    // Check to assure SPD DRAM hybrid media is valid
    FAPI_TRY( mss::check::spd::valid_value_fail(i_target_dimm,
              l_hybrid_media <= MAX_HYBRID_KEY,
              BYTE_INDEX,
              l_hybrid,
              "Failed check for SPD DRAM hybrid media") );
    // Retrive entire MCS level attribute
    FAPI_TRY(spd_module_type(l_target_mcs, &l_module_type[0][0]));

    // Update attribute to decoded byte values
    l_module_type[PORT_NUM][DIMM_NUM] =  base_module_type_map[l_base_module_type - BASE_MODULE_MAP_OFFSET];

    // Update MCS level attribute
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_SPD_MODULE_TYPE, l_target_mcs, l_module_type));

    FAPI_INF("%s. Base Module Type: %d, Hybrid Media: %d, Hybrid: %d",
             c_str(i_target_dimm),
             l_module_type[PORT_NUM][DIMM_NUM],
             l_hybrid_media,
             l_hybrid);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decode SDRAM density
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       SPD Byte 4
///
fapi2::ReturnCode decoder::sdram_density(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX = 4;

    // DRAM capacity mapping limits
    const size_t CAPACITY_MAP_OFFSET = 1;   // base_module_type_map has an index offset of 1
    const size_t CAPACITY_MIN_VALID_KEY = 2; // All previous keys are not supported or reserved
    const size_t CAPACITY_MAX_VALID_KEY = 9; // The rest are not supported or reserved

    // DRAM banks mapping limits
    const size_t BANKS_MAX_VALID_KEY = 1; // The rest are not supported or reserved

    // DRAM bank groups mapping limits
    const size_t BANK_GRP_MAX_VALID_KEY = 2; // The rest are not supported or reserved

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Byte variables used for decoding
    uint8_t l_sdram_capacity = 0;
    uint8_t l_sdram_banks = 0;
    uint8_t l_sdram_bank_group = 0;

    // Attribute variables used to set decoded vals
    uint8_t l_capacities[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};
    uint8_t l_banks[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};
    uint8_t l_bank_groups[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Buffer used for bit manipulation
    fapi2::buffer<uint8_t> l_spd_buffer(i_spd_data[BYTE_INDEX]);

    // Trace in the front assists w/ debug
    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Decoding bits 3~0
    l_spd_buffer.extractToRight<SDRAM_CAPACITY_START, SDRAM_CAPACITY_LEN>(l_sdram_capacity);

    // Check to assure SPD DRAM capacity (map) wont be at invalid values
    FAPI_TRY( mss::check::spd::valid_value_fail(i_target_dimm,
              (l_sdram_capacity >= CAPACITY_MIN_VALID_KEY) &&
              (l_sdram_capacity <= CAPACITY_MAX_VALID_KEY),
              BYTE_INDEX,
              l_sdram_capacity,
              "Failed check for SPD DRAM capacity") );
    // Decoding bits 5~4
    l_spd_buffer.extractToRight<SDRAM_BANKS_START, SDRAM_BANKS_LEN>(l_sdram_banks);

    // Check to assure SPD DRAM banks (map) wont be at invalid values
    FAPI_TRY( mss::check::spd::valid_value_fail(i_target_dimm,
              (l_sdram_banks <= BANKS_MAX_VALID_KEY),
              BYTE_INDEX,
              l_sdram_banks,
              "Failed check for SPD DRAM banks") );

    // Decoding bits 7~6
    l_spd_buffer.extractToRight<BANK_GROUP_START, BANK_GROUP_LEN>(l_sdram_bank_group);

    // Check to assure SPD DRAM banks groups (map) wont be at invalid values
    FAPI_TRY( mss::check::spd::valid_value_fail(i_target_dimm,
              (l_sdram_bank_group <= BANK_GRP_MAX_VALID_KEY),
              BYTE_INDEX,
              l_sdram_bank_group,
              "Failed check for SPD DRAM bank groups") );

    // Retrive entire MCS level attribute
    FAPI_TRY( eff_dram_density(l_target_mcs, &l_capacities[0][0]) );
    FAPI_TRY( eff_dram_banks(l_target_mcs, &l_banks[0][0]) );
    FAPI_TRY( eff_dram_bank_groups(l_target_mcs, &l_bank_groups[0][0]) );

    // Update attribute to decoded byte values
    l_capacities[PORT_NUM][DIMM_NUM] = sdram_capacity_map[l_sdram_capacity - CAPACITY_MAP_OFFSET];
    l_banks[PORT_NUM][DIMM_NUM] = sdram_banks_map[l_sdram_banks];
    l_bank_groups[PORT_NUM][DIMM_NUM] = sdram_bankgroups_map[l_sdram_bank_group];

    // Update MCS level attribute
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_DENSITY, l_target_mcs, l_capacities));
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_BANKS, l_target_mcs, l_banks));
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_BANK_GROUPS, l_target_mcs, l_bank_groups));

    FAPI_INF("%s. SDRAM capacity: %d, banks: %d, bank groups: %d",
             c_str(i_target_dimm),
             sdram_capacity_map[l_sdram_capacity],
             sdram_banks_map[l_sdram_banks],
             sdram_bankgroups_map[l_sdram_bank_group]);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decode SDRAM addressing
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       SPD Byte 5
///
fapi2::ReturnCode decoder::sdram_addressing(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX = 5;
    // DRAM column address mapping limits
    const size_t COLUMN_MAX_VALID_KEY = 3; // The rest are not supported or reserved
    // DRAM row address mapping limits
    const size_t ROW_MAX_VALID_KEY = 6; // The rest are not supported or reserved

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Byte variables used for decoding
    uint8_t l_column_addr = 0;
    uint8_t l_row_addr = 0;
    uint8_t l_reserved = 0;

    // Attribute variables used to set decoded vals
    uint8_t l_columns[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};
    uint8_t l_rows[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Buffer used for bit manipulation
    fapi2::buffer<uint8_t> l_spd_buffer(i_spd_data[BYTE_INDEX]);

    // Trace in the front assists w/ debug
    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Decoding bits 2~0 (Column Address bits)
    l_spd_buffer.extractToRight<COL_ADDRESS_START, COL_ADDRESS_LEN>(l_column_addr);

    // Check to assure SPD DRAM Column Address bits (map) wont be indexed at invalid values
    FAPI_TRY(mss::check::spd::valid_value_fail(i_target_dimm,
             (l_column_addr <= COLUMN_MAX_VALID_KEY),
             BYTE_INDEX,
             l_column_addr,
             "Failed check for SPD DRAM bank groups") );

    // Decoding bits 3~0 (Row address bits)
    l_spd_buffer.extractToRight<ROW_ADDRESS_START, ROW_ADDRESS_LEN>(l_row_addr);

    // Check to assure SPD DRAM Row address bits (map) wont be at invalid values
    FAPI_TRY( mss::check::spd::valid_value_fail(i_target_dimm,
              (l_row_addr <= ROW_MAX_VALID_KEY),
              BYTE_INDEX,
              l_row_addr,
              "Failed check for SPD DRAM bank groups") );

    // Decoding bits 7~6
    l_spd_buffer.extractToRight<ADDRESS_RESERVED_START, ADDRESS_RESERVED_LEN>(l_reserved);

    // Check to assure SPD reserved bits are 0 as defined in JEDEC SPD spec
    FAPI_TRY( mss::check::spd::valid_value_fail(i_target_dimm,
              (l_reserved == 0),
              BYTE_INDEX,
              l_reserved,
              "Failed check for SPD DRAM bank groups") );

    // Retrive entire MCS level attribute
    FAPI_TRY( eff_dram_cols(l_target_mcs, &l_columns[0][0]) );
    FAPI_TRY( eff_dram_rows(l_target_mcs, &l_rows[0][0]) );

    // Update attribute to decoded byte values
    l_columns[PORT_NUM][DIMM_NUM] = column_address_map[l_column_addr];
    l_rows[PORT_NUM][DIMM_NUM] = row_address_map[l_row_addr];

    // Update MCS level attribute
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_COLS, l_target_mcs, l_columns));
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_ROWS, l_target_mcs, l_rows));

    FAPI_INF("%s. Columns: %d, Rows: %d",
             c_str(i_target_dimm),
             l_columns[PORT_NUM][DIMM_NUM],
             l_rows[PORT_NUM][DIMM_NUM]);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief      Decode SDRAM Package Type
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       SPD Byte 6
///
fapi2::ReturnCode decoder::primary_package_type(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX = 6;
    const size_t INVALID_VALUE = 0x11; //per JEDEC spec
    const size_t RESERVED = 0;

    // DRAM die count mapping limits
    const size_t DIE_COUNT_MAX_VALID_KEY = 7; // Nothing greater doesn't exist
    const size_t INVALID_PACKAGE_TYPE = ~0;

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Byte variables used for decoding
    uint8_t l_prim_signal_loading = 0;
    uint8_t l_reserved = 0;
    uint8_t l_prim_die_count = 0;
    uint8_t l_prim_package_type = 0;

    // Attribute variables used to set decoded vals
    uint8_t l_stack_type = 0;
    uint8_t l_sdram_package_type[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};
    uint8_t l_sdram_die_count[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Buffer used for bit manipulation
    fapi2::buffer<uint8_t> l_spd_buffer(i_spd_data[BYTE_INDEX]);

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Decoding bits 1~0 (Signal loading)
    l_spd_buffer.extractToRight<PRIM_PRIM_SIGNAL_LOAD_START, PRIM_PRIM_SIGNAL_LOAD_LEN>(l_prim_signal_loading);

    // Check to assure SPD DRAM signal loading conforms to JEDEC SPEC
    FAPI_TRY( mss::check::spd::valid_value_fail(i_target_dimm,
              (l_prim_signal_loading != INVALID_VALUE),
              BYTE_INDEX,
              l_prim_signal_loading,
              "Failed check for SPD DRAM signal loading") );
    // Decoding bits 3~2 (Reserved)
    l_spd_buffer.extractToRight<PACKAGE_RESERVE_START, PACKAGE_RESERVE_LEN>(l_reserved);

    // Check to assure SPD reserved bits are 0 as defined in JEDEC SPD spec
    mss::check::spd::valid_value_warn(i_target_dimm,
                                      (l_reserved == RESERVED),
                                      BYTE_INDEX,
                                      l_reserved,
                                      "Failed check for SPD DRAM reserved bits");

    // Decoding bits 6~4 (Die Count)
    l_spd_buffer.extractToRight<PRIM_DIE_COUNT_START, PRIM_DIE_COUNT_LEN>(l_prim_die_count);

    FAPI_TRY( mss::check::spd::valid_value_fail(i_target_dimm,
              (l_prim_die_count <= DIE_COUNT_MAX_VALID_KEY),
              BYTE_INDEX,
              l_prim_die_count,
              "Failed check for SPD DRAM die count") );
    // Decoding bit 7
    l_spd_buffer.extractToRight<PRIM_PACKAGE_TYPE_START, PRIM_PACKAGE_TYPE_LEN>(l_prim_package_type);

    // Manipulating and combining l_prim_package_type and l_prim_signal_loading to produce the following
    // table for indexing the package_type_map[].
    // 0000 0000 = SDP (monolithic device)
    // 0000 0101 = DDP/QDP (non-monolithic device)
    // 0000 0110 = 3DS (non-monolithic device)
    // What this essentially does is remove reserved bits.
    // This was done to avoid having large gaps (of 0's) in the package_type_map (sparsed array)
    // since we can't use std::map due to thread saftey issues
    l_stack_type = (l_prim_package_type >> 5) | l_prim_signal_loading;

    FAPI_TRY( mss::check::spd::valid_value_fail(i_target_dimm,
              check::stack_type(l_stack_type, die_count_map[l_prim_die_count]) &&
              (package_type_map[l_stack_type] != INVALID_PACKAGE_TYPE),
              BYTE_INDEX,
              package_type_map[l_stack_type],
              "Failed check for SPD DRAM stack type") );

    // Retrive entire MCS level attribute
    FAPI_TRY( eff_stack_type(l_target_mcs, &l_sdram_package_type[0][0]) );
    FAPI_TRY( eff_prim_die_count(l_target_mcs, &l_sdram_die_count[0][0]) );

    // Update attribute to decoded byte values
    l_sdram_die_count[PORT_NUM][DIMM_NUM] = die_count_map[l_prim_die_count];
    l_sdram_package_type[PORT_NUM][DIMM_NUM] = package_type_map[l_stack_type];

    // Update MCS level attribute
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_STACK_TYPE, l_target_mcs, l_sdram_package_type));
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_PRIM_DIE_COUNT, l_target_mcs, l_sdram_die_count));

    FAPI_INF("%s. Signal loading: %d, Die count: %d, Stack type: %d",
             c_str(i_target_dimm),
             l_prim_signal_loading,
             die_count_map[l_prim_die_count],
             l_sdram_package_type[PORT_NUM][DIMM_NUM]);

fapi_try_exit:
    return fapi2::current_err;
}

//TODO
// Need to complete this function, map need tREF1 calculations

///
/// @brief      Decode SDRAM Optional Features
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       SPD Byte 7
///
fapi2::ReturnCode decoder::sdram_optional_features(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX = 7;
    const size_t RESERVED = 0;

    // MAC mapping limits
    const size_t MAC_RESERVED = 7; //per JEDEC spec
    const size_t MAC_MAX_VALID_KEY = 8;

    // TMAW mappint limits
    const size_t TMAW_MAX_VALID_KEY = 2;

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Byte variables used for decoding
    uint16_t l_MAC = 0; // Maximum Active Count
    uint16_t l_tMAW = 0; // Maximum Active Window
    uint8_t l_reserved = 0;

    // Attribute variables used to set decoded vals
    uint16_t l_mac[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};
    uint16_t l_tmaw[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Buffer used for bit manipulation
    fapi2::buffer<uint8_t> l_spd_buffer(i_spd_data[BYTE_INDEX]);

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Decoding bits 3~0 (MAC)
    l_spd_buffer.extractToRight<MAC_START, MAC_LEN>(l_MAC);
    // Check to assure SPD DRAM signal loading conforms to JEDEC SPEC
    FAPI_TRY( mss::check::spd::valid_value_fail(i_target_dimm,
              (l_MAC <= MAC_MAX_VALID_KEY) &&
              l_MAC != MAC_RESERVED,
              BYTE_INDEX,
              l_MAC,
              "Failed check for Maximum Active Count (MAC)") );

    // Decoding bits 5~4 (tMAW)
    l_spd_buffer.extractToRight<TMAW_START, TMAW_LEN>(l_tMAW);

    // Check to assure SPD DRAM signal loading conforms to JEDEC SPEC
    FAPI_TRY( mss::check::spd::valid_value_fail(i_target_dimm,
              (l_tMAW <= TMAW_MAX_VALID_KEY),
              BYTE_INDEX,
              l_tMAW,
              "Failed check for Maximum Active Window (tMAW)") );

    // Decoding bits 7~6 (Reserved)
    l_spd_buffer.extractToRight<OPT_FEAT_RESERVED_START, OPT_FEAT_RESERVED_LEN>(l_reserved);

    mss::check::spd::valid_value_warn(i_target_dimm,
                                      (l_reserved == RESERVED),
                                      BYTE_INDEX,
                                      l_reserved,
                                      "Failed check for Reserved bits") ;

    // Retrive entire MCS level attribute
    FAPI_TRY(eff_dram_mac(l_target_mcs, &l_mac[0][0]));
    FAPI_TRY(eff_dram_tmaw(l_target_mcs, &l_tmaw[0][0]));

    // Update attribute to decoded byte values
    l_mac[PORT_NUM][DIMM_NUM] = MAC_map[l_MAC];
    l_tmaw[PORT_NUM][DIMM_NUM] = tMAW_map[l_tMAW];

    // Update MCS level attribute
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_MAC, l_target_mcs, l_mac));
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_TMAW, l_target_mcs, l_tmaw));

    // Print decoded info
    FAPI_INF("%s. MAC: %d, tMAW: %d",
             c_str(i_target_dimm),
             l_tmaw[PORT_NUM][DIMM_NUM],
             l_mac[PORT_NUM][DIMM_NUM]);

fapi_try_exit:
    return fapi2::current_err;
}// decode_sdram_optional_features()

///
/// @brief      Decode SDRAM Thermal and Refresh Options
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       SPD Byte 8, currently reserved
///
fapi2::ReturnCode decoder::thermal_and_refresh_options(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX = 8;
    const size_t RESERVED_BYTE = 0; // per JEDEC spec

    // Byte variable
    uint8_t l_reserved = i_spd_data[BYTE_INDEX];

    // Check to assure SPD reserved byte is 0 per JEDEC spec
    FAPI_TRY( mss::check::spd::valid_value_fail(i_target_dimm,
              (l_reserved == RESERVED_BYTE),
              BYTE_INDEX,
              l_reserved,
              "Failed check for SPD DRAM reserved byte") );

    // Print decoded info
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

fapi_try_exit:
    return fapi2::current_err;
}// decode_thermal_and_refresh_options()


///
/// @brief      Decode Other SDRAM Optional Features
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       SPD Byte 9
///
fapi2::ReturnCode decoder::other_optional_features(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX = 9;
    const size_t RESERVED = 0;

    // Soft PPR mapping limits
    const size_t SOFT_PPR_MAX_VALID_KEY = 2; // Nothing greater doesn't exist

    // PPR mapping limits
    const size_t PPR_MAX_VALID_KEY = 2; // Nothing greater doesn't exist

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Byte variables used for decoding
    uint8_t l_reserved = 0;
    uint8_t l_soft_ppr = 0;// Soft Post Package Repair
    uint8_t l_ppr = 0; // Post Package Repair

    // Attribute variables used to set decoded vals
    uint8_t l_soft_PPRs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};
    uint8_t l_PPRs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Buffer used for bit manipulation
    fapi2::buffer<uint8_t> l_spd_buffer(i_spd_data[BYTE_INDEX]);

    // Decoding bits 4~0
    l_spd_buffer.extractToRight<PPR_RESERVED_START, PPR_RESERVED_LEN>(l_reserved);

    mss::check::spd::valid_value_warn(i_target_dimm,
                                      (l_reserved == RESERVED),
                                      BYTE_INDEX,
                                      l_reserved,
                                      "Failed check for reserved bits");

    // Decoding bit 5
    l_spd_buffer.extractToRight<SOFT_PPR_START, SOFT_PPR_LEN>(l_soft_ppr);

    FAPI_TRY( mss::check::spd::valid_value_fail(i_target_dimm,
              (l_soft_ppr < SOFT_PPR_MAX_VALID_KEY),
              BYTE_INDEX,
              l_soft_ppr,
              "Failed check for SOFT PPR") );

    // Decoding bits 7~6
    l_spd_buffer.extractToRight<PPR_START, PPR_LEN>(l_ppr);

    FAPI_TRY( mss::check::spd::valid_value_fail(i_target_dimm,
              (l_ppr < PPR_MAX_VALID_KEY),
              BYTE_INDEX,
              l_ppr,
              "Failed check for PPR") );

    // Retrive entire MCS level attribute
    FAPI_TRY(eff_dram_soft_ppr(l_target_mcs, &l_soft_PPRs[0][0]));
    FAPI_TRY(eff_dram_ppr(l_target_mcs, &l_PPRs[0][0]));

    // Update attribute to decoded byte values
    l_soft_PPRs[PORT_NUM][DIMM_NUM] = soft_ppr_map[l_soft_ppr];
    l_PPRs[PORT_NUM][DIMM_NUM] = ppr_map[l_ppr];

    // Update MCS level attribute
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_SOFT_PPR, l_target_mcs, l_soft_PPRs));
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_PPR, l_target_mcs, l_PPRs));

    // Printed decoded info
    FAPI_INF("%s. Soft PPR: %d, PPR: %d, Reserved: %d",
             c_str(i_target_dimm),
             l_soft_PPRs[PORT_NUM][DIMM_NUM],
             l_PPRs[PORT_NUM][DIMM_NUM],
             l_reserved);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decode Secondary SDRAM Package Type
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       SPD Byte 10
///
fapi2::ReturnCode decoder::secondary_package_type(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX = 10;
    const size_t SUPPORTED_VALUE = 0;

    // Byte variables used for decoding
    uint8_t l_sec_signal_loading = 0;
    uint8_t l_density_ratio = 0;
    uint8_t l_sec_die_count = 0;
    uint8_t l_sec_package_type = 0;

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Currently we do not support asymmetrical assembly of multiple SDRAM package types
    // According to the JEDEC spec, for modules with symmetrical assembly (which we do support),
    // this byte must be coded as 0x00.  Additional checks were added to isolate any corrupt data failure

    // Buffer used for bit manipulation
    fapi2::buffer<uint8_t> l_spd_buffer(i_spd_data[BYTE_INDEX]);

    // Decoding bits 1~0 (Signal loading)
    l_spd_buffer.extractToRight<SEC_SIGNAL_LOAD_START, SEC_SIGNAL_LOAD_LEN>(l_sec_signal_loading);

    // Check to assure SPD DRAM signal loading conforms to JEDEC SPEC
    FAPI_TRY( mss::check::spd::valid_value_fail(i_target_dimm,
              (l_sec_signal_loading == SUPPORTED_VALUE),
              BYTE_INDEX,
              l_sec_signal_loading,
              "Failed check for SPD DRAM signal loading") );

    // Decoding bits 3~2 (Density Ratio)
    l_spd_buffer.extractToRight<DENSITY_RATIO_START, DENSITY_RATIO_LEN>(l_density_ratio);

    // Check to assure SPD density ratio bits are 0 to assure symmetical package
    FAPI_TRY( mss::check::spd::valid_value_fail(i_target_dimm,
              (l_density_ratio == SUPPORTED_VALUE),
              BYTE_INDEX,
              l_density_ratio,
              "Failed check for SPD DRAM density ratio") );

    // Decoding bits 6~4 (Die Count)
    l_spd_buffer.extractToRight<SEC_DIE_COUNT_START, SEC_DIE_COUNT_LEN>(l_sec_die_count);

    FAPI_TRY( mss::check::spd::valid_value_fail(i_target_dimm,
              (l_sec_die_count  == SUPPORTED_VALUE),
              BYTE_INDEX,
              l_sec_die_count,
              "Failed check for SPD DRAM secondary die count") );

    // Decoding bit 7
    l_spd_buffer.extractToRight<SEC_PACKAGE_TYPE_START, SEC_PACKAGE_TYPE_LEN>(l_sec_package_type);

    FAPI_TRY( mss::check::spd::valid_value_fail(i_target_dimm,
              (l_sec_package_type == SUPPORTED_VALUE),
              BYTE_INDEX,
              l_sec_package_type,
              "Failed check for SPD DRAM secondary package type") );

    // Printed decoded info
    FAPI_INF("Signal Loading: %d, DRAM Density Ratio: %d, Die Count: %d, SDRAM Package Type: %d",
             l_sec_signal_loading,
             l_density_ratio,
             l_sec_die_count,
             l_sec_package_type);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decode Module Nominal Voltage, VDD
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       SPD Byte 11
///
fapi2::ReturnCode decoder::module_nominal_voltage(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX = 11;
    const size_t RESERVED = 0; // per JEDEC sepc
    const size_t SUPPORTED = 1; // per JEDEC sepc
    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Byte variables used for decoding
    uint8_t l_operable = 0;
    uint8_t l_endurant = 0;
    uint8_t l_reserved = 0;

    // Attribute variables used to set decoded vals
    uint64_t l_operable_attrs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Buffer used for bit manipulation
    fapi2::buffer<uint8_t> l_spd_buffer(i_spd_data[BYTE_INDEX]);

    // Decoding bits 0 (Operable)
    l_spd_buffer.extractToRight<OPERABLE_START, OPERABLE_LEN>(l_operable);

    // DDR4 only supports 1.2 V, if not OPERABLE at this voltage than fail IPL
    FAPI_TRY( mss::check::spd::valid_value_fail(i_target_dimm,
              l_operable == SUPPORTED,
              BYTE_INDEX,
              l_operable,
              "Failed check for OPERABLE module nominal voltage") );
    // Decoding bits 1 (Endurant)
    l_spd_buffer.extractToRight<ENDURANT_START, ENDURANT_LEN>(l_endurant);

    // OPERABLE at 1.2V implies ENDURANT at 1.2V
    FAPI_TRY( mss::check::spd::valid_value_fail(i_target_dimm,
              l_endurant == SUPPORTED,
              BYTE_INDEX,
              l_endurant,
              "Failed check for ENDURABLE module nominal voltage") );

    // Decoding bits 7~2  (Reserved)
    l_spd_buffer.extractToRight<NOM_VOLT_START, NOM_VOLT_LEN>(l_reserved);

    mss::check::spd::valid_value_warn(i_target_dimm,
                                      l_reserved == RESERVED,
                                      BYTE_INDEX,
                                      l_reserved,
                                      "Failed check for module nominal voltage RESERVED bits");

    // Retrive entire MCS level attribute
    FAPI_TRY(spd_module_nominal_voltage(l_target_mcs, &l_operable_attrs[0][0]));

    // Update attribute to decoded byte values
    l_operable_attrs[PORT_NUM][DIMM_NUM] = l_operable;

    // Update MCS level attribute
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_SPD_MODULE_NOMINAL_VOLTAGE, l_target_mcs, l_operable_attrs) );

    // Printed decoded info
    FAPI_INF( "%s Operable: %d,  Endurant: %d, Reserved: %d",
              c_str(i_target_dimm),
              l_operable,
              l_endurant,
              l_reserved );


fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decode Module Organization
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       SPD Byte 12
///
fapi2::ReturnCode decoder::module_organization(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX = 12;
    const size_t RESERVED = 0;

    // SDRAM device width mapping limits
    const size_t MAX_DEV_WIDTH_VALID_KEY = 3; // All others reserved

    // Number of package ranks per DIMM mapping limits
    const size_t MAX_PKG_RANKS_VALID_KEY = 7; // max supported packages

    // Rank mix limits
    const size_t SYMMETRICAL = 0; // asymmetical not supported

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Byte variables used for decoding
    uint8_t l_device_width = 0;
    uint8_t l_num_pkgs_ranks = 0;
    uint8_t l_rank_mix = 0;
    uint8_t l_reserved = 0;

    // Attribute variables used to set decoded vals
    uint8_t l_sdram_device_widths[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};
    uint8_t l_num_pkg_ranks_per_dimm[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};
    uint8_t l_rank_mixes[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};


    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Buffer used for bit manipulation
    fapi2::buffer<uint8_t> l_spd_buffer(i_spd_data[BYTE_INDEX]);

    // Decoding Bits 2~0
    l_spd_buffer.extractToRight<SDRAM_WIDTH_START, SDRAM_WIDTH_LEN>(l_device_width);

    FAPI_TRY( mss::check::spd::valid_value_fail(i_target_dimm,
              l_device_width <= MAX_DEV_WIDTH_VALID_KEY,
              BYTE_INDEX,
              l_device_width,
              "Failed check for SDRAM device width") );
    // Decoding Bits 5~3
    l_spd_buffer.extractToRight<PACKAGE_RANKS_START, PACKAGE_RANKS_LEN>(l_num_pkgs_ranks);

    FAPI_TRY( mss::check::spd::valid_value_fail(i_target_dimm,
              l_num_pkgs_ranks <= MAX_PKG_RANKS_VALID_KEY,
              BYTE_INDEX,
              l_num_pkgs_ranks,
              "Failed check for number of packages per DIMM") );
    // Decoding Bit 6
    l_spd_buffer.extractToRight<RANK_MIX_START, RANK_MIX_LEN>(l_rank_mix);

    // We only support symmetrical rank mix
    FAPI_TRY( mss::check::spd::valid_value_fail(i_target_dimm,
              l_rank_mix == SYMMETRICAL,
              BYTE_INDEX,
              l_rank_mix,
              "Failed check for number of packages per DIMM") );
    // Decoding Bit 7
    l_spd_buffer.extractToRight<MODULE_ORG_RESERVED_START, MODULE_ORG_RESERVED_LEN>(l_reserved);

    mss::check::spd::valid_value_warn(i_target_dimm,
                                      l_reserved == RESERVED,
                                      BYTE_INDEX,
                                      l_reserved,
                                      "Failed check for number of packages per DIMM");

    // Retrive entire MCS level attribute
    FAPI_TRY(eff_dram_width(l_target_mcs, &l_sdram_device_widths[0][0]));
    FAPI_TRY(eff_num_packages_per_rank(l_target_mcs, &l_num_pkg_ranks_per_dimm[0][0]));
    FAPI_TRY(eff_dram_rank_mix(l_target_mcs, &l_rank_mixes[0][0]));

    // Update attribute to decoded byte values
    l_sdram_device_widths[PORT_NUM][DIMM_NUM] = device_type_map[l_device_width];
    l_num_pkg_ranks_per_dimm[PORT_NUM][DIMM_NUM] = num_pkgs_ranks_per_dimm_map[l_num_pkgs_ranks];
    l_rank_mixes[PORT_NUM][DIMM_NUM] = l_rank_mix;

    // Update MCS level attribute
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_WIDTH, l_target_mcs, l_sdram_device_widths) );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_NUM_PACKAGES_PER_RANK, l_target_mcs, l_num_pkg_ranks_per_dimm) );
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_RANK_MIX, l_target_mcs, l_rank_mixes) );

    // Printed decoded info
    FAPI_INF( "%s. Device Width: %d, Number of rank packages per DIMM: %d, Rank Mix: %d",
              c_str(i_target_dimm),
              l_sdram_device_widths[PORT_NUM][DIMM_NUM],
              l_num_pkg_ranks_per_dimm[PORT_NUM][DIMM_NUM],
              l_rank_mixes[PORT_NUM][DIMM_NUM] );

fapi_try_exit:
    return fapi2::current_err;
}

//TODO
// Returning correct stuff (bits) ?? Or am I supposed to calc "Module DRAM Capacity" pg 27

///
/// @brief      Decode Module Memory Bus Width
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       SPD Byte 13
///
fapi2::ReturnCode decoder::module_memory_bus_width(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX = 13;
    const size_t RESERVED = 0;

    // Primary bus width mapping limits
    const size_t MAX_PRIM_BUS_WIDTH_KEY = 3; // All others reserved

    // Bus width extention mapping limits
    const size_t MAX_VALID_BUS_WIDTH_EXT_KEY = 1; // All others reserved

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Byte variables used for decoding
    uint8_t l_bus_width = 0;
    uint8_t l_bus_width_ext = 0;
    uint8_t l_reserved = 0;

    // Attribute variables used to set decoded vals
    uint8_t l_module_bus_widths[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Buffer used for bit manipulation
    fapi2::buffer<uint8_t> l_spd_buffer(i_spd_data[BYTE_INDEX]);

    // Decoding Bits 2~0
    l_spd_buffer.extractToRight<BUS_WIDTH_START, BUS_WIDTH_LEN>(l_bus_width);

    FAPI_TRY( mss::check::spd::valid_value_fail(i_target_dimm,
              l_bus_width <= MAX_PRIM_BUS_WIDTH_KEY,
              BYTE_INDEX,
              l_bus_width,
              "Failed check on primary bus width") );
    // Decoding Bits 4~3
    l_spd_buffer.extractToRight<BUS_EXT_WIDTH_START, BUS_EXT_WIDTH_LEN>(l_bus_width_ext);

    FAPI_TRY( mss::check::spd::valid_value_fail(i_target_dimm,
              l_bus_width_ext <= MAX_VALID_BUS_WIDTH_EXT_KEY,
              BYTE_INDEX,
              l_bus_width_ext,
              "Failed check for bus width extension") );
    // Decoding bits Bits 7~5
    l_spd_buffer.extractToRight<BUS_WIDTH_RESERVED_START, BUS_WIDTH_RESERVED_LEN>(l_reserved);

    mss::check::spd::valid_value_warn(i_target_dimm,
                                      l_reserved == RESERVED,
                                      BYTE_INDEX,
                                      l_reserved,
                                      "Failed check for bus width reserved bits");

    // Retrive entire MCS level attribute
    FAPI_TRY( eff_dram_module_bus_width(l_target_mcs, &l_module_bus_widths[0][0]) );

    // Update attribute to decoded byte values
    l_module_bus_widths[PORT_NUM][DIMM_NUM] = prim_bus_width_map[l_bus_width] + bus_width_ext_map[l_bus_width_ext];

    // Update MCS level attribute
    FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_MODULE_BUS_WIDTH, l_target_mcs, l_module_bus_widths);

    // Printed decoded info
    FAPI_INF( "%s Module Memory Bus Width (in bits): %d, Primary bus width: %d, Bus width extension: %d",
              c_str(i_target_dimm),
              l_module_bus_widths[PORT_NUM][DIMM_NUM],
              prim_bus_width_map[l_bus_width],
              bus_width_ext_map[l_bus_width_ext] );

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief      Decode Module Thermal Sensor
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       SPD Byte 14, no attribute found for this
///
fapi2::ReturnCode decoder::module_thermal_sensor(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX = 14;
    const size_t VALID_VALUE = 1;
    const size_t RESERVED = 0;

    // Byte variables used for decoding
    uint8_t l_reserved = 0;
    uint8_t l_thermal_sensor = 0;

    // Attribute variables used to set decoded vals
    uint8_t l_therm_sensors[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Buffer used for bit manipulation
    fapi2::buffer<uint8_t> l_spd_buffer(i_spd_data[BYTE_INDEX]);

    // Decoding Bits 6~0
    l_spd_buffer.extractToRight<THERM_SENSOR_RESERV_START, THERM_SENSOR_RESERV_LEN>(l_reserved);

    mss::check::spd::valid_value_warn(i_target_dimm,
                                      l_reserved == RESERVED,
                                      BYTE_INDEX,
                                      l_reserved,
                                      "Failed check for thermal sensor reserved bits");
    // Decoding bits Bit 7
    l_spd_buffer.extractToRight<THERM_SENSOR_START, THERM_SENSOR_LEN>(l_thermal_sensor);

    // Length is a single bit (0 or 1), anything larger means corrupt data
    FAPI_TRY( mss::check::spd::valid_value_fail(i_target_dimm,
              l_thermal_sensor <= VALID_VALUE,
              BYTE_INDEX,
              l_thermal_sensor,
              "Failed check for thermal sensor") );

    // Retrive entire MCS level attribute
    FAPI_TRY( spd_module_thermal_sensor(l_target_mcs, &l_therm_sensors[0][0]) );

    // Update attribute to decoded byte values
    l_therm_sensors[PORT_NUM][DIMM_NUM] = l_thermal_sensor;

    // Update MCS level attribute
    FAPI_ATTR_SET(fapi2::ATTR_SPD_MODULE_THERMAL_SENSOR, l_target_mcs, l_therm_sensors);

    // Printed decoded info
    FAPI_INF("%s. Thermal sensor: %d, Reserved: %d",
             c_str(i_target_dimm),
             l_thermal_sensor,
             l_reserved );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decode Extended Module Type
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       SPD Byte 15, no attribute for this byte
///
fapi2::ReturnCode decoder::extended_module_type(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX = 15;
    const size_t RESERVED = 0;

    // Byte variables used for decoding
    uint8_t l_ext_module_type = 0;
    uint8_t l_reserved = 0;

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Buffer used for bit manipulation
    fapi2::buffer<uint8_t> l_spd_buffer(i_spd_data[BYTE_INDEX]);

    // Decoding Bits 3~0
    l_spd_buffer.extractToRight<EXT_MOD_TYPE_START, EXT_MOD_TYPE_LEN>(l_ext_module_type);

    // According to JEDEC spec this value should be coded as 0000 which is the value as the reserved bits
    FAPI_TRY(mss::check::spd::valid_value_fail(i_target_dimm,
             l_ext_module_type == RESERVED,
             BYTE_INDEX,
             l_ext_module_type,
             "Failed check for extended base module type") );
    // Decoding Bit 7~4
    l_spd_buffer.extractToRight<EXT_MOD_TYPE_RESERV_START, EXT_MOD_TYPE_RESERV_LEN>(l_reserved);

    mss::check::spd::valid_value_warn(i_target_dimm,
                                      l_reserved == RESERVED,
                                      BYTE_INDEX,
                                      l_reserved,
                                      "Failed check for extended module type reserved bits");

    // Printed decoded info
    FAPI_INF("%s. Extended Base Module Type: %d, Reserved: %d",
             c_str(i_target_dimm),
             l_ext_module_type,
             l_reserved );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decode Timebases
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       SPD Byte 17
///
fapi2::ReturnCode decoder::timebases(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
                                     const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX = 17;
    const size_t RESERVED = 0;

    // Medium timebase mapping limits
    const int64_t MAX_VALID_MTB_KEY = 1; // All others reserved

    // Fine timebase mapping limits
    const int64_t MAX_VALID_FTB_KEY = 1; // All others reserved

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Byte variables used for decoding
    int64_t l_fine_timebase = 0;
    int64_t l_medium_timebase = 0;
    int64_t l_reserved = 0;

    // Attribute variables used to set decoded vals
    int64_t l_FTBs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};
    int64_t l_MTBs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Buffer used for bit manipulation
    fapi2::buffer<uint8_t> l_spd_buffer(i_spd_data[BYTE_INDEX]);

    // TODO - update ENUMS to take account to int64_t
    // Decoding Bits 1~0
    l_spd_buffer.extractToRight<FINE_TIMEBASE_START, FINE_TIMEBASE_LEN>(l_fine_timebase);

    FAPI_TRY(mss::check::spd::valid_value_fail(i_target_dimm,
             l_fine_timebase < MAX_VALID_FTB_KEY,
             BYTE_INDEX,
             l_fine_timebase,
             "Failed check for fine timebase") );
    // Decoding Bits 3~2
    l_spd_buffer.extractToRight<MED_TIMEBASE_START, MED_TIMEBASE_LEN>(l_medium_timebase);

    FAPI_TRY(mss::check::spd::valid_value_fail(i_target_dimm,
             l_medium_timebase < MAX_VALID_MTB_KEY,
             BYTE_INDEX,
             l_medium_timebase,
             "Failed check for medium timebase") );
    // Decoding bits Bits 7~4
    l_spd_buffer.extractToRight<TIMEBASE_RESERV_START, TIMEBASE_RESERV_LEN>(l_reserved);

    mss::check::spd::valid_value_warn(i_target_dimm,
                                      l_reserved == RESERVED,
                                      BYTE_INDEX,
                                      l_reserved,
                                      "Failed check for timebases reserved bits");

    // Retrive entire MCS level attribute
    FAPI_TRY( spd_fine_timebase(l_target_mcs, &l_FTBs[0][0]) );
    FAPI_TRY( spd_medium_timebase(l_target_mcs, &l_MTBs[0][0]) );

    // Update attribute to decoded byte values
    l_FTBs[PORT_NUM][DIMM_NUM] =  fine_timebase_map[l_fine_timebase];
    l_MTBs[PORT_NUM][DIMM_NUM] = medium_timebase_map[l_medium_timebase];

    // Update MCS level attribute
    FAPI_ATTR_SET( fapi2::ATTR_SPD_FINE_TIMEBASE, l_target_mcs, l_FTBs );
    FAPI_ATTR_SET( fapi2::ATTR_SPD_MEDIUM_TIMEBASE, l_target_mcs, l_MTBs );

    // Printed decoded info
    FAPI_INF( "%s. Fine Timebase: %d, Medium Timebase: %d",
              c_str(i_target_dimm),
              l_FTBs[PORT_NUM][DIMM_NUM],
              l_MTBs[PORT_NUM][DIMM_NUM] );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decode SDRAM Minimum Cycle Time
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       SPD Byte 18 & Byte 125
///             This byte depends on the fine & medium timebase values
///             obtained from Byte 17
///
fapi2::ReturnCode decoder::min_cycle_time(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX_MTB = 18; // min cycle medium timebase (mtb)
    const size_t BYTE_INDEX_FTB = 125; // min cycle fine timebase (ftb)

    const int64_t MIN_CYCLE_TIME_MTB = 1; // from JEDEC
    const int64_t MAX_CYCLE_TIME_MTB = 255; // from JEDEC

    const int64_t MIN_CYCLE_TIME_FTB = -128; // from JEDEC
    const int64_t MAX_CYCLE_TIME_FTB = 127; // from JEDEC

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Byte variables used for decoding
    int64_t l_tCKmin_mtb = 0;
    int64_t l_tCKmin_ftb = 0;

    // Attribute variables
    int64_t l_min_cycle_times[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};
    int64_t l_MTBs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};
    int64_t l_FTBs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX_MTB,
             i_spd_data[BYTE_INDEX_MTB]);

    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX_FTB,
             i_spd_data[BYTE_INDEX_FTB]);

    // Retrieve SDRAM Maximum Cycle Time
    l_tCKmin_mtb = i_spd_data[BYTE_INDEX_MTB];

    FAPI_TRY(mss::check::spd::valid_value_fail(i_target_dimm,
             (l_tCKmin_mtb <= MAX_CYCLE_TIME_MTB) &&
             (l_tCKmin_mtb >= MIN_CYCLE_TIME_MTB),
             BYTE_INDEX_MTB,
             l_tCKmin_mtb,
             "Failed check for tCKmin (min cycle time) in MTB units") );

    // Retrieve Fine Offset for SDRAM Minimum Cycle Time
    // casted int8_t undoes 2's complement on the uint8_t spd data
    l_tCKmin_ftb = int8_t(i_spd_data[BYTE_INDEX_FTB]);

    FAPI_TRY(mss::check::spd::valid_value_fail(i_target_dimm,
             (l_tCKmin_ftb <= MAX_CYCLE_TIME_FTB) &&
             (l_tCKmin_ftb >= MIN_CYCLE_TIME_FTB),
             BYTE_INDEX_FTB,
             l_tCKmin_ftb,
             "Failed check for tCKmin (min cycle time) in FTB units") );


    // Retrieving medium timebase (MTB) multiplier used for timing calculation
    FAPI_TRY( spd_medium_timebase(l_target_mcs, &l_MTBs[0][0]) );
    FAPI_TRY( spd_fine_timebase(l_target_mcs, &l_FTBs[0][0]) );

    // Retrive entire MCS level attribute
    FAPI_TRY( spd_timing_tckmin(l_target_mcs, &l_min_cycle_times[0][0]) );

    // Update attribute to decoded byte values
    // Calculating minimum cycle time in picosconds
    l_min_cycle_times[PORT_NUM][DIMM_NUM] = calc_timing(l_tCKmin_mtb,
                                            l_tCKmin_ftb,
                                            l_MTBs[PORT_NUM][DIMM_NUM],
                                            l_FTBs[PORT_NUM][DIMM_NUM]);
    // Update MCS level attribute
    FAPI_ATTR_SET( fapi2::ATTR_TIMING_TCKMIN, l_target_mcs, l_min_cycle_times );

    // Printed decoded info
    FAPI_INF("%s. tCKmin (min cycle time): %d (ps)",
             c_str(i_target_dimm),
             l_min_cycle_times[PORT_NUM][DIMM_NUM] );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decode SDRAM Maximum Cycle Time
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       SPD Byte 19 and 124
///
fapi2::ReturnCode decoder::max_cycle_time(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX_MTB = 19; // min cycle medium timebase (mtb)
    const size_t BYTE_INDEX_FTB = 124; // min cycle fine timebase (ftb)

    const int64_t MIN_CYCLE_TIME_MTB = 1; // from JEDEC
    const int64_t MAX_CYCLE_TIME_MTB = 255; // from JEDEC

    const int64_t MIN_CYCLE_TIME_FTB = -128; // from JEDEC
    const int64_t MAX_CYCLE_TIME_FTB = 127; // from JEDEC

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Byte variables used for decoding
    int64_t l_tCKmax_mtb = 0;
    int64_t l_tCKmax_ftb = 0;

    // Attribute variable
    int64_t l_max_cycle_times[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};
    int64_t l_MTBs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};
    int64_t l_FTBs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX_MTB,
             i_spd_data[BYTE_INDEX_MTB]);

    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX_FTB,
             i_spd_data[BYTE_INDEX_FTB]);

    // Retrieve SDRAM Maximum Cycle Time
    l_tCKmax_mtb = i_spd_data[BYTE_INDEX_MTB];

    FAPI_TRY(mss::check::spd::valid_value_fail(i_target_dimm,
             (l_tCKmax_mtb <= MAX_CYCLE_TIME_MTB) &&
             (l_tCKmax_mtb >= MIN_CYCLE_TIME_MTB),
             BYTE_INDEX_MTB,
             l_tCKmax_mtb,
             "Failed check for tCKmin (min cycle time) in MTB units") );

    // Retrieve Fine Offset for SDRAM Maximum Cycle Time
    // casted int8_t undoes 2's complement on the uint8_t spd data
    l_tCKmax_ftb = int8_t(i_spd_data[BYTE_INDEX_FTB]);

    FAPI_TRY(mss::check::spd::valid_value_fail(i_target_dimm,
             (l_tCKmax_ftb <= MAX_CYCLE_TIME_FTB) &&
             (l_tCKmax_ftb >= MIN_CYCLE_TIME_FTB),
             BYTE_INDEX_FTB,
             l_tCKmax_ftb,
             "Failed check for tCKmin (min cycle time) in FTB units") );

    // Retrieving medium timebase (MTB) multiplier used for timing calculation
    FAPI_TRY( spd_medium_timebase(l_target_mcs, &l_MTBs[0][0]) );
    FAPI_TRY( spd_fine_timebase(l_target_mcs, &l_FTBs[0][0]) );

    // Retrive entire MCS level attribute
    FAPI_TRY(spd_timing_tckmax(l_target_mcs, &l_max_cycle_times[0][0]))

    // Update attribute to decoded byte values
    l_max_cycle_times[PORT_NUM][DIMM_NUM] = calc_timing(l_tCKmax_mtb,
                                            l_tCKmax_ftb,
                                            l_MTBs[PORT_NUM][DIMM_NUM],
                                            l_FTBs[PORT_NUM][DIMM_NUM]);

    // Update MCS level attribute
    FAPI_ATTR_SET( fapi2::ATTR_TIMING_TCKMAX, l_target_mcs, l_max_cycle_times );

    // Printed decoded info
    FAPI_INF("%s. tCKmax (max cycle time): %d (ps)",
             c_str(i_target_dimm),
             l_max_cycle_times[PORT_NUM][DIMM_NUM] );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Decode Minimum CAS Latency Time
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       SPD Byte 24 & 123
///
fapi2::ReturnCode decoder::min_cas_latency_time(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX_MTB = 24; // min cycle medium timebase (mtb)
    const size_t BYTE_INDEX_FTB = 123; // min cycle fine timebase (ftb)

    const int64_t MIN_CYCLE_TIME_MTB = 1; // from JEDEC
    const int64_t MAX_CYCLE_TIME_MTB = 255; // from JEDEC

    const int64_t MIN_CYCLE_TIME_FTB = -128; // from JEDEC
    const int64_t MAX_CYCLE_TIME_FTB = 127; // from JEDEC

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Byte variables used for decoding
    int64_t l_tAAmin_mtb = 0;
    int64_t l_tAAmin_ftb = 0;

    // Attribute variable
    int64_t l_min_cas_latency_times[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};
    int64_t l_MTBs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};
    int64_t l_FTBs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX_MTB,
             i_spd_data[BYTE_INDEX_MTB]);

    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX_FTB,
             i_spd_data[BYTE_INDEX_FTB]);

    // Retrieve SDRAM Minimum CAS Latency Time
    l_tAAmin_mtb = i_spd_data[BYTE_INDEX_MTB];

    FAPI_TRY(mss::check::spd::valid_value_fail(i_target_dimm,
             (l_tAAmin_mtb <= MAX_CYCLE_TIME_MTB) &&
             (l_tAAmin_mtb >= MIN_CYCLE_TIME_MTB),
             BYTE_INDEX_MTB,
             l_tAAmin_mtb,
             "Failed check for min CAS latency time (tAAmin) in MTB units") );

    // Retrieve Fine Offset for Minimum CAS Latency Time
    // casted int8_t undoes 2's complement on the uint8_t spd data
    l_tAAmin_ftb = int8_t(i_spd_data[BYTE_INDEX_FTB]);

    FAPI_TRY(mss::check::spd::valid_value_fail(i_target_dimm,
             (l_tAAmin_ftb <= MAX_CYCLE_TIME_FTB) &&
             (l_tAAmin_ftb >= MIN_CYCLE_TIME_FTB),
             BYTE_INDEX_FTB,
             l_tAAmin_ftb,
             "Failed check for min CAS latency time (tAAmin) in FTB units") );

    // Retrieving medium timebase (MTB) multiplier used for timing calculation
    FAPI_TRY( spd_medium_timebase(l_target_mcs, &l_MTBs[0][0]) );
    FAPI_TRY( spd_fine_timebase(l_target_mcs, &l_FTBs[0][0]) );

    // Retrive entire MCS level attribute
    FAPI_TRY(spd_timing_taamin(l_target_mcs, &l_min_cas_latency_times[0][0]))

    // Update attribute to decoded byte values
    l_min_cas_latency_times[PORT_NUM][DIMM_NUM] = calc_timing(l_tAAmin_mtb,
            l_tAAmin_ftb,
            l_MTBs[PORT_NUM][DIMM_NUM],
            l_FTBs[PORT_NUM][DIMM_NUM]);

    // Update MCS level attribute
    FAPI_ATTR_SET( fapi2::ATTR_TIMING_TAAMIN, l_target_mcs, l_min_cas_latency_times );

    // Printed decoded info
    FAPI_INF("%s. tAAmin (min cycle time): %d (ps)",
             c_str(i_target_dimm),
             l_min_cas_latency_times[PORT_NUM][DIMM_NUM] );

fapi_try_exit:
    return fapi2::current_err;
}

#if 0

///
/// @brief      Decode CAS Latencies Supported
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       SPD Byte 20-23
///
fapi2::ReturnCode decoder::supported_cas_latencies(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t FIRST_BYTE = 20;
    const size_t SEC_BYTE = 21;
    const size_t THIRD_BYTE = 22;
    const size_t FORTH_BYTE = 23;

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Byte variables used for decoding
    uint64_t l_supported_cas_lat = 0;

    // Attribute variables used to set decoded vals
    uint64_t l_supported_CLs[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Buffers used for bit manipulation
    fapi2::buffer<uint8_t> l_first_byte_buff(i_spd_data[FIRST_BYTE]);
    fapi2::buffer<uint8_t> l_second_byte_buff(i_spd_data[SEC_BYTE]);
    fapi2::buffer<uint8_t> l_third_byte_buff(i_spd_data[THIRD_BYTE]);
    fapi2::buffer<uint8_t> l_forth_byte_buff(i_spd_data[FORTH_BYTE]);

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // TODO - update ENUMS to take account to int64_t

    // Combine Bytes 20 - 23 to create bitmap
    l_first_byte_buff.extractToRight<CAS_BYTE_1_START, CAS_BYTE_1_LEN>(l_supported_cas_lat).
    l_second_byte_buff.extractToRight<CAS_BYTE_2_START, CAS_BYTE_2_LEN>(l_supported_cas_lat).
    l_third_byte_buff.extractToRight<CAS_BYTE_3_START, CAS_BYTE_3_LEN>(l_supported_cas_lat).
    l_forth_byte_buff.extractToRight<CAS_BYTE_4_START, CAS_BYTE_4_LEN>(l_supported_cas_lat);

    // Retrive entire MCS level attribute
    FAPI_TRY( cas_latencies_supported(l_target_mcs, &l_supported_CLs[0][0]) );

    // Update attribute to decoded byte values
    l_supported_CLs[PORT_NUM][DIMM_NUM] = l_supported_cas_lat;

    // Update MCS level attribute
    FAPI_ATTR_SET( fapi2::ATTR_SPD_CAS_LATENCIES_SUPPORTED, l_target_mcs, l_supported_CLs );
    // Printed decoded info
    FAPI_INF("%s",
             c_str(i_target_dimm);
             fapi_try_exit:
             return fapi2::current_err;
}



///
/// @brief      Decode Minimum RAS to CAS Delay Time
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       SPD Byte 25
///
fapi2::ReturnCode decoder::min_ras_to_cas_delay_time(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX = 25;

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Attribute variable (rcd = ras to cas delay)
    int64_t l_min_rcd_times[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Retrive entire MCS level attribute
    FAPI_TRY( eff_dram_trcd(l_target_mcs, &l_min_rcd_times[0][0]) );

    // Update attribute to decoded byte values
    l_min_rcd_times[PORT_NUM][DIMM_NUM] = ns_to_ps( int64_t(i_spd_data[BYTE_INDEX]) );

    // Update MCS level attribute
    FAPI_ATTR_SET( fapi2::ATTR_EFF_DRAM_TRCD, l_target_mcs, l_min_rcd_times );
    // Printed decoded info
    FAPI_INF("%s",
             c_str(i_target_dimm);
             fapi_try_exit:
             return fapi2::current_err;
}

///
/// @brief      Decode Minimum Row Precharge Delay Time
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       SPD Byte 26
///
fapi2::ReturnCode decoder::min_row_precharge_delay_time(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX = 26;

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Attribute variable (rp = row to precharge)
    int64_t l_min_rp_times[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Retrive entire MCS level attribute
    FAPI_TRY( eff_dram_trp(l_target_mcs, &l_min_rp_times[0][0]) );

    // Update attribute to decoded byte values
    l_min_rp_times[PORT_NUM][DIMM_NUM] = ns_to_ps( int64_t(i_spd_data[BYTE_INDEX]) );

    // Update MCS level attribute
    FAPI_ATTR_SET( fapi2::ATTR_EFF_DRAM_TRP, l_target_mcs, l_min_rp_times );
    // Printed decoded info
    FAPI_INF("%s",
             c_str(i_target_dimm);
             fapi_try_exit:
             return fapi2::current_err;
}

///
/// @brief      Decode Minimum Active to Precharge Delay Time (tRASmin)
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       Byte 27 Bits 3~0 along with Byte 28 Bits 7~0
///
fapi2::ReturnCode decoder::min_activate_to_precharge_delay_time(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX_MSB = 27; // MSN = most significant byte
    const size_t BYTE_INDEX_LSB = 28; // LSB = least significant byte

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Byte variables used for decoding (tRAS = Active to Precharge Delay Time)
    int64_t l_tRASmin = 0;

    // Attribute variable
    int64_t l_min_ras_times[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Buffers used for bit manipulation
    fapi2::buffer<uint8_t> l_buffer_upper_nibble(i_spd_data[BYTE_INDEX_MSB]);
    fapi2::buffer<uint8_t> l_buffer_lower_byte(i_spd_data[BYTE_INDEX_LSB]);

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // TODO - update ENUMS to take account to int64_t

    // Combining bits to create timing value
    l_buffer_upper_nibble.extractToRight<TRASMIN_MSN_START, TRASMIN_MSN_LEN>(l_tRASmin);
    l_buffer_lower_byte.extractToRight<TRASMIN_LSB_START, TRASMIN_LSB_LEN>(l_tRASmin);

    // Retrive entire MCS level attribute
    FAPI_TRY( eff_dram_tras(l_target_mcs, &l_min_ras_times[0][0]) );

    // Update attribute to decoded byte values (returning picoseconds)
    l_min_ras_times[PORT_NUM][DIMM_NUM] = ns_to_ps(l_tRASmin);

    // Update MCS level attribute
    FAPI_ATTR_SET( fapi2::ATTR_EFF_DRAM_TRAS, l_target_mcs, l_min_ras_times );
    // Printed decoded info
    FAPI_INF("%s",
             c_str(i_target_dimm);
             fapi_try_exit:
             return fapi2::current_err;
}

///
/// @brief      Minimum Active to Active/Refresh Delay Time (tRCmin)
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       SPD Byte Byte 27 Bits 7~4 along with Byte 29 Bits 7~0
///
fapi2::ReturnCode
decoder::min_activate_to_activate_refresh_delay_time(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX_MSN = 27; // MSN = most significant nibble
    const size_t BYTE_INDEX_LSB = 28; // LSB = least significant byte

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Byte variables used for decoding (RC = Activate to Activate/Refresh Delay)
    uint16_t l_tRCmin = 0;

    // Attribute variable
    uint16_t l_min_rc_times[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // TODO - update ENUMS to take account to int64_t

    // Buffers used for bit manipulation
    fapi2::buffer<uint8_t> l_buffer_upper_nibble(i_spd_data[BYTE_INDEX_MSN]);
    fapi2::buffer<uint8_t> l_buffer_lower_byte(i_spd_data[BYTE_INDEX_LSB]);

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Combining bits to create timing value
    l_buffer_upper_nibble.extractToRight<TRCMIN_MSN_START, TRCMIN_MSN_LEN>(l_tRCmin);
    l_buffer_lower_byte.extractToRight<TRCMIN_LSB_START, TRCMIN_LSB_LEN>(l_tRCmin);

    // Retrive entire MCS level attribute
    FAPI_TRY( eff_dram_trc(l_target_mcs, &l_min_rc_times[0][0]) );

    // Update attribute to decoded byte values (returning picoseconds, currently nanoseconds)
    l_min_rc_times[PORT_NUM][DIMM_NUM] = ns_to_ps(l_tRCmin);

    // Update MCS level attribute (returning picoseconds, currently nanoseconds)
    FAPI_ATTR_SET( fapi2::ATTR_EFF_DRAM_TRC, l_target_mcs, l_min_rc_times );
    // Printed decoded info
    FAPI_INF("%s",
             c_str(i_target_dimm);
             fapi_try_exit:
             return fapi2::current_err;
}

///
/// @brief      Minimum Refresh Recovery Delay Time 1 (tRFC1min)
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       SPD Byte Byte 30 (LSB) along with Byte 31 (MSB)
///
fapi2::ReturnCode decoder::min_refresh_recovery_delay_time_1(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX_MSB = 31; // MSN = most significant nibble
    const size_t BYTE_INDEX_LSB = 30; // LSB = least significant byte

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Byte variables used for decoding (RFC1 = Minimum Refresh Recovery Delay Time)
    uint32_t l_tRFC1min = 0;

    // Attribute variable
    uint32_t l_min_rfc1_times[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Buffers used for bit manipulation
    fapi2::buffer<uint8_t> l_buffer_MSB(i_spd_data[BYTE_INDEX_MSB]);
    fapi2::buffer<uint8_t> l_buffer_LSB(i_spd_data[BYTE_INDEX_LSB]);

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Combining bits to create timing value
    l_buffer_MSB.extractToRight<, >();
    l_buffer_LSB.extractToRight<, >();

    // Retrive entire MCS level attribute
    FAPI_TRY( eff_dram_trc(l_target_mcs, &l_min_rfc1_times[0][0]) );

    // Update attribute to decoded byte values (returning picoseconds, currently nanoseconds)
    l_min_rfc1_times[PORT_NUM][DIMM_NUM] = ns_to_ps(l_tRFC1min);

    // Update MCS level attribute (returning picoseconds, currently nanoseconds)
    FAPI_ATTR_SET( fapi2::ATTR_EFF_DRAM_TRFC1, l_target_mcs, l_min_rfc1_times );
    // Printed decoded info
    FAPI_INF("%s",
             c_str(i_target_dimm);
             fapi_try_exit:
             return fapi2::current_err;
}

///
/// @brief      Minimum Refresh Recovery Delay Time 2 (tRFC2min)
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       SPD Byte Byte 32 (LSB) along with Byte 33 (MSB)
///
fapi2::ReturnCode decoder::min_refresh_recovery_delay_time_2(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX_MSB = 33; // MSN = most significant nibble
    const size_t BYTE_INDEX_LSB = 32; // LSB = least significant byte

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Byte variables used for decoding (RFC1 = Minimum Refresh Recovery Delay 2)
    uint32_t l_tRFC2min = 0;

    // Attribute variable
    uint32_t l_min_rfc2_times[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Buffers used for bit manipulation
    fapi2::buffer<uint8_t> l_buffer_MSB(i_spd_data[BYTE_INDEX_MSB]);
    fapi2::buffer<uint8_t> l_buffer_LSB(i_spd_data[BYTE_INDEX_LSB]);

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Combining bits to create timing value
    l_buffer_MSB.extractToRight<, >();
    l_buffer_LSB.extractToRight<, >();

    // Retrive entire MCS level attribute
    FAPI_TRY( eff_dram_trc(l_target_mcs, &l_min_rfc2_times[0][0]) );

    // Update attribute to decoded byte values (returning picoseconds, currently nanoseconds)
    l_min_rfc1_times[PORT_NUM][DIMM_NUM] = ns_to_ps(l_tRFC2min);

    // Update MCS level attribute (returning picoseconds, currently nanoseconds)
    FAPI_ATTR_SET( fapi2::ATTR_EFF_DRAM_TRFC2, l_target_mcs, l_min_rfc2_times );
    // Printed decoded info
    FAPI_INF("%s",
             c_str(i_target_dimm);
             fapi_try_exit:
             return fapi2::current_err;
}

///
/// @brief      Minimum Refresh Recovery Delay Time 4 (tRFC4min)
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       SPD Byte Byte 34 (LSB) along with Byte 5 (MSB)
///
fapi2::ReturnCode decoder::min_refresh_recovery_delay_time_4(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX_MSB = 35; // MSN = most significant nibble
    const size_t BYTE_INDEX_LSB = 34; // LSB = least significant byte

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Byte variables used for decoding (RFC4 = Minimum Refresh Recovery Delay 4)
    uint32_t l_tRFC4min = 0;

    // Attribute variable
    uint32_t l_min_rfc4_times[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Buffers used for bit manipulation
    fapi2::buffer<uint8_t> l_buffer_MSB(i_spd_data[BYTE_INDEX_MSB]);
    fapi2::buffer<uint8_t> l_buffer_LSB(i_spd_data[BYTE_INDEX_LSB]);

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Combining bits to create timing value
    l_buffer_MSB.extractToRight<, >();
    l_buffer_LSB.extractToRight<, >();

    // Retrive entire MCS level attribute
    FAPI_TRY( eff_dram_trc(l_target_mcs, &l_min_rfc4_times[0][0]) );

    // Update attribute to decoded byte values (returning picoseconds, currently nanoseconds)
    l_min_rfc1_times[PORT_NUM][DIMM_NUM] = ns_to_ps(l_tRFC4min);

    // Update MCS level attribute (returning picoseconds, currently nanoseconds)
    FAPI_ATTR_SET( fapi2::ATTR_EFF_DRAM_TRFC2, l_target_mcs, l_min_rfc4_times );
    // Printed decoded info
    FAPI_INF("%s",
             c_str(i_target_dimm);
             fapi_try_exit:
             return fapi2::current_err;
}

///
/// @brief      Minimum Four Activate Window Delay Time (t FAW min)
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       Byte 36 Bits 3 ~ 0 along with Byte 37 Bits 7 ~ 0
///
fapi2::ReturnCode decoder::min_four_activate_window_time(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX_MSN = 36; // MSN = most significant nibble
    const size_t BYTE_INDEX_LSB = 37; // LSB = least significant byte

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Byte variables used for decoding (FAW = Four Activate Window Delay)
    uint16_t l_tFAW = 0;

    // Attribute variable
    uint16_t l_min_faw_times[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // TODO - update ENUMS to take account to int64_t

    // Buffers used for bit manipulation
    fapi2::buffer<uint8_t> l_buffer_upper_nibble(i_spd_data[BYTE_INDEX_MSN]);
    fapi2::buffer<uint8_t> l_buffer_lower_byte(i_spd_data[BYTE_INDEX_LSB]);

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Combining bits to create timing value
    l_buffer_upper_nibble.extractToRight<TRCMIN_MSN_START, TRCMIN_MSN_LEN>(l_tFAW);
    l_buffer_lower_byte.extractToRight<TRCMIN_LSB_START, TRCMIN_LSB_LEN>(l_tFAW);

    // Retrive entire MCS level attribute
    FAPI_TRY( eff_dram_trc(l_target_mcs, &l_min_faw_times[0][0]) );

    // Update attribute to decoded byte values (returning picoseconds, currently nanoseconds)
    l_min_faw_times[PORT_NUM][DIMM_NUM] = ns_to_ps(l_tFAW);

    // Update MCS level attribute (returning picoseconds, currently nanoseconds)
    FAPI_ATTR_SET( fapi2::ATTR_EFF_DRAM_TRC, l_target_mcs, l_min_faw_times );
    // Printed decoded info
    FAPI_INF("%s",
             c_str(i_target_dimm);
             fapi_try_exit:
             return fapi2::current_err;
}

///
/// @brief      Minimum Activate to Activate Delay Time (tRRD_Smin)
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       Byte 38
///
fapi2::ReturnCode
decoder::min_act_to_act_delay_time_diff_bank_group(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX = 38;

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Attribute variable (rrd_s = Activate to Activate Delay)
    int64_t l_min_tRRD_S[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Retrive entire MCS level attribute
    FAPI_TRY( eff_dram_trrd(l_target_mcs, &l_min_tRRD_S[0][0]) );

    // Update attribute to decoded byte values
    l_min_tRRD_S[PORT_NUM][DIMM_NUM] = ns_to_ps( int64_t(i_spd_data[BYTE_INDEX]) );

    // Update MCS level attribute
    FAPI_ATTR_SET( fapi2::ATTR_EFF_DRAM_TRRD_S, l_target_mcs, l_min_tRRD_S );
    // Printed decoded info
    FAPI_INF("%s",
             c_str(i_target_dimm);
             fapi_try_exit:
             return fapi2::current_err;
}

///
/// @brief      Minimum Activate to Activate Delay Time (tRRD_Lmin), samebank group
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       Byte 39
///
fapi2::ReturnCode
decoder::min_act_to_act_delay_time_same_bank_group(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX = 39;

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Attribute variable (rrd_s = Activate to Activate Delay)
    int64_t l_min_tRRD_S[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Retrive entire MCS level attribute
    FAPI_TRY( eff_dram_trrd(l_target_mcs, &l_min_tRRD_S[0][0]) );

    // Update attribute to decoded byte values
    l_min_tRRD_S[PORT_NUM][DIMM_NUM] = ns_to_ps( int64_t(i_spd_data[BYTE_INDEX]) );

    // Update MCS level attribute
    FAPI_ATTR_SET( fapi2::ATTR_EFF_DRAM_TRRD_L, l_target_mcs, l_min_tRRD_S );

    // Printed decoded info
    FAPI_INF("%s",
             c_str(i_target_dimm);
             fapi_try_exit:
             return fapi2::current_err;
}

///
/// @brief      Minimum CAS to CAS Delay Time (tCCD_Lmin), same bank group
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       Byte 40
///
fapi2::ReturnCode decoder::min_cas_to_cas_delay_time(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX = 40;

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Attribute variable (CCD_L = Minimum CAS to CAS Delay Time, same bank group)
    int64_t l_min_tCCD_L[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Retrive entire MCS level attribute
    FAPI_TRY( eff_dram_trrd(l_target_mcs, &l_min_tCCD_L[0][0]) );

    // Update attribute to decoded byte values
    l_min_tCCD_L[PORT_NUM][DIMM_NUM] = ns_to_ps( int64_t(i_spd_data[BYTE_INDEX]) );

    // Update MCS level attribute
    FAPI_ATTR_SET( fapi2::ATTR_EFF_DRAM_TCCD_L, l_target_mcs, l_min_tCCD_L );

    // Printed decoded info
    FAPI_INF("%s",
             c_str(i_target_dimm);
             fapi_try_exit:
             return fapi2::current_err;
}

///
/// @brief      Minimum Write Recovery Time (tWRmin)
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       Byte 41 Bits 3~0, Byte 42 Bits 7~0
///
fapi2::ReturnCode decoder::min_write_recovery_time(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX_MSN = 41; // MSN = most significant nibble
    const size_t BYTE_INDEX_LSB = 42; // LSB = least significant byte

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Byte variables used for decoding (FAW = Four Activate Window Delay)
    uint16_t l_tWRmin = 0;

    // Attribute variable
    int64_t l_min_wr_times[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // TODO - update ENUMS to take account to int64_t

    // Buffers used for bit manipulation
    fapi2::buffer<uint8_t> l_buffer_upper_nibble(i_spd_data[BYTE_INDEX_MSN]);
    fapi2::buffer<uint8_t> l_buffer_lower_byte(i_spd_data[BYTE_INDEX_LSB]);

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Combining bits to create timing value
    l_buffer_upper_nibble.insert<, >(l_tWRmin);
    l_buffer_lower_byte.insert<, >(l_tWRmin);

    // Retrive entire MCS level attribute
    FAPI_TRY( eff_dram_twr(l_target_mcs, &l_min_wr_times[0][0]) );

    // Update attribute to decoded byte values (returning picoseconds, currently nanoseconds)
    l_min_wr_times[PORT_NUM][DIMM_NUM] = ns_to_ps(l_tWRmin);

    // Update MCS level attribute (returning picoseconds, currently nanoseconds)
    FAPI_ATTR_SET( fapi2::ATTR_EFF_DRAM_TWR, l_target_mcs, l_min_wr_times );
    // Printed decoded info
    FAPI_INF("%s",
             c_str(i_target_dimm);
             fapi_try_exit:
             return fapi2::current_err;
}

///
/// @brief      Minimum Write to Read Time (tWTR_Smin), different bank group
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       Byte 43 Bits 3~0, Byte 44 Bits 7~0
///
fapi2::ReturnCode decoder::min_write_to_read_time_diff_bank_group(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX_MSN = 43; // MSN = most significant nibble
    const size_t BYTE_INDEX_LSB = 44; // LSB = least significant byte

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Byte variables used for decoding (WRT = Write to Read Time)
    int64_t l_tWRTmin = 0;

    // Attribute variable
    int64_t l_min_wrt_times[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // TODO - update ENUMS to take account to int64_t

    // Buffers used for bit manipulation
    fapi2::buffer<uint8_t> l_buffer_upper_nibble(i_spd_data[BYTE_INDEX_MSN]);
    fapi2::buffer<uint8_t> l_buffer_lower_byte(i_spd_data[BYTE_INDEX_LSB]);

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Combining bits to create timing value
    l_buffer_upper_nibble.insert<, >(l_tWRTmin);
    l_buffer_lower_byte.insert<, >(l_tWRTmin);

    // Retrive entire MCS level attribute
    FAPI_TRY( eff_dram_twrt(l_target_mcs, &l_min_wrt_times[0][0]) );

    // Update attribute to decoded byte values (returning picoseconds, currently nanoseconds)
    l_min_wrt_times[PORT_NUM][DIMM_NUM] = ns_to_ps(l_tWRTmin);

    // Update MCS level attribute (returning picoseconds, currently nanoseconds)
    FAPI_ATTR_SET( fapi2::ATTR_EFF_DRAM_TWRT, l_target_mcs, l_min_wrt_times );
    // Printed decoded info
    FAPI_INF("%s",
             c_str(i_target_dimm);
             fapi_try_exit:
             return fapi2::current_err;
}

///
/// @brief      Minimum Write to Read Time (tWTR_Lmin), same bank group
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       Byte 43 Bits 7~4, Byte 45 Bits 7~0
///
fapi2::ReturnCode
decoder::min_write_to_read_time_same_bank_group(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX_MSN = 43; // MSN = most significant nibble
    const size_t BYTE_INDEX_LSB = 45; // LSB = least significant byte

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Byte variables used for decoding (WRT = Write to Read Time)
    int64_t l_tWRTmin = 0;

    // Attribute variable
    int64_t l_min_wrt_times[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // TODO - update ENUMS to take account to int64_t

    // Buffers used for bit manipulation
    fapi2::buffer<uint8_t> l_buffer_upper_nibble(i_spd_data[BYTE_INDEX_MSN]);
    fapi2::buffer<uint8_t> l_buffer_lower_byte(i_spd_data[BYTE_INDEX_LSB]);

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Combining bits to create timing value
    l_buffer_upper_nibble.insert<, >(l_tWRTmin);
    l_buffer_lower_byte.insert<, >(l_tWRTmin);

    // Retrive entire MCS level attribute
    FAPI_TRY( eff_dram_twrt(l_target_mcs, &l_min_wrt_times[0][0]) );

    // Update attribute to decoded byte values (returning picoseconds, currently nanoseconds)
    l_min_wrt_times[PORT_NUM][DIMM_NUM] = ns_to_ps(l_tWRTmin);

    // Update MCS level attribute (returning picoseconds, currently nanoseconds)
    FAPI_ATTR_SET( fapi2::ATTR_EFF_DRAM_TWRT, l_target_mcs, l_min_wrt_times );
    // Printed decoded info
    FAPI_INF("%s",
             c_str(i_target_dimm);
             fapi_try_exit:
             return fapi2::current_err;
}

///
/// @brief      Connector to SDRAM Bit Mapping
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       Bytes 60~77
///
fapi2::ReturnCode decoder::connector_to_sdram_bit_mapping(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
// Retrive entire MCS level attribute
// Update attribute to decoded byte values
// Update MCS level attribute
    // Printed decoded info
    FAPI_INF("%s",
             c_str(i_target_dimm);
             fapi_try_exit:
             return fapi2::current_err;
}

///
/// @brief     Fine Offset for Minimum CAS to CAS Delay Time (tCCD_Lmin), same bank group
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       Byte 117
///
fapi2::ReturnCode decoder::offset_for_min_cas_to_cas_delay_time(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX = 117;

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Attribute variable (CCD_L = Minimum CAS to CAS Delay Time, same bank group)
    int64_t l_min_offset_tCCD_L[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Retrive entire MCS level attribute
    FAPI_TRY( eff_dram_trrd(l_target_mcs, &l_min_offset_tCCD_L[0][0]) );

    // Update attribute to decoded byte values
    l_min_offset_tCCD_L[PORT_NUM][DIMM_NUM] = ns_to_ps( int64_t(i_spd_data[BYTE_INDEX]) );

    // Update MCS level attribute
    FAPI_ATTR_SET( fapi2::ATTR_EFF_OFFSET_DRAM_TCCD_L, l_target_mcs, l_min_offset_tCCD_L );
    // Printed decoded info
    FAPI_INF("%s",
             c_str(i_target_dimm);
             fapi_try_exit:
             return fapi2::current_err;
}

// Retrive entire MCS level attribute
// Update attribute to decoded byte values
// Update MCS level attribute

fapi_try_exit:
return fapi2::current_err;
}

///
/// @brief      Fine Offset for Minimum Activate to Activate Delay Time(tRRD_Lmin), same bank group
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       Byte 118
///
fapi2::ReturnCode
decoder::offset_min_act_to_act_delay_time_diff_bank_gp(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX = 118;

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Attribute variable (CCD_L = Minimum CAS to CAS Delay Time, same bank group)
    int64_t l_min_offset_tCCD_L[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Retrive entire MCS level attribute
    FAPI_TRY( eff_dram_trrd(l_target_mcs, &l_min_offset_tCCD_L[0][0]) );

    // Update attribute to decoded byte values
    l_min_offset_tCCD_L[PORT_NUM][DIMM_NUM] = ns_to_ps( int64_t(i_spd_data[BYTE_INDEX]) );

    // Update MCS level attribute
    FAPI_ATTR_SET( fapi2::ATTR_EFF_OFFSET_DRAM_TCCD_L, l_target_mcs, l_min_offset_tCCD_L );
    // Printed decoded info
    FAPI_INF("%s",
             c_str(i_target_dimm);
             fapi_try_exit:
             return fapi2::current_err;

}

///
/// @brief      Fine Offset for Minimum Activate to Activate Delay Time (tRRD_Smin), different bank group
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       Byte 119
///
fapi2::ReturnCode
decoder::offset_min_act_to_act_delay_time_same_bank_gp(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX = 119;

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Attribute variable (CCD_L = Minimum CAS to CAS Delay Time, same bank group)
    int64_t l_min_offset_tCCD_L[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Retrive entire MCS level attribute
    FAPI_TRY( eff_dram_trrd(l_target_mcs, &l_min_offset_tCCD_L[0][0]) );

    // Update attribute to decoded byte values
    l_min_offset_tCCD_L[PORT_NUM][DIMM_NUM] = ns_to_ps( int64_t(i_spd_data[BYTE_INDEX]) );

    // Update MCS level attribute
    FAPI_ATTR_SET( fapi2::ATTR_EFF_OFFSET_DRAM_TCCD_L, l_target_mcs, l_min_offset_tCCD_L );
    // Printed decoded info
    FAPI_INF("%s",
             c_str(i_target_dimm);
             fapi_try_exit:
             return fapi2::current_err;
}

///
/// @brief      Fine Offset for Minimum Active to Active/Refresh Delay Time (tRCmin)
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       Byte 120
///
fapi2::ReturnCode
decoder::offset_for_min_act_to_act_refresh_delay_time(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX = 120;

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Attribute variable (CCD_L = Minimum CAS to CAS Delay Time, same bank group)
    int64_t l_min_offset_tCCD_L[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Retrive entire MCS level attribute
    FAPI_TRY( eff_dram_trrd(l_target_mcs, &l_min_offset_tCCD_L[0][0]) );

    // Update attribute to decoded byte values
    l_min_offset_tCCD_L[PORT_NUM][DIMM_NUM] = ns_to_ps( int64_t(i_spd_data[BYTE_INDEX]) );

    // Update MCS level attribute
    FAPI_ATTR_SET( fapi2::ATTR_EFF_OFFSET_DRAM_TCCD_L, l_target_mcs, l_min_offset_tCCD_L );
    // Printed decoded info
    FAPI_INF("%s",
             c_str(i_target_dimm);
             fapi_try_exit:
             return fapi2::current_err;

// Retrive entire MCS level attribute
// Update attribute to decoded byte values
// Update MCS level attribute

             fapi_try_exit:
             return fapi2::current_err;
}

///
/// @brief      Fine Offset for Minimum Row Precharge Delay Time (tRPmin)
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       Byte 121
///
fapi2::ReturnCode
decoder::offset_for_min_row_precharge_delay_time(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX = 121;

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Attribute variable (CCD_L = Minimum CAS to CAS Delay Time, same bank group)
    int64_t l_min_offset_tCCD_L[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Retrive entire MCS level attribute
    FAPI_TRY( eff_dram_trrd(l_target_mcs, &l_min_offset_tCCD_L[0][0]) );

    // Update attribute to decoded byte values
    l_min_offset_tCCD_L[PORT_NUM][DIMM_NUM] = ns_to_ps( int64_t(i_spd_data[BYTE_INDEX]) );

    // Update MCS level attribute
    FAPI_ATTR_SET( fapi2::ATTR_EFF_OFFSET_DRAM_TCCD_L, l_target_mcs, l_min_offset_tCCD_L );

    // Printed decoded info
    FAPI_INF("%s",
             c_str(i_target_dimm);
             fapi_try_exit:
             return fapi2::current_err;
}


///
/// @brief      Fine Offset for Minimum RAS to CAS Delay Time (tRCDmin)
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       Byte 122
///
fapi2::ReturnCode decoder::offset_for_min_ras_to_cas_delay_time(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX = 122;

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Attribute variable (CCD_L = Minimum CAS to CAS Delay Time, same bank group)
    int64_t l_min_offset_tCCD_L[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Retrive entire MCS level attribute
    FAPI_TRY( eff_dram_trrd(l_target_mcs, &l_min_offset_tCCD_L[0][0]) );

    // Update attribute to decoded byte values
    l_min_offset_tCCD_L[PORT_NUM][DIMM_NUM] = ns_to_ps( int64_t(i_spd_data[BYTE_INDEX]) );

    // Update MCS level attribute
    FAPI_ATTR_SET( fapi2::ATTR_EFF_OFFSET_DRAM_TCCD_L, l_target_mcs, l_min_offset_tCCD_L );

    // Printed decoded info
    FAPI_INF("%s",
             c_str(i_target_dimm);
             fapi_try_exit:
             return fapi2::current_err;
}

///
/// @brief      Fine Offset for Minimum CAS Latency Time (tAAmin)
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       Byte 123
///
fapi2::ReturnCode decoder::offset_for_min_cas_latency_time(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX = 123;

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Attribute variable (CCD_L = Minimum CAS to CAS Delay Time, same bank group)
    int64_t l_min_offset_tCCD_L[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Retrive entire MCS level attribute
    FAPI_TRY( eff_dram_trrd(l_target_mcs, &l_min_offset_tCCD_L[0][0]) );

    // Update attribute to decoded byte values
    l_min_offset_tCCD_L[PORT_NUM][DIMM_NUM] = ns_to_ps( int64_t(i_spd_data[BYTE_INDEX]) );

    // Update MCS level attribute
    FAPI_ATTR_SET( fapi2::ATTR_EFF_OFFSET_DRAM_TCCD_L, l_target_mcs, l_min_offset_tCCD_L );

    // Printed decoded info
    FAPI_INF("%s",
             c_str(i_target_dimm);
             fapi_try_exit:
             return fapi2::current_err;
}

///
/// @brief      Fine Offset for SDRAM Maximum Cycle Time (tCKAVGmax)
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       Byte 124
///
fapi2::ReturnCode decoder::offset_for_max_cycle_time(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX = 124;

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Attribute variable (CCD_L = Minimum CAS to CAS Delay Time, same bank group)
    int64_t l_min_offset_tCCD_L[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Retrive entire MCS level attribute
    FAPI_TRY( eff_dram_trrd(l_target_mcs, &l_min_offset_tCCD_L[0][0]) );

    // Update attribute to decoded byte values
    l_min_offset_tCCD_L[PORT_NUM][DIMM_NUM] = ns_to_ps( int64_t(i_spd_data[BYTE_INDEX]) );

    // Update MCS level attribute
    FAPI_ATTR_SET( fapi2::ATTR_EFF_OFFSET_DRAM_TCCD_L, l_target_mcs, l_min_offset_tCCD_L );

    // Printed decoded info
    FAPI_INF("%s",
             c_str(i_target_dimm);
             fapi_try_exit:
             return fapi2::current_err;
}

///
/// @brief      Fine Offset for SDRAM Minimum Cycle Time (tCKAVGmin)
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       Byte 125
///
fapi2::ReturnCode decoder::offset_for_min_cycle_time(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX = 125;

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Attribute variable (CCD_L = Minimum CAS to CAS Delay Time, same bank group)
    int64_t l_min_offset_tCCD_L[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Retrive entire MCS level attribute
    FAPI_TRY( eff_dram_trrd(l_target_mcs, &l_min_offset_tCCD_L[0][0]) );

    // Update attribute to decoded byte values
    l_min_offset_tCCD_L[PORT_NUM][DIMM_NUM] = ns_to_ps( int64_t(i_spd_data[BYTE_INDEX]) );

    // Update MCS level attribute
    FAPI_ATTR_SET( fapi2::ATTR_EFF_OFFSET_DRAM_TCCD_L, l_target_mcs, l_min_offset_tCCD_L );
    // Printed decoded info
    FAPI_INF("%s",
             c_str(i_target_dimm);

             fapi_try_exit:
             return fapi2::current_err;
}

///
/// @brief      Cyclical Redundancy Code (CRC) for Base Configuration Section
/// @param[in]  const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
///             uint8_t* i_spd_data
/// @return     fapi2::ReturnCode
/// @note       Byte 126 (LSB) along with Byte 127 (MSB)
///
fapi2::ReturnCode decoder::crc_for_base_config_section(const fapi2::Target<TARGET_TYPE_DIMM>& i_target_dimm,
        const uint8_t* i_spd_data)
{
    // Immutable constants
    const size_t BYTE_INDEX_MSB = 127; // MSN = most significant nibble
    const size_t BYTE_INDEX_LSB = 126; // LSB = least significant byte

    // Targets
    const auto l_target_mcs = find_target<TARGET_TYPE_MCS>(i_target_dimm);
    const auto l_target_port = find_target<TARGET_TYPE_MCA>(i_target_dimm);

    // Current index
    const auto PORT_NUM = index(l_target_port);
    const auto DIMM_NUM = index(i_target_dimm);

    // Byte variables used for decoding (WRT = Write to Read Time)
    int64_t l_tWRTmin = 0;

    // Attribute variable
    int64_t l_min_wrt_times[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // TODO - update ENUMS to take account to int64_t

    // Buffers used for bit manipulation
    fapi2::buffer<uint8_t> l_buffer_upper_nibble(i_spd_data[BYTE_INDEX_MSN]);
    fapi2::buffer<uint8_t> l_buffer_lower_byte(i_spd_data[BYTE_INDEX_LSB]);

    // Trace print in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX",
             c_str(i_target_dimm),
             BYTE_INDEX,
             i_spd_data[BYTE_INDEX]);

    // Combining bits to create timing value
    l_buffer_upper_nibble.insert<, >(l_tWRTmin);
    l_buffer_lower_byte.insert<, >(l_tWRTmin);

    // Retrive entire MCS level attribute
    FAPI_TRY( eff_dram_twrt(l_target_mcs, &l_min_wrt_times[0][0]) );

    // Update attribute to decoded byte values (returning picoseconds, currently nanoseconds)
    l_min_wrt_times[PORT_NUM][DIMM_NUM] = ns_to_ps(l_tWRTmin);

    // Update MCS level attribute (returning picoseconds, currently nanoseconds)
    FAPI_ATTR_SET( fapi2::ATTR_EFF_DRAM_TWRT, l_target_mcs, l_min_wrt_times );

    // Printed decoded info
    FAPI_INF("%s",
             c_str(i_target_dimm);
             fapi_try_exit:
             return fapi2::current_err;
}
#endif

}//spd namespace
}// mss namespace
