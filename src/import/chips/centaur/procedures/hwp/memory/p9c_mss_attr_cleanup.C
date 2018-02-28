/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_attr_cleanup.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
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
/// @file p9s_mss_attr_cleanup.C
/// @brief Decode SPD and populate attrs
///
// *HWP HWP Owner: Thomas Sand <trsand@us.ibm.com>
// *HWP HWP Backup: Luke Mulkey <lwmulkey@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
// std lib
#include <map>
#include <vector>

#include <p9c_mss_attr_cleanup.H>

#include <fapi2_spd_access.H>
#include <attribute_ids.H>

#include <lib/shared/dimmConsts.H>

using fapi2::TARGET_TYPE_DIMM;
using fapi2::FAPI2_RC_SUCCESS;

namespace mss
{
namespace common_spd
{

enum factory_byte_offset
{
    REVISION = 1,       ///< SPD Revision
    DRAM_DEVICE_TYPE = 2,   ///< SPD DRAM Interface Type
    ATTR_MODULE_PART_NUMBER_LENGTH_IN_BYTES = 20,
    DDR3_MEMORY_REVISION = 0x0b,
    DDR4_MEMORY_REVISION = 0x0c,
};

}

enum attr_setup_callout
{
    COMMON = 0,
    DDR3 = 3,
    DDR4 = 4,
};

}

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


///
/// @brief Programatic over-rides related to effective config, including data
///        from module VPD
/// @param[in] i_target, the controller (e.g., MCS)
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode
p9c_mss_attr_cleanup(const fapi2::Target<TARGET_TYPE_DIMM>& i_dimm)
{
    char l_target_str_storage[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::toString(i_dimm, l_target_str_storage, fapi2::MAX_ECMD_STRING_LEN);

    FAPI_INF("%s Start", l_target_str_storage );

    fapi2::ReturnCode l_rc;
    size_t l_size = 0;
    uint8_t l_spd_byte1 = 0;

    // Get the size of the factory
    FAPI_TRY( fapi2::getSPD(i_dimm, nullptr, l_size),
              "%s Failed to retrieve SPD blob size", l_target_str_storage );

    // The SPD size varies depending upon the DRAM device type
    // As such, the SPD size is checked within the individual DRAM type functions
    // Here, we just need to be able to get the DRAM device type
    // So, below we check that we can at least get the DRAM device type
    FAPI_ASSERT(l_size >= mss::common_spd::DRAM_DEVICE_TYPE,
                fapi2::CEN_MSS_INVALID_SPD_SIZE()
                .set_TARGET_DIMM(i_dimm)
                .set_SPD_SIZE(l_size)
                .set_EXPECTED_SIZE(mss::common_spd::DRAM_DEVICE_TYPE)
                .set_FUNCTION(mss::COMMON),
                "%s SPD size (%lu) is less than %lu",
                l_target_str_storage, l_size, mss::common_spd::DRAM_DEVICE_TYPE);

    FAPI_INF("%s Get SPD Data size 0x%02X ", l_target_str_storage, l_size);
    {
        // "Container" for SPD data
        std::vector<uint8_t> l_spd(l_size);
        // Retrieve SPD data
        FAPI_TRY( fapi2::getSPD(i_dimm, l_spd.data(), l_size),
                  "%s Failed to retrieve SPD data", l_target_str_storage );
        FAPI_INF("%s Get SPD Data byte 0 0x%02X ", l_target_str_storage, l_spd[0]);


        // Brute force pull the data from the SPD and set it in
        // REVISION = 1
        l_spd_byte1 = l_spd[mss::common_spd::REVISION];
        FAPI_INF("%s: ATTR_CEN_SPD_REVISION 0x%02X ", l_target_str_storage, l_spd_byte1);

        // DRAM_DEVICE_TYPE
        l_spd_byte1 = l_spd[mss::common_spd::DRAM_DEVICE_TYPE];

        if(l_spd_byte1 == mss::common_spd::DDR4_MEMORY_REVISION)
        {

            FAPI_TRY(mss::ddr4::set_spd_attributes(i_dimm, l_spd), "%s Failed to decode DDR4 SPD", l_target_str_storage);
        }
        else if(l_spd_byte1 == mss::common_spd::DDR3_MEMORY_REVISION)
        {
            FAPI_INF("%s DDR3 DRAM module type detected (0x%02X). Starting the decode.", l_target_str_storage, l_spd_byte1);
            FAPI_TRY(mss::ddr3::set_spd_attributes(i_dimm, l_spd), "%s Failed to decode DDR3 SPD", l_target_str_storage);
        }
        else
        {
            // Unknown DRAM type - exit out
            FAPI_ASSERT(false,
                        fapi2::CEN_MSS_VOLT_UNRECOGNIZED_DRAM_DEVICE_TYPE()
                        .set_DIMM_TARGET(i_dimm)
                        .set_DEVICE_TYPE(l_spd_byte1),
                        "%s Unknown DRAM module type detected (0x%02X), skipping SPD collection.  Contact your IBM memory or FW representative.",
                        l_target_str_storage, l_spd_byte1);
        }
    }
fapi_try_exit:
    FAPI_INF("%s End", l_target_str_storage );
    return fapi2::current_err;
}

namespace mss
{
namespace ddr4
{

enum factory_byte_offset
{
    MODULE_TYPE = 3,        ///< SPD DIMM Type
    SDRAM_DENSITY = 4,      ///< SPD SDRAM Density
    SDRAM_ADDRESSING = 5,   ///< SPD SDRAM Addressing
    SDRAM_PACKING_TYPE = 6, ///< SPD SDRAM Addressing
    SDRAM_OPTIONAL_FEATURES = 7,///< SPD SDRAM Optional Features
    SDRAM_THERMAL_OPTIONS = 8,  ///< SPD SDRAM Thermal and Refresh Options
    SDRAM_OTHER_OPT_FEATURES = 9, ///<
    SDRAM_SEC_PACKAGE_FEAT = 10, ///<
    MODULE_NOMINAL_VOLTAGE = 11, ///
    MODULE_ORGANIZATION = 12,   ///<
    MODULE_MEMORY_BUS_WIDTH = 13,
    MODULE_THERMAL_SENSOR = 14,

    TIMEBASE = 17,
    TCKMIN = 18,
    TCKMAX_DDR4 = 19,
    CAS_LATENCIES_SUPPORTED_BYTE1 = 20,
    CAS_LATENCIES_SUPPORTED_BYTE2 = 21,
    CAS_LATENCIES_SUPPORTED_BYTE3 = 23,
    CAS_LATENCIES_SUPPORTED_BYTE4 = 23,
    TAAMIN = 24,
    TRCDMIN = 25,
    TRPMIN = 26,
    TRAS_TRCMIN_HIGH = 27,
    TRASMIN_LOW = 28,
    TRCMIN_LOW = 29,
    TRFC1MIN_DDR4_LOW = 30,
    TRFC1MIN_DDR4_HIGH = 31,
    TRFC2MIN_DDR4_LOW = 32,
    TRFC2MIN_DDR4_HIGH = 33,
    TRFC4MIN_DDR4_LOW = 34,
    TRFC4MIN_DDR4_HIGH = 35,
    TFAWMIN_HIGH = 36,
    TFAWMIN_LOW = 37,
    TRRDSMIN_DDR4 = 38,
    TRRDLMIN_DDR4 = 39,
    TCCDLMIN_DDR4 = 40,

    FINE_OFFSET_TCCDLMIN_DDR4 = 117,
    FINE_OFFSET_TRRDLMIN_DDR4 = 118,
    FINE_OFFSET_TRRDSMIN_DDR4 = 119,
    FINE_OFFSET_TRCMIN = 120,
    FINE_OFFSET_TRPMIN = 121,
    FINE_OFFSET_TRCDMIN = 122,
    FINE_OFFSET_TAAMIN =  123,
    FINE_OFFSET_TCKMAX_DDR4 = 124,
    FINE_OFFSET_TCKMIN = 125,
    CRC_BASE_CONFIG_DDR4_LOW = 126,
    CRC_BASE_CONFIG_DDR4_HIGH = 127,
    MODULE_SPECIFIC_SECTION = 128,

    ADDR_MAP_REG_TO_DRAM = 136, // and 137

    MODULE_ID_MODULE_MANUFACTURERS_JEDEC_ID_CODE_LOW = 320,
    MODULE_ID_MODULE_MANUFACTURERS_JEDEC_ID_CODE_HIGH = 321,
    MODULE_ID_MODULE_MANUFACTURING_LOCATION = 322,
    MODULE_ID_MODULE_MANUFACTURING_DATE_YEAR = 323,
    MODULE_ID_MODULE_MANUFACTURING_DATE_WEEK = 324,
    MODULE_ID_MODULE_SERIAL_NUMBER_BYTE1 = 325,
    MODULE_ID_MODULE_SERIAL_NUMBER_BYTE2 = 326,
    MODULE_ID_MODULE_SERIAL_NUMBER_BYTE3 = 327,
    MODULE_ID_MODULE_SERIAL_NUMBER_BYTE4 = 328,
    MODULE_PART_NUMBER = 329,    // 329-348
    MODULE_PART_NUMBER_LENGTH_IN_BYTES = 20,

    MODULE_REVISION_CODE = 349,
    DRAM_MANUFACTURER_JEDEC_ID_CODE_LSB = 350,
    DRAM_MANUFACTURER_JEDEC_ID_CODE_MSB = 351,
    DRAM_STEPPING_DDR4 = 352,

    CRC_MNFG_SEC_DDR4_LSB = 382,
    CRC_MNFG_SEC_DDR4_MSB = 383,
    SPD_SIZE = 512,
};

///
/// @brief Cleans up DDR4 SPD information
/// @param[in] i_target, the dimm on which to opearte
/// @param[in] i_spd, the SPD on which to operate
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode set_spd_attributes( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
                                      const std::vector<uint8_t>& i_spd )
{
    char l_target_str_storage[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::toString(i_dimm, l_target_str_storage, fapi2::MAX_ECMD_STRING_LEN);

    uint8_t l_spd_byte1 = 0;
    uint8_t l_spd_byte2 = 0;
    uint8_t l_spd_byte3 = 0;
    uint8_t l_spd_byte4 = 0;
    uint8_t l_work_byte = 0;
    uint8_t l_work2_byte = 0;
    uint8_t l_module_pn[MODULE_PART_NUMBER_LENGTH_IN_BYTES] = {0};
    uint32_t l_work_word = 0;
    // DQ SPD Attribute
    uint8_t l_dqData[DIMM_DQ_SPD_DATA_SIZE] = {0};

    // Checks that the DRAM size is the expected DDR4 SPD size
    FAPI_ASSERT(i_spd.size() == SPD_SIZE,
                fapi2::CEN_MSS_INVALID_SPD_SIZE()
                .set_TARGET_DIMM(i_dimm)
                .set_SPD_SIZE(i_spd.size())
                .set_EXPECTED_SIZE(SPD_SIZE)
                .set_FUNCTION(mss::DDR4),
                "%s DDR4 SPD size (%lu) does not equal expected size of %lu",
                l_target_str_storage, i_spd.size(), SPD_SIZE);

    l_spd_byte1 = i_spd[mss::common_spd::DRAM_DEVICE_TYPE];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_DRAM_DEVICE_TYPE, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_DRAM_DEVICE_TYPE", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_DRAM_DEVICE_TYPE 0x%02X ", l_target_str_storage, l_spd_byte1);

    // MODULE_TYPE
    l_spd_byte1 = i_spd[MODULE_TYPE];
    l_work_byte = l_spd_byte1 & 0xF;  // bits 3-0
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_MODULE_TYPE, i_dimm, l_work_byte),
              "%s Failed to set ATTR_CEN_SPD_MODULE_TYPE", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_MODULE_TYPE 0x%02X ", l_target_str_storage, l_work_byte);
    l_work_byte = (l_spd_byte1 & 0x80) >> 7;  // bit 7
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_CUSTOM, i_dimm, l_work_byte),
              "%s Failed to set ATTR_CEN_SPD_CUSTOM", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_CUSTOM 0x%02X ", l_target_str_storage, l_work_byte);

    // SDRAM_DENSITY = 4
    l_spd_byte1 = i_spd[SDRAM_DENSITY];
    l_work_byte = l_spd_byte1 & 0xF;  // bits 3-0
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_SDRAM_DENSITY, i_dimm, l_work_byte),
              "%s Failed to set ATTR_CEN_SPD_SDRAM_DENSITY", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_SDRAM_DENSITY 0x%02X ", l_target_str_storage, l_work_byte);
    l_work_byte = (l_spd_byte1 & 0x30) >> 4;  // bits 5-4
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_SDRAM_BANKS, i_dimm, l_work_byte),
              "%s Failed to set ATTR_CEN_SPD_SDRAM_BANKS", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_SDRAM_BANKS 0x%02X ", l_target_str_storage, l_work_byte);

    // SDRAM_ADDRESSING = 5
    l_spd_byte1 = i_spd[SDRAM_ADDRESSING];
    l_work_byte = l_spd_byte1 & 0x7;  // bits 2-0
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_SDRAM_COLUMNS, i_dimm, l_work_byte),
              "%s Failed to set ATTR_CEN_SPD_SDRAM_COLUMNS", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_SDRAM_COLUMNS 0x%02X ", l_target_str_storage, l_work_byte);
    l_work_byte = (l_spd_byte1 & 0x38) >> 3;  // bits 5-3
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_SDRAM_ROWS, i_dimm, l_work_byte),
              "%s Failed to set ATTR_CEN_SPD_SDRAM_ROWS", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_SDRAM_ROWS 0x%02X ", l_target_str_storage, l_work_byte);

    // SDRAM_PACKING_TYPE = 6
    l_spd_byte1 = i_spd[SDRAM_PACKING_TYPE];
    l_work_byte = (l_spd_byte1 & 0x80) >> 7;  // bit 7
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_SDRAM_DEVICE_TYPE, i_dimm, l_work_byte),
              "%s Failed to set ATTR_CEN_SPD_SDRAM_DEVICE_TYPE", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_SDRAM_DEVICE_TYPE 0x%02X ", l_target_str_storage, l_work_byte);
    l_work_byte = (l_spd_byte1 & 0x70) >> 4;  // bits 6-4
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_SDRAM_DIE_COUNT, i_dimm, l_work_byte),
              "%s Failed to set ATTR_CEN_SPD_SDRAM_DIE_COUNT", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_SDRAM_DIE_COUNT 0x%02X ", l_target_str_storage, l_work_byte);
    l_work_byte = l_spd_byte1 & 0x03;  // bits 1-0
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_SDRAM_DEVICE_TYPE_SIGNAL_LOADING, i_dimm, l_work_byte),
              "%s Failed to set ATTR_CEN_SPD_SDRAM_DEVICE_TYPE_SIGNAL_LOADING", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_SDRAM_DEVICE_TYPE_SIGNAL_LOADING 0x%02X ", l_target_str_storage, l_work_byte);

    // SDRAM_OPTIONAL_FEATURES = 7
    l_spd_byte1 = i_spd[SDRAM_OPTIONAL_FEATURES];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_SDRAM_OPTIONAL_FEATURES, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_SDRAM_OPTIONAL_FEATURES", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_SDRAM_OPTIONAL_FEATURES 0x%02X ", l_target_str_storage, l_spd_byte1);

    // SDRAM_THERMAL_OPTIONS = 8
    l_spd_byte1 = i_spd[SDRAM_THERMAL_OPTIONS];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_SDRAM_THERMAL_AND_REFRESH_OPTIONS, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_SDRAM_THERMAL_AND_REFRESH_OPTIONS", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_SDRAM_THERMAL_AND_REFRESH_OPTIONS 0x%02X ", l_target_str_storage, l_spd_byte1);

    // MODULE_NOMINAL_VOLTAGE = 11
    l_spd_byte1 = i_spd[MODULE_NOMINAL_VOLTAGE];
    l_work_byte = l_spd_byte1 & 0x3;  // bits 1-0

    if (1 == l_work_byte)
    {
        l_work2_byte = fapi2::ENUM_ATTR_CEN_SPD_MODULE_NOMINAL_VOLTAGE_OP1_2V;
    }
    else if (2 == l_work_byte)
    {
        l_work2_byte =  fapi2::ENUM_ATTR_CEN_SPD_MODULE_NOMINAL_VOLTAGE_END1_2V;
    }
    else if (3 == l_work_byte)
    {
        l_work2_byte =  fapi2::ENUM_ATTR_CEN_SPD_MODULE_NOMINAL_VOLTAGE_END1_2V |
                        fapi2::ENUM_ATTR_CEN_SPD_MODULE_NOMINAL_VOLTAGE_OP1_2V;
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_MODULE_NOMINAL_VOLTAGE, i_dimm, l_work2_byte),
              "%s Failed to set ATTR_CEN_SPD_MODULE_NOMINAL_VOLTAGE", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_MODULE_NOMINAL_VOLTAGE 0x%02X ", l_target_str_storage, l_work2_byte);

    // MODULE_ORGANIZATION = 12
    l_spd_byte1 = i_spd[MODULE_ORGANIZATION];
    l_work_byte = l_spd_byte1 & 0x7;  // bits 2-0
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_DRAM_WIDTH, i_dimm, l_work_byte),
              "%s Failed to set ATTR_CEN_SPD_DRAM_WIDTH", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_DRAM_WIDTH 0x%02X ", l_target_str_storage, l_work_byte);
    l_work_byte = (l_spd_byte1 & 0x38) >> 3;  // bits 5-3
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_NUM_RANKS, i_dimm, l_work_byte),
              "%s Failed to set ATTR_CEN_SPD_NUM_RANKS", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_NUM_RANKS 0x%02X ", l_target_str_storage, l_work_byte);

    // MODULE_MEMORY_BUS_WIDTH = 13
    l_spd_byte1 = i_spd[MODULE_MEMORY_BUS_WIDTH];
    l_work_byte = l_spd_byte1 & 0x1F;  // bits 4-0
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_MODULE_MEMORY_BUS_WIDTH, i_dimm, l_work_byte),
              "%s Failed to set ATTR_CEN_SPD_MODULE_MEMORY_BUS_WIDTH", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_MODULE_MEMORY_BUS_WIDTH 0x%02X ", l_target_str_storage, l_work_byte);

    // MODULE_THERMAL_SENSOR = 14
    l_spd_byte1 = i_spd[MODULE_THERMAL_SENSOR];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_MODULE_THERMAL_SENSOR, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_MODULE_THERMAL_SENSOR", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_MODULE_THERMAL_SENSOR 0x%02X ", l_target_str_storage, l_spd_byte1);

    // TIMEBASE = 17,
    l_spd_byte1 = i_spd[MODULE_THERMAL_SENSOR];
    l_work_byte = (l_spd_byte1 & 0x0C) >> 2;  // bits 3-2
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TIMEBASE_MTB_DDR4, i_dimm, l_work_byte),
              "%s Failed to set ATTR_CEN_SPD_TIMEBASE_MTB_DDR4", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_TIMEBASE_MTB_DDR4 0x%02X ", l_target_str_storage, l_work_byte);
    l_work_byte = l_spd_byte1 & 0x3;  // bits 1-0
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TIMEBASE_FTB_DDR4, i_dimm, l_work_byte),
              "%s Failed to set ATTR_CEN_SPD_TIMEBASE_FTB_DDR4", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_TIMEBASE_FTB_DDR4 0x%02X ", l_target_str_storage, l_work_byte);

    // TCKMIN = 18
    l_spd_byte1 = i_spd[TCKMIN];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TCKMIN, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_TCKMIN", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_TCKMIN 0x%02X ", l_target_str_storage, l_spd_byte1);

    // TCKMAX_DDR4 = 19
    l_spd_byte1 = i_spd[TCKMAX_DDR4];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TCKMAX_DDR4, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_TCKMAX_DDR4", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_TCKMAX_DDR4 0x%02X ", l_target_str_storage, l_spd_byte1);

    // CAS_LATENCIES_SUPPORTED = Bytes 20-23
    l_spd_byte1 = i_spd[CAS_LATENCIES_SUPPORTED_BYTE1];
    l_spd_byte2 = i_spd[CAS_LATENCIES_SUPPORTED_BYTE2];
    l_spd_byte3 = i_spd[CAS_LATENCIES_SUPPORTED_BYTE3];
    l_spd_byte4 = i_spd[CAS_LATENCIES_SUPPORTED_BYTE4];
    l_work_word = (l_spd_byte4 << 24) | (l_spd_byte3 << 16) | (l_spd_byte2 << 8) | l_spd_byte1;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_CAS_LATENCIES_SUPPORTED, i_dimm, l_work_word),
              "%s Failed to set ATTR_CEN_SPD_CAS_LATENCIES_SUPPORTED", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_CAS_LATENCIES_SUPPORTED 0x%02X ", l_target_str_storage, l_work_word);

    // TAAMIN = 24
    l_spd_byte1 = i_spd[TAAMIN];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TAAMIN, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_TAAMIN", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_TAAMIN 0x%02X ", l_target_str_storage, l_spd_byte1);

    // TRCDMIN = 25
    l_spd_byte1 = i_spd[TRCDMIN];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TRCDMIN, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_TRCDMIN", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_TRCDMIN 0x%02X ", l_target_str_storage, l_spd_byte1);

    // TRPMIN = 26
    l_spd_byte1 = i_spd[TRPMIN];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TRPMIN, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_TRPMIN", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_TRPMIN 0x%02X ", l_target_str_storage, l_spd_byte1);

    // TRAS_TRCMIN_HIGH = 27,
    // TRASMIN_LOW = 28
    l_spd_byte1 = i_spd[TRAS_TRCMIN_HIGH];
    l_spd_byte2 = i_spd[TRASMIN_LOW];
    l_work_word = ((l_spd_byte1 & 0xF0) << 4) | l_spd_byte2;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TRASMIN, i_dimm, l_work_word),
              "%s Failed to set ATTR_CEN_SPD_TRASMIN", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_TRASMIN 0x%02X ", l_target_str_storage, l_work_word);

    // TRCMIN_LOW = 29,
    l_spd_byte2 = i_spd[TRCMIN_LOW];
    l_work_word = ((l_spd_byte1 & 0xF) << 8) | l_spd_byte2;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TRCMIN, i_dimm, l_work_word),
              "%s Failed to set ATTR_CEN_SPD_TRCMIN", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_TRCMIN 0x%02X ", l_target_str_storage, l_work_word);

    // TRFC1MIN_DDR4_LOW = 30
    // TRFC1MIN_DDR4_HIGH = 31
    l_spd_byte1 = i_spd[TRFC1MIN_DDR4_HIGH];
    l_spd_byte2 = i_spd[TRFC1MIN_DDR4_LOW];
    l_work_word = (l_spd_byte1 << 8) | l_spd_byte2;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TRFC1MIN_DDR4, i_dimm, l_work_word),
              "%s Failed to set ATTR_CEN_SPD_TRFC1MIN_DDR4", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_TRFC1MIN_DDR4 0x%02X ", l_target_str_storage, l_work_word);

    // TRFC2MIN_DDR4_LOW = 32,
    // TRFC2MIN_DDR4_HIGH = 33,
    l_spd_byte1 = i_spd[TRFC2MIN_DDR4_HIGH];
    l_spd_byte2 = i_spd[TRFC2MIN_DDR4_LOW];
    l_work_word = (l_spd_byte1 << 8) | l_spd_byte2;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TRFC2MIN_DDR4, i_dimm, l_work_word),
              "%s Failed to set ATTR_CEN_SPD_TRFC2MIN_DDR4", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_TRFC2MIN_DDR4 0x%02X ", l_target_str_storage, l_work_word);

    // TRFC4MIN_DDR4_LOW = 34,
    // TRFC4MIN_DDR4_HIGH = 35,
    l_spd_byte1 = i_spd[TRFC4MIN_DDR4_HIGH];
    l_spd_byte2 = i_spd[TRFC4MIN_DDR4_LOW];
    l_work_word = (l_spd_byte1 << 8) | l_spd_byte2;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TRFC4MIN_DDR4, i_dimm, l_work_word),
              "%s Failed to set ATTR_CEN_SPD_TRFC4MIN_DDR4", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_TRFC4MIN_DDR4 0x%02X ", l_target_str_storage, l_work_word);

    // TFAWMIN_HIGH = 36
    // TFAWMIN_LOW = 37,
    l_spd_byte1 = i_spd[TFAWMIN_HIGH];
    l_spd_byte2 = i_spd[TFAWMIN_LOW];
    l_work_word = (l_spd_byte1 << 8) | l_spd_byte2;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TFAWMIN, i_dimm, l_work_word),
              "%s Failed to set ATTR_CEN_SPD_TFAWMIN", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_TFAWMIN 0x%02X ", l_target_str_storage, l_work_word);

    // TRRDSMIN_DDR4 = 38
    l_spd_byte1 = i_spd[TRRDSMIN_DDR4];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TRRDSMIN_DDR4, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_TRRDSMIN_DDR4", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_TRRDSMIN_DDR4 0x%02X ", l_target_str_storage, l_spd_byte1);

    // TRRDLMIN_DDR4 = 39
    l_spd_byte1 = i_spd[TRRDLMIN_DDR4];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TRRDLMIN_DDR4, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_TRRDLMIN_DDR4", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_TRRDLMIN_DDR4 0x%02X ", l_target_str_storage, l_spd_byte1);

    // TCCDLMIN_DDR4 = 40,ATTR_CEN_SPD_TCCDLMIN_DDR4
    l_spd_byte1 = i_spd[TCCDLMIN_DDR4];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TCCDLMIN_DDR4, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_TCCDLMIN_DDR4", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_TCCDLMIN_DDR4 0x%02X ", l_target_str_storage, l_spd_byte1);

    // FINE_OFFSET_TRCMIN = 120
    l_spd_byte1 = i_spd[FINE_OFFSET_TRCMIN];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_FINE_OFFSET_TRCMIN, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_FINE_OFFSET_TRCMIN", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_FINE_OFFSET_TRCMIN 0x%02X ", l_target_str_storage, l_spd_byte1);

    // FINE_OFFSET_TRPMIN = 121
    l_spd_byte1 = i_spd[FINE_OFFSET_TRPMIN];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_FINE_OFFSET_TRPMIN, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_FINE_OFFSET_TRPMIN", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_FINE_OFFSET_TRPMIN 0x%02X ", l_target_str_storage, l_spd_byte1);

    // FINE_OFFSET_TRCDMIN = 122
    l_spd_byte1 = i_spd[FINE_OFFSET_TRCDMIN];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_FINE_OFFSET_TRCDMIN, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_FINE_OFFSET_TRCDMIN", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_FINE_OFFSET_TRCDMIN 0x%02X ", l_target_str_storage, l_spd_byte1);

    // FINE_OFFSET_TAAMIN =  123
    l_spd_byte1 = i_spd[FINE_OFFSET_TAAMIN];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_FINE_OFFSET_TAAMIN, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_FINE_OFFSET_TAAMIN", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_FINE_OFFSET_TAAMIN 0x%02X ", l_target_str_storage, l_spd_byte1);

    // FINE_OFFSET_TCKMAX_DDR4 = 124
    l_spd_byte1 = i_spd[FINE_OFFSET_TCKMAX_DDR4];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_FINE_OFFSET_TCKMAX_DDR4, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_FINE_OFFSET_TCKMAX_DDR4", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_FINE_OFFSET_TCKMAX_DDR4 0x%02X ", l_target_str_storage, l_spd_byte1);

    // FINE_OFFSET_TCKMIN = 125
    l_spd_byte1 = i_spd[FINE_OFFSET_TCKMIN];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_FINE_OFFSET_TCKMIN, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_FINE_OFFSET_TCKMIN", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_FINE_OFFSET_TCKMIN 0x%02X ", l_target_str_storage, l_spd_byte1);

    //ADDR_MAP_REG_TO_DRAM = 136
    l_spd_byte1 = i_spd[ADDR_MAP_REG_TO_DRAM];
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_ADDR_MAP_REG_TO_DRAM, i_dimm, l_spd_byte1),
             "%s Failed to set ATTR_CEN_SPD_ADDR_MAP_REG_TO_DRAM", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_ADDR_MAP_REG_TO_DRAM 0x%02X ", l_target_str_storage, l_spd_byte1);

    //MODULE_ID_MODULE_MANUFACTURERS_JEDEC_ID_CODE_LOW = 320
    //MODULE_ID_MODULE_MANUFACTURERS_JEDEC_ID_CODE_HIGH = 321
    l_spd_byte1 = i_spd[MODULE_ID_MODULE_MANUFACTURERS_JEDEC_ID_CODE_HIGH];
    l_spd_byte2 = i_spd[MODULE_ID_MODULE_MANUFACTURERS_JEDEC_ID_CODE_LOW];
    l_work_word = (l_spd_byte1 << 8) | l_spd_byte2;
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_MODULE_ID_MODULE_MANUFACTURERS_JEDEC_ID_CODE, i_dimm, l_work_word),
             "%s Failed to set ATTR_CEN_SPD_MODULE_ID_MODULE_MANUFACTURERS_JEDEC_ID_CODE", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_MODULE_ID_MODULE_MANUFACTURERS_JEDEC_ID_CODE 0x%02X ", l_target_str_storage, l_spd_byte1);

    //MODULE_ID_MODULE_MANUFACTURING_LOCATION = 322
    l_spd_byte1 = i_spd[MODULE_ID_MODULE_MANUFACTURING_LOCATION];
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_MODULE_ID_MODULE_MANUFACTURING_LOCATION, i_dimm, l_spd_byte1),
             "%s Failed to set ATTR_CEN_SPD_MODULE_ID_MODULE_MANUFACTURING_LOCATION", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_MODULE_ID_MODULE_MANUFACTURING_LOCATION 0x%02X ", l_target_str_storage, l_spd_byte1);

    //MODULE_ID_MODULE_MANUFACTURING_DATE_YEAR = 323
    //MODULE_ID_MODULE_MANUFACTURING_DATE_WEEK = 324 (LSB)
    l_spd_byte1 = i_spd[MODULE_ID_MODULE_MANUFACTURING_DATE_YEAR];
    l_spd_byte2 = i_spd[MODULE_ID_MODULE_MANUFACTURING_DATE_WEEK];
    l_work_word = (l_spd_byte1 << 8) | l_spd_byte2;
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_MODULE_ID_MODULE_MANUFACTURING_DATE, i_dimm, l_work_word),
             "%s Failed to set ATTR_CEN_SPD_MODULE_ID_MODULE_MANUFACTURING_DATE", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_MODULE_ID_MODULE_MANUFACTURING_DATE 0x%02X ", l_target_str_storage, l_work_word);

    //MODULE_ID_MODULE_SERIAL_NUMBER_BYTE1 = 325 (LSB)
    //MODULE_ID_MODULE_SERIAL_NUMBER_BYTE2 = 326
    //MODULE_ID_MODULE_SERIAL_NUMBER_BYTE3 = 327
    //MODULE_ID_MODULE_SERIAL_NUMBER_BYTE4 = 328
    l_spd_byte1 = i_spd[MODULE_ID_MODULE_SERIAL_NUMBER_BYTE1];
    l_spd_byte2 = i_spd[MODULE_ID_MODULE_SERIAL_NUMBER_BYTE2];
    l_spd_byte3 = i_spd[MODULE_ID_MODULE_SERIAL_NUMBER_BYTE3];
    l_spd_byte4 = i_spd[MODULE_ID_MODULE_SERIAL_NUMBER_BYTE4];
    l_work_word = (l_spd_byte4 << 24) | (l_spd_byte3 << 16) | (l_spd_byte2 << 8) | l_spd_byte1;
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_MODULE_ID_MODULE_SERIAL_NUMBER, i_dimm, l_work_word),
             "%s Failed to set ATTR_CEN_SPD_MODULE_ID_MODULE_SERIAL_NUMBER", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_MODULE_ID_MODULE_SERIAL_NUMBER 0x%02X ", l_target_str_storage, l_work_word);

    //MODULE_PART_NUMBER = 329:348
    for (uint16_t l_byte = 0; l_byte < MODULE_PART_NUMBER_LENGTH_IN_BYTES; l_byte++)
    {
        l_module_pn[l_byte] = i_spd[l_byte + MODULE_PART_NUMBER];
    }

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_MODULE_PART_NUMBER, i_dimm, l_module_pn),
             "%s Failed to set ATTR_CEN_SPD_MODULE_PART_NUMBER", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_MODULE_PART_NUMBER 0x%02X ", l_target_str_storage, l_module_pn[0]);


    //MODULE_REVISION_CODE = 349
    l_spd_byte1 = i_spd[MODULE_REVISION_CODE];
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_MODULE_REVISION_CODE_DDR4, i_dimm, l_spd_byte1),
             "%s Failed to set ATTR_CEN_SPD_MODULE_REVISION_CODE_DDR4", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_MODULE_REVISION_CODE_DDR4 0x%02X ", l_target_str_storage, l_spd_byte1);


    //DRAM_MANUFACTURER_JEDEC_ID_CODE_LSB = 350
    //DRAM_MANUFACTURER_JEDEC_ID_CODE_MSB = 351
    l_spd_byte1 = i_spd[DRAM_MANUFACTURER_JEDEC_ID_CODE_LSB];
    l_spd_byte2 = i_spd[DRAM_MANUFACTURER_JEDEC_ID_CODE_MSB];
    l_work_word = (l_spd_byte2 << 8) | l_spd_byte1;
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_DRAM_MANUFACTURER_JEDEC_ID_CODE, i_dimm, l_work_word),
             "%s Failed to set ATTR_CEN_SPD_DRAM_MANUFACTURER_JEDEC_ID_CODE", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_DRAM_MANUFACTURER_JEDEC_ID_CODE 0x%02X ", l_target_str_storage, l_work_word);

    //DRAM_STEPPING_DDR4 = 352
    l_spd_byte1 = i_spd[DRAM_STEPPING_DDR4];
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_DRAM_STEPPING_DDR4, i_dimm, l_spd_byte1),
             "%s Failed to set ATTR_CEN_SPD_DRAM_STEPPING_DDR4", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_DRAM_STEPPING_DDR4 0x%02X ", l_target_str_storage, l_spd_byte1);

    //CRC_MNFG_SEC_DDR4_LSB = 382
    //CRC_MNFG_SEC_DDR4_MSB = 383
    l_spd_byte1 = i_spd[CRC_MNFG_SEC_DDR4_LSB];
    l_spd_byte2 = i_spd[CRC_MNFG_SEC_DDR4_MSB];
    l_work_word = (l_spd_byte2 << 8) | l_spd_byte1;
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_CRC_MNFG_SEC_DDR4, i_dimm, l_work_word),
             "%s Failed to set ATTR_CEN_SPD_CRC_MNFG_SEC_DDR4", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_CRC_MNFG_SEC_DDR4 0x%02X ", l_target_str_storage, l_work_word);

    // Reset ATTR_CEN_SPD_BAD_DQ_DATA
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_BAD_DQ_DATA, i_dimm, l_dqData),
              "%s Failed to set ATTR_CEN_SPD_BAD_DQ_DATA", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_BAD_DQ_DATA 0x%02X ", l_target_str_storage, l_dqData);

fapi_try_exit:
    return fapi2::current_err;
}

}

namespace ddr3
{

enum factory_byte_offset
{
    MODULE_TYPE = 3,
    SDRAM_DENSITY_BANKS = 4,
    SDRAM_ADDRESSING = 5,
    SDRAM_NOMINAL_VOLTAGE = 6,
    MODULE_ORGANIZATION = 7,
    MEMORY_BUS_WIDTH = 8,
    FTB_DIVIDENT_DIVISOR = 9,
    MTB_DIVIDEND = 10,
    MTB_DIVISOR = 11,
    TCKMIN = 12,
    CAS_LATENCIES_SUPPORTED_BYTE1 = 14,
    CAS_LATENCIES_SUPPORTED_BYTE2 = 15,
    TAAMIN = 16,
    TWRMIN = 17,
    TRCDMIN = 18,
    TRRDMIN = 19,
    TRPMIN = 20,
    TRAS_TRC_UPPER_NIBBLE = 21,
    TRAS_MIN_LSB = 22,
    TRC_MIN_LSB = 23,
    TRFC_MIN_LSB = 24,
    TRFC_MIN_MSB = 25,
    TWTRMIN = 26,
    TRTPMIN = 27,
    TFAW_UPPER_NIBBLE = 28,
    TFAW_MIN = 29,
    SDRAM_OPTIONAL_FEATURES = 30,
    SDRAM_THERMAL_REFRESH_OPTIONS = 31,
    MODULE_THERMAL_SENSOR = 32,
    DRAM_PACKING_TYPE = 33, // Using DDR4 nomenclature to differentiate compared to DRAM_DEVICE_TYPE to avoid confusion
    FINE_OFFSET_TCKMIN = 34,
    FINE_OFFSET_TAAMIN = 35,
    FINE_OFFSET_TRCDMIN = 36,
    FINE_OFFSET_TRPMIN = 37,
    FINE_OFFSET_TRCMIN = 38,
    MODULE_ID_MODULE_MANUFACTURERS_JEDEC_ID_CODE_LOW = 117,
    MODULE_ID_MODULE_MANUFACTURERS_JEDEC_ID_CODE_HIGH = 118,
    MODULE_ID_MODULE_MANUFACTURING_LOCATION = 119,
    MODULE_ID_MODULE_MANUFACTURING_DATE_YEAR = 120,
    MODULE_ID_MODULE_MANUFACTURING_DATE_WEEK = 121,
    MODULE_ID_MODULE_SERIAL_NUMBER_BYTE1 = 122,
    MODULE_ID_MODULE_SERIAL_NUMBER_BYTE2 = 123,
    MODULE_ID_MODULE_SERIAL_NUMBER_BYTE3 = 124,
    MODULE_ID_MODULE_SERIAL_NUMBER_BYTE4 = 125,
    CRC1 = 126,
    CRC2 = 127,
    MODULE_PART_NUMBER = 128,
    MODULE_PART_NUMBER_LENGTH_IN_BYTES = 18,
    MODULE_REVISION_CODE1 = 146,
    MODULE_REVISION_CODE2 = 147,
    DRAM_MANUFACTURER_JEDEC_ID_CODE_LSB = 148,
    DRAM_MANUFACTURER_JEDEC_ID_CODE_MSB = 149,
    SPD_SIZE = 256,
};

///
/// @brief Cleans up DDR3 SPD information
/// @param[in] i_dimm, the dimm on which to opearte
/// @param[in] i_spd, the SPD on which to operate
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode set_spd_attributes( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
                                      const std::vector<uint8_t>& i_spd )
{
    char l_target_str_storage[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::toString(i_dimm, l_target_str_storage, fapi2::MAX_ECMD_STRING_LEN);

    uint8_t l_spd_byte1 = 0;
    uint8_t l_spd_byte2 = 0;
    uint8_t l_spd_byte3 = 0;
    uint8_t l_spd_byte4 = 0;
    uint8_t l_work_byte = 0;
    uint8_t l_work2_byte = 0;
    uint8_t l_module_pn[mss::common_spd::ATTR_MODULE_PART_NUMBER_LENGTH_IN_BYTES] = {0};
    uint32_t l_work_word = 0;
    // DQ SPD Attribute
    uint8_t l_dqData[DIMM_DQ_SPD_DATA_SIZE] = {0};

    // Checks that the DRAM size is the expected DDR3 SPD size
    FAPI_ASSERT(i_spd.size() == SPD_SIZE,
                fapi2::CEN_MSS_INVALID_SPD_SIZE()
                .set_TARGET_DIMM(i_dimm)
                .set_SPD_SIZE(i_spd.size())
                .set_EXPECTED_SIZE(SPD_SIZE)
                .set_FUNCTION(mss::DDR3),
                "%s DDR3 SPD size (%lu) does not equal expected size of %lu",
                l_target_str_storage, i_spd.size(), SPD_SIZE);

    l_spd_byte1 = i_spd[mss::common_spd::DRAM_DEVICE_TYPE];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_DRAM_DEVICE_TYPE, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_DRAM_DEVICE_TYPE", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_DRAM_DEVICE_TYPE 0x%02X ", l_target_str_storage, l_spd_byte1);

    // MODULE_TYPE
    l_spd_byte1 = i_spd[MODULE_TYPE];
    l_work_byte = l_spd_byte1 & 0xF;  // bits 3-0
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_MODULE_TYPE, i_dimm, l_work_byte),
              "%s Failed to set ATTR_CEN_SPD_MODULE_TYPE", l_target_str_storage );
    // Note: not technically in the DDR3 spec, but centaur XML says that the DDR3/DDR4 bits are located in the same place
    // in DDR3, this bit is reserved, so I guess centaur chose to use the same bit as in DDR4
    l_work_byte = (l_spd_byte1 & 0x80) >> 7;  // bit 7
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_CUSTOM, i_dimm, l_work_byte),
              "%s Failed to set ATTR_CEN_SPD_CUSTOM", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_CUSTOM 0x%02X ", l_target_str_storage, l_work_byte);

    // SDRAM_DENSITY_BANKS = 4
    l_spd_byte1 = i_spd[SDRAM_DENSITY_BANKS];
    l_work_byte = l_spd_byte1 & 0xf;  // bits 3-0
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_SDRAM_DENSITY, i_dimm, l_work_byte),
              "%s Failed to set ATTR_CEN_SPD_SDRAM_DENSITY", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_SDRAM_DENSITY 0x%02X ", l_target_str_storage, l_work_byte);
    l_work_byte = (l_spd_byte1 & 0x70) >> 4;  // bits 6-4
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_SDRAM_BANKS, i_dimm, l_work_byte),
              "%s Failed to set ATTR_CEN_SPD_SDRAM_BANKS", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_SDRAM_BANKS 0x%02X ", l_target_str_storage, l_work_byte);

    // SDRAM_ADDRESSING = 5
    l_spd_byte1 = i_spd[SDRAM_ADDRESSING];
    l_work_byte = l_spd_byte1 & 0x7;  // bits 2-0
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_SDRAM_COLUMNS, i_dimm, l_work_byte),
              "%s Failed to set ATTR_CEN_SPD_SDRAM_COLUMNS", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_SDRAM_COLUMNS 0x%02X ", l_target_str_storage, l_work_byte);
    l_work_byte = (l_spd_byte1 & 0x38) >> 3;  // bits 5-3
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_SDRAM_ROWS, i_dimm, l_work_byte),
              "%s Failed to set ATTR_CEN_SPD_SDRAM_ROWS", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_SDRAM_ROWS 0x%02X ", l_target_str_storage, l_work_byte);

    // SDRAM_NOMINAL_VOLTAGE = 6
    l_spd_byte1 = i_spd[SDRAM_NOMINAL_VOLTAGE];
    l_work_byte = l_spd_byte1 & 0x7;  // bits 1-0
    l_work2_byte = 0;

    if (l_work_byte & 0x1)
    {
        l_work2_byte |= fapi2::ENUM_ATTR_CEN_SPD_MODULE_NOMINAL_VOLTAGE_NOTOP1_5;
    }

    if (l_work_byte & 0x2)
    {
        l_work2_byte |= fapi2::ENUM_ATTR_CEN_SPD_MODULE_NOMINAL_VOLTAGE_OP1_35;
    }

    if (l_work_byte & 0x4)
    {
        l_work2_byte |= fapi2::ENUM_ATTR_CEN_SPD_MODULE_NOMINAL_VOLTAGE_OP1_2X;
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_MODULE_NOMINAL_VOLTAGE, i_dimm, l_work2_byte),
              "%s Failed to set ATTR_CEN_SPD_MODULE_NOMINAL_VOLTAGE", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_MODULE_NOMINAL_VOLTAGE 0x%02X ", l_target_str_storage, l_work2_byte);

    // MODULE_ORGANIZATION = 7
    l_spd_byte1 = i_spd[MODULE_ORGANIZATION];
    l_work_byte = l_spd_byte1 & 0x7;  // bits 2-0
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_DRAM_WIDTH, i_dimm, l_work_byte),
              "%s Failed to set ATTR_CEN_SPD_DRAM_WIDTH", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_DRAM_WIDTH 0x%02X ", l_target_str_storage, l_work_byte);
    l_work_byte = (l_spd_byte1 & 0x38) >> 3;  // bits 5-3
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_NUM_RANKS, i_dimm, l_work_byte),
              "%s Failed to set ATTR_CEN_SPD_NUM_RANKS", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_NUM_RANKS 0x%02X ", l_target_str_storage, l_work_byte);

    // MEMORY_BUS_WIDTH = 8
    l_spd_byte1 = i_spd[MEMORY_BUS_WIDTH];
    l_work_byte = l_spd_byte1 & 0x1F;  // bits 4-0
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_MODULE_MEMORY_BUS_WIDTH, i_dimm, l_work_byte),
              "%s Failed to set ATTR_CEN_SPD_MODULE_MEMORY_BUS_WIDTH", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_MODULE_MEMORY_BUS_WIDTH 0x%02X ", l_target_str_storage, l_work_byte);

    // FTB_DIVIDENT_DIVISOR = 9
    l_spd_byte1 = i_spd[FTB_DIVIDENT_DIVISOR];
    l_work_byte = l_spd_byte1 & 0xf;  // bits 3-0
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_FTB_DIVISOR, i_dimm, l_work_byte),
              "%s Failed to set ATTR_CEN_SPD_FTB_DIVISOR", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_FTB_DIVISOR 0x%02X ", l_target_str_storage, l_work_byte);
    l_work_byte = (l_spd_byte1 & 0xf0) >> 4;  // bits 7-0
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_FTB_DIVIDEND, i_dimm, l_work_byte),
              "%s Failed to set ATTR_CEN_SPD_FTB_DIVIDEND", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_FTB_DIVIDEND 0x%02X ", l_target_str_storage, l_work_byte);

    // MTB_DIVIDEND = 10
    l_spd_byte1 = i_spd[MTB_DIVIDEND];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_MTB_DIVIDEND, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_MTB_DIVIDEND", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_MTB_DIVIDEND 0x%02X ", l_target_str_storage, l_spd_byte1);

    // MTB_DIVISOR = 11
    l_spd_byte1 = i_spd[MTB_DIVISOR];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_MTB_DIVISOR, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_MTB_DIVISOR", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_MTB_DIVISOR 0x%02X ", l_target_str_storage, l_spd_byte1);

    // TCKMIN = 12
    l_spd_byte1 = i_spd[TCKMIN];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TCKMIN, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_TCKMIN", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_TCKMIN 0x%02X ", l_target_str_storage, l_spd_byte1);

    // CAS_LATENCIES_SUPPORTED = Bytes 14-15
    l_spd_byte1 = i_spd[CAS_LATENCIES_SUPPORTED_BYTE1];
    l_spd_byte2 = i_spd[CAS_LATENCIES_SUPPORTED_BYTE2];
    l_work_word = (l_spd_byte2 << 8) | l_spd_byte1;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_CAS_LATENCIES_SUPPORTED, i_dimm, l_work_word),
              "%s Failed to set ATTR_CEN_SPD_CAS_LATENCIES_SUPPORTED", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_CAS_LATENCIES_SUPPORTED 0x%02X ", l_target_str_storage, l_work_word);

    // TAAMIN = 16
    l_spd_byte1 = i_spd[TAAMIN];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TAAMIN, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_TAAMIN", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_TAAMIN 0x%02X ", l_target_str_storage, l_spd_byte1);

    // TAAMIN = 17
    l_spd_byte1 = i_spd[TWRMIN];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TWRMIN, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_TWRMIN", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_TWRMIN 0x%02X ", l_target_str_storage, l_spd_byte1);

    // TRCDMIN = 18
    l_spd_byte1 = i_spd[TRCDMIN];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TRCDMIN, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_TRCDMIN", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_TRCDMIN 0x%02X ", l_target_str_storage, l_spd_byte1);

    // TRRDMIN = 19
    l_spd_byte1 = i_spd[TRRDMIN];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TRRDMIN, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_TRRDMIN", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_TRRDMIN 0x%02X ", l_target_str_storage, l_spd_byte1);

    // TRPMIN = 20
    l_spd_byte1 = i_spd[TRPMIN];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TRPMIN, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_TRPMIN", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_TRPMIN 0x%02X ", l_target_str_storage, l_spd_byte1);

    // TRAS_MIN_LSB = 22
    // TRAS_TRC_UPPER_NIBBLE = 21
    l_spd_byte1 = (i_spd[TRAS_TRC_UPPER_NIBBLE] & 0xf);
    l_spd_byte2 = i_spd[TRAS_MIN_LSB];
    l_work_word = (l_spd_byte1 << 8) | l_spd_byte2;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TRASMIN, i_dimm, l_work_word),
              "%s Failed to set ATTR_CEN_SPD_TRASMIN", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_TRASMIN 0x%02X ", l_target_str_storage, l_work_word);

    // TRAS_MIN_LSB = 23
    // TRAS_TRC_UPPER_NIBBLE = 21
    l_spd_byte1 = i_spd[TRAS_TRC_UPPER_NIBBLE];
    l_spd_byte1 = (l_spd_byte1 & 0xf0) >> 4;
    l_spd_byte2 = i_spd[TRC_MIN_LSB];
    l_work_word = (l_spd_byte1 << 8) | l_spd_byte2;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TRCMIN, i_dimm, l_work_word),
              "%s Failed to set ATTR_CEN_SPD_TRCMIN", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_TRCMIN 0x%02X ", l_target_str_storage, l_work_word);

    // TRFC_MIN - LSB=24, MSB=25
    l_spd_byte1 = i_spd[TRFC_MIN_MSB];
    l_spd_byte2 = i_spd[TRFC_MIN_LSB];
    l_work_word = (l_spd_byte1 << 8) | l_spd_byte2;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TRFCMIN, i_dimm, l_work_word),
              "%s Failed to set ATTR_CEN_SPD_TRFCMIN", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_TRFCMIN 0x%02X ", l_target_str_storage, l_work_word);

    // TRRDMIN = 26
    l_spd_byte1 = i_spd[TWTRMIN];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TWTRMIN, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_TWTRMIN", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_TWTRMIN 0x%02X ", l_target_str_storage, l_spd_byte1);

    // TRRDMIN = 27
    l_spd_byte1 = i_spd[TRTPMIN];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TRTPMIN, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_TRTPMIN", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_TRTPMIN 0x%02X ", l_target_str_storage, l_spd_byte1);

    // TFAW_MIN = 29
    // TFAW_UPPER_NIBBLE = 28
    l_spd_byte1 = (i_spd[TFAW_UPPER_NIBBLE] & 0xf);
    l_spd_byte2 = i_spd[TFAW_MIN];
    l_work_word = (l_spd_byte1 << 8) | l_spd_byte2;
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TFAWMIN, i_dimm, l_work_word),
              "%s Failed to set ATTR_CEN_SPD_TFAWMIN", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_TFAWMIN 0x%02X ", l_target_str_storage, l_work_word);

    // SDRAM_OPTIONAL_FEATURES = 30
    l_spd_byte1 = i_spd[SDRAM_OPTIONAL_FEATURES];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_SDRAM_OPTIONAL_FEATURES, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_SDRAM_OPTIONAL_FEATURES", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_SDRAM_OPTIONAL_FEATURES 0x%02X ", l_target_str_storage, l_spd_byte1);

    // SDRAM_THERMAL_REFRESH_OPTIONS = 31
    l_spd_byte1 = i_spd[SDRAM_THERMAL_REFRESH_OPTIONS];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_SDRAM_THERMAL_AND_REFRESH_OPTIONS, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_SDRAM_THERMAL_AND_REFRESH_OPTIONS", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_SDRAM_THERMAL_AND_REFRESH_OPTIONS 0x%02X ", l_target_str_storage, l_spd_byte1);

    // MODULE_THERMAL_SENSOR = 32
    l_spd_byte1 = i_spd[MODULE_THERMAL_SENSOR];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_MODULE_THERMAL_SENSOR, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_MODULE_THERMAL_SENSOR", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_MODULE_THERMAL_SENSOR 0x%02X ", l_target_str_storage, l_spd_byte1);

    // SDRAM_PACKING_TYPE = 33
    l_spd_byte1 = i_spd[DRAM_PACKING_TYPE];
    l_work_byte = (l_spd_byte1 & 0x80) >> 7;  // bit 7
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_SDRAM_DEVICE_TYPE, i_dimm, l_work_byte),
              "%s Failed to set ATTR_CEN_SPD_SDRAM_DEVICE_TYPE", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_SDRAM_DEVICE_TYPE 0x%02X ", l_target_str_storage, l_work_byte);
    l_work_byte = (l_spd_byte1 & 0x70) >> 4;  // bits 6-4
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_SDRAM_DIE_COUNT, i_dimm, l_work_byte),
              "%s Failed to set ATTR_CEN_SPD_SDRAM_DIE_COUNT", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_SDRAM_DIE_COUNT 0x%02X ", l_target_str_storage, l_work_byte);
    l_work_byte = l_spd_byte1 & 0x03;  // bits 1-0
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_SDRAM_DEVICE_TYPE_SIGNAL_LOADING, i_dimm, l_work_byte),
              "%s Failed to set ATTR_CEN_SPD_SDRAM_DEVICE_TYPE_SIGNAL_LOADING", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_SDRAM_DEVICE_TYPE_SIGNAL_LOADING 0x%02X ", l_target_str_storage, l_work_byte);

    // FINE_OFFSET_TCKMIN = 34
    l_spd_byte1 = i_spd[FINE_OFFSET_TCKMIN];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_FINE_OFFSET_TCKMIN, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_FINE_OFFSET_TCKMIN", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_FINE_OFFSET_TCKMIN 0x%02X ", l_target_str_storage, l_spd_byte1);

    // FINE_OFFSET_TAAMIN =  35
    l_spd_byte1 = i_spd[FINE_OFFSET_TAAMIN];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_FINE_OFFSET_TAAMIN, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_FINE_OFFSET_TAAMIN", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_FINE_OFFSET_TAAMIN 0x%02X ", l_target_str_storage, l_spd_byte1);

    // FINE_OFFSET_TRCDMIN = 36
    l_spd_byte1 = i_spd[FINE_OFFSET_TRCDMIN];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_FINE_OFFSET_TRCDMIN, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_FINE_OFFSET_TRCDMIN", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_FINE_OFFSET_TRCDMIN 0x%02X ", l_target_str_storage, l_spd_byte1);

    // FINE_OFFSET_TRPMIN = 37
    l_spd_byte1 = i_spd[FINE_OFFSET_TRPMIN];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_FINE_OFFSET_TRPMIN, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_FINE_OFFSET_TRPMIN", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_FINE_OFFSET_TRPMIN 0x%02X ", l_target_str_storage, l_spd_byte1);

    // FINE_OFFSET_TRCMIN = 38
    l_spd_byte1 = i_spd[FINE_OFFSET_TRCMIN];
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_FINE_OFFSET_TRCMIN, i_dimm, l_spd_byte1),
              "%s Failed to set ATTR_CEN_SPD_FINE_OFFSET_TRCMIN", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_FINE_OFFSET_TRCMIN 0x%02X ", l_target_str_storage, l_spd_byte1);

    //MODULE_ID_MODULE_MANUFACTURERS_JEDEC_ID_CODE_LOW = 117
    //MODULE_ID_MODULE_MANUFACTURERS_JEDEC_ID_CODE_HIGH = 118
    l_spd_byte1 = i_spd[MODULE_ID_MODULE_MANUFACTURERS_JEDEC_ID_CODE_HIGH];
    l_spd_byte2 = i_spd[MODULE_ID_MODULE_MANUFACTURERS_JEDEC_ID_CODE_LOW];
    l_work_word = (l_spd_byte1 << 8) | l_spd_byte2;
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_MODULE_ID_MODULE_MANUFACTURERS_JEDEC_ID_CODE, i_dimm, l_work_word),
             "%s Failed to set ATTR_CEN_SPD_MODULE_ID_MODULE_MANUFACTURERS_JEDEC_ID_CODE", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_MODULE_ID_MODULE_MANUFACTURERS_JEDEC_ID_CODE 0x%02X ", l_target_str_storage, l_spd_byte1);

    //MODULE_ID_MODULE_MANUFACTURING_LOCATION = 119
    l_spd_byte1 = i_spd[MODULE_ID_MODULE_MANUFACTURING_LOCATION];
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_MODULE_ID_MODULE_MANUFACTURING_LOCATION, i_dimm, l_spd_byte1),
             "%s Failed to set ATTR_CEN_SPD_MODULE_ID_MODULE_MANUFACTURING_LOCATION", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_MODULE_ID_MODULE_MANUFACTURING_LOCATION 0x%02X ", l_target_str_storage, l_spd_byte1);

    //MODULE_ID_MODULE_MANUFACTURING_DATE_YEAR = 120
    //MODULE_ID_MODULE_MANUFACTURING_DATE_WEEK = 121 (LSB)
    l_spd_byte1 = i_spd[MODULE_ID_MODULE_MANUFACTURING_DATE_YEAR];
    l_spd_byte2 = i_spd[MODULE_ID_MODULE_MANUFACTURING_DATE_WEEK];
    l_work_word = (l_spd_byte1 << 8) | l_spd_byte2;
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_MODULE_ID_MODULE_MANUFACTURING_DATE, i_dimm, l_work_word),
             "%s Failed to set ATTR_CEN_SPD_MODULE_ID_MODULE_MANUFACTURING_DATE", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_MODULE_ID_MODULE_MANUFACTURING_DATE 0x%02X ", l_target_str_storage, l_work_word);

    //MODULE_ID_MODULE_SERIAL_NUMBER_BYTE1 = 122 (LSB)
    //MODULE_ID_MODULE_SERIAL_NUMBER_BYTE2 = 123
    //MODULE_ID_MODULE_SERIAL_NUMBER_BYTE3 = 124
    //MODULE_ID_MODULE_SERIAL_NUMBER_BYTE4 = 125
    l_spd_byte1 = i_spd[MODULE_ID_MODULE_SERIAL_NUMBER_BYTE1];
    l_spd_byte2 = i_spd[MODULE_ID_MODULE_SERIAL_NUMBER_BYTE2];
    l_spd_byte3 = i_spd[MODULE_ID_MODULE_SERIAL_NUMBER_BYTE3];
    l_spd_byte4 = i_spd[MODULE_ID_MODULE_SERIAL_NUMBER_BYTE4];
    l_work_word = (l_spd_byte4 << 24) | (l_spd_byte3 << 16) | (l_spd_byte2 << 8) | l_spd_byte1;
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_MODULE_ID_MODULE_SERIAL_NUMBER, i_dimm, l_work_word),
             "%s Failed to set ATTR_CEN_SPD_MODULE_ID_MODULE_SERIAL_NUMBER", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_MODULE_ID_MODULE_SERIAL_NUMBER 0x%02X ", l_target_str_storage, l_work_word);

    //MODULE_PART_NUMBER = 128:145
    for (uint16_t l_byte = 0; l_byte < MODULE_PART_NUMBER_LENGTH_IN_BYTES; l_byte++)
    {
        l_module_pn[l_byte] = i_spd[l_byte + MODULE_PART_NUMBER];
    }

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_MODULE_PART_NUMBER, i_dimm, l_module_pn),
             "%s Failed to set ATTR_CEN_SPD_MODULE_PART_NUMBER", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_MODULE_PART_NUMBER 0x%02X ", l_target_str_storage, l_module_pn[0]);

    //MODULE_REVISION_CODE1 = 146
    //MODULE_REVISION_CODE2 = 147
    l_spd_byte1 = i_spd[MODULE_REVISION_CODE1];
    l_spd_byte2 = i_spd[MODULE_REVISION_CODE2];
    l_work_word = (l_spd_byte1 << 8) | l_spd_byte2;
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_MODULE_REVISION_CODE, i_dimm, l_work_word),
             "%s Failed to set ATTR_CEN_SPD_MODULE_REVISION_CODE", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_MODULE_REVISION_CODE 0x%02X ", l_target_str_storage, l_spd_byte1);

    //DRAM_MANUFACTURER_JEDEC_ID_CODE_LSB = 117
    //DRAM_MANUFACTURER_JEDEC_ID_CODE_MSB = 118
    l_spd_byte1 = i_spd[DRAM_MANUFACTURER_JEDEC_ID_CODE_MSB];
    l_spd_byte2 = i_spd[DRAM_MANUFACTURER_JEDEC_ID_CODE_LSB];
    l_work_word = (l_spd_byte1 << 8) | l_spd_byte2;
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_DRAM_MANUFACTURER_JEDEC_ID_CODE, i_dimm, l_work_word),
             "%s Failed to set ATTR_CEN_SPD_DRAM_MANUFACTURER_JEDEC_ID_CODE", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_DRAM_MANUFACTURER_JEDEC_ID_CODE 0x%02X ", l_target_str_storage, l_spd_byte1);

    // Reset ATTR_CEN_SPD_BAD_DQ_DATA
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_BAD_DQ_DATA, i_dimm, l_dqData),
              "%s Failed to set ATTR_CEN_SPD_BAD_DQ_DATA", l_target_str_storage );
    FAPI_INF("%s Set ATTR_CEN_SPD_BAD_DQ_DATA 0x%02X ", l_target_str_storage, l_dqData);

fapi_try_exit:
    return fapi2::current_err;
}

}

}
