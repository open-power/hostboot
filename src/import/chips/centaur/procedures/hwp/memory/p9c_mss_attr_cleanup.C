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

enum factory_byte_offset
{
    REVISION = 1,       ///< SPD Revision
    DRAM_DEVICE_TYPE = 2,   ///< SPD DRAM Interface Type
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
    CRC_MNFG_SEC_DDR4_MSB = 383
};

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
    FAPI_INF("Start");

    fapi2::ReturnCode l_rc;
    size_t l_size = 0;
    uint8_t l_spd_byte1 = 0;
    uint8_t l_spd_byte2 = 0;
    uint8_t l_spd_byte3 = 0;
    uint8_t l_spd_byte4 = 0;
    uint8_t l_work_byte = 0;
    uint8_t l_work2_byte = 0;
    uint8_t l_module_pn[MODULE_PART_NUMBER_LENGTH_IN_BYTES] = {0};
    uint32_t l_work_word = 0;
    // DQ SPD Attribute
    uint8_t l_dqData[DIMM_DQ_SPD_DATA_SIZE] {0};

    // Get the size of the factory
    FAPI_TRY( fapi2::getSPD(i_dimm, nullptr, l_size),
              "Failed to retrieve SPD blob size");
    FAPI_INF("Get SPD Data size 0x%X ", l_size);
    {
        // "Container" for SPD data
        std::vector<uint8_t> l_spd(l_size);
        // Retrieve SPD data
        FAPI_TRY( fapi2::getSPD(i_dimm, l_spd.data(), l_size),
                  "Failed to retrieve SPD data" );
        FAPI_INF("Get SPD Data byte 0 0x%X ", l_spd[0]);


        // Brute force pull the data from the SPD and set it in
        // REVISION = 1
        l_spd_byte1 = l_spd[REVISION];
        FAPI_INF("ATTR_CEN_SPD_REVISION 0x%X ", l_spd_byte1);

        // DRAM_DEVICE_TYPE
        l_spd_byte1 = l_spd[DRAM_DEVICE_TYPE];

        if(l_spd_byte1 == 0x0c)
        {
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_DRAM_DEVICE_TYPE, i_dimm, l_spd_byte1),
                      "Failed to set ATTR_CEN_SPD_DRAM_DEVICE_TYPE" );
            FAPI_INF("Set ATTR_CEN_SPD_DRAM_DEVICE_TYPE 0x%X ", l_spd_byte1);

            // MODULE_TYPE
            l_spd_byte1 = l_spd[MODULE_TYPE];
            l_work_byte = l_spd_byte1 & 0xF;  // bits 3-0
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_MODULE_TYPE, i_dimm, l_work_byte),
                      "Failed to set ATTR_CEN_SPD_MODULE_TYPE" );
            FAPI_INF("Set ATTR_CEN_SPD_MODULE_TYPE 0x%X ", l_work_byte);
            l_work_byte = (l_spd_byte1 & 0x80) >> 7;  // bit 7
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_CUSTOM, i_dimm, l_work_byte),
                      "Failed to set ATTR_CEN_SPD_CUSTOM" );
            FAPI_INF("Set ATTR_CEN_SPD_CUSTOM 0x%X ", l_work_byte);

            // SDRAM_DENSITY = 4
            l_spd_byte1 = l_spd[SDRAM_DENSITY];
            l_work_byte = l_spd_byte1 & 0xF;  // bits 3-0
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_SDRAM_DENSITY, i_dimm, l_work_byte),
                      "Failed to set ATTR_CEN_SPD_SDRAM_DENSITY" );
            FAPI_INF("Set ATTR_CEN_SPD_SDRAM_DENSITY 0x%X ", l_work_byte);
            l_work_byte = (l_spd_byte1 & 0x30) >> 4;  // bits 5-4
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_SDRAM_BANKS, i_dimm, l_work_byte),
                      "Failed to set ATTR_CEN_SPD_SDRAM_BANKS" );
            FAPI_INF("Set ATTR_CEN_SPD_SDRAM_BANKS 0x%X ", l_work_byte);

            // SDRAM_ADDRESSING = 5
            l_spd_byte1 = l_spd[SDRAM_ADDRESSING];
            l_work_byte = l_spd_byte1 & 0x7;  // bits 2-0
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_SDRAM_COLUMNS, i_dimm, l_work_byte),
                      "Failed to set ATTR_CEN_SPD_SDRAM_COLUMNS" );
            FAPI_INF("Set ATTR_CEN_SPD_SDRAM_COLUMNS 0x%X ", l_work_byte);
            l_work_byte = (l_spd_byte1 & 0x38) >> 3;  // bits 5-3
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_SDRAM_ROWS, i_dimm, l_work_byte),
                      "Failed to set ATTR_CEN_SPD_SDRAM_ROWS" );
            FAPI_INF("Set ATTR_CEN_SPD_SDRAM_ROWS 0x%X ", l_work_byte);

            // SDRAM_PACKING_TYPE = 6
            l_spd_byte1 = l_spd[SDRAM_PACKING_TYPE];
            l_work_byte = (l_spd_byte1 & 0x80) >> 7;  // bit 7
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_SDRAM_DEVICE_TYPE, i_dimm, l_work_byte),
                      "Failed to set ATTR_CEN_SPD_SDRAM_DEVICE_TYPE" );
            FAPI_INF("Set ATTR_CEN_SPD_SDRAM_DEVICE_TYPE 0x%X ", l_work_byte);
            l_work_byte = (l_spd_byte1 & 0x70) >> 4;  // bits 6-4
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_SDRAM_DIE_COUNT, i_dimm, l_work_byte),
                      "Failed to set ATTR_CEN_SPD_SDRAM_DIE_COUNT" );
            FAPI_INF("Set ATTR_CEN_SPD_SDRAM_DIE_COUNT 0x%X ", l_work_byte);
            l_work_byte = l_spd_byte1 & 0x03;  // bits 1-0
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_SDRAM_DEVICE_TYPE_SIGNAL_LOADING, i_dimm, l_work_byte),
                      "Failed to set ATTR_CEN_SPD_SDRAM_DEVICE_TYPE_SIGNAL_LOADING" );
            FAPI_INF("Set ATTR_CEN_SPD_SDRAM_DEVICE_TYPE_SIGNAL_LOADING 0x%X ", l_work_byte);

            // SDRAM_OPTIONAL_FEATURES = 7
            l_spd_byte1 = l_spd[SDRAM_OPTIONAL_FEATURES];
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_SDRAM_OPTIONAL_FEATURES, i_dimm, l_spd_byte1),
                      "Failed to set ATTR_CEN_SPD_SDRAM_OPTIONAL_FEATURES" );
            FAPI_INF("Set ATTR_CEN_SPD_SDRAM_OPTIONAL_FEATURES 0x%X ", l_spd_byte1);

            // SDRAM_THERMAL_OPTIONS = 8
            l_spd_byte1 = l_spd[SDRAM_THERMAL_OPTIONS];
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_SDRAM_THERMAL_AND_REFRESH_OPTIONS, i_dimm, l_spd_byte1),
                      "Failed to set ATTR_CEN_SPD_SDRAM_THERMAL_AND_REFRESH_OPTIONS" );
            FAPI_INF("Set ATTR_CEN_SPD_SDRAM_THERMAL_AND_REFRESH_OPTIONS 0x%X ", l_spd_byte1);

            // MODULE_NOMINAL_VOLTAGE = 11
            l_spd_byte1 = l_spd[MODULE_NOMINAL_VOLTAGE];
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
                      "Failed to set ATTR_CEN_SPD_MODULE_NOMINAL_VOLTAGE" );
            FAPI_INF("Set ATTR_CEN_SPD_MODULE_NOMINAL_VOLTAGE 0x%X ", l_work2_byte);

            // MODULE_ORGANIZATION = 12
            l_spd_byte1 = l_spd[MODULE_ORGANIZATION];
            l_work_byte = l_spd_byte1 & 0x7;  // bits 2-0
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_DRAM_WIDTH, i_dimm, l_work_byte),
                      "Failed to set ATTR_CEN_SPD_DRAM_WIDTH" );
            FAPI_INF("Set ATTR_CEN_SPD_DRAM_WIDTH 0x%X ", l_work_byte);
            l_work_byte = (l_spd_byte1 & 0x38) >> 3;  // bits 5-3
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_NUM_RANKS, i_dimm, l_work_byte),
                      "Failed to set ATTR_CEN_SPD_NUM_RANKS" );
            FAPI_INF("Set ATTR_CEN_SPD_NUM_RANKS 0x%X ", l_work_byte);

            // MODULE_MEMORY_BUS_WIDTH = 13
            l_spd_byte1 = l_spd[MODULE_MEMORY_BUS_WIDTH];
            l_work_byte = l_spd_byte1 & 0x1F;  // bits 4-0
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_MODULE_MEMORY_BUS_WIDTH, i_dimm, l_work_byte),
                      "Failed to set ATTR_CEN_SPD_MODULE_MEMORY_BUS_WIDTH" );
            FAPI_INF("Set ATTR_CEN_SPD_MODULE_MEMORY_BUS_WIDTH 0x%X ", l_work_byte);

            // MODULE_THERMAL_SENSOR = 14
            l_spd_byte1 = l_spd[MODULE_THERMAL_SENSOR];
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_MODULE_THERMAL_SENSOR, i_dimm, l_spd_byte1),
                      "Failed to set ATTR_CEN_SPD_MODULE_THERMAL_SENSOR" );
            FAPI_INF("Set ATTR_CEN_SPD_MODULE_THERMAL_SENSOR 0x%X ", l_spd_byte1);

            // TIMEBASE = 17,
            l_spd_byte1 = l_spd[MODULE_THERMAL_SENSOR];
            l_work_byte = (l_spd_byte1 & 0x0C) >> 2;  // bits 3-2
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TIMEBASE_MTB_DDR4, i_dimm, l_work_byte),
                      "Failed to set ATTR_CEN_SPD_TIMEBASE_MTB_DDR4" );
            FAPI_INF("Set ATTR_CEN_SPD_TIMEBASE_MTB_DDR4 0x%X ", l_work_byte);
            l_work_byte = l_spd_byte1 & 0x3;  // bits 1-0
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TIMEBASE_FTB_DDR4, i_dimm, l_work_byte),
                      "Failed to set ATTR_CEN_SPD_TIMEBASE_FTB_DDR4" );
            FAPI_INF("Set ATTR_CEN_SPD_TIMEBASE_FTB_DDR4 0x%X ", l_work_byte);

            // TCKMIN = 18
            l_spd_byte1 = l_spd[TCKMIN];
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TCKMIN, i_dimm, l_spd_byte1),
                      "Failed to set ATTR_CEN_SPD_TCKMIN" );
            FAPI_INF("Set ATTR_CEN_SPD_TCKMIN 0x%X ", l_spd_byte1);

            // TCKMAX_DDR4 = 19
            l_spd_byte1 = l_spd[TCKMAX_DDR4];
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TCKMAX_DDR4, i_dimm, l_spd_byte1),
                      "Failed to set ATTR_CEN_SPD_TCKMAX_DDR4" );
            FAPI_INF("Set ATTR_CEN_SPD_TCKMAX_DDR4 0x%X ", l_spd_byte1);

            // CAS_LATENCIES_SUPPORTED = Bytes 20-23
            l_spd_byte1 = l_spd[CAS_LATENCIES_SUPPORTED_BYTE1];
            l_spd_byte2 = l_spd[CAS_LATENCIES_SUPPORTED_BYTE2];
            l_spd_byte3 = l_spd[CAS_LATENCIES_SUPPORTED_BYTE3];
            l_spd_byte4 = l_spd[CAS_LATENCIES_SUPPORTED_BYTE4];
            l_work_word = (l_spd_byte4 << 24) | (l_spd_byte3 << 16) | (l_spd_byte2 << 8) | l_spd_byte1;
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_CAS_LATENCIES_SUPPORTED, i_dimm, l_work_word),
                      "Failed to set ATTR_CEN_SPD_CAS_LATENCIES_SUPPORTED" );
            FAPI_INF("Set ATTR_CEN_SPD_CAS_LATENCIES_SUPPORTED 0x%X ", l_work_word);

            // TAAMIN = 24
            l_spd_byte1 = l_spd[TAAMIN];
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TAAMIN, i_dimm, l_spd_byte1),
                      "Failed to set ATTR_CEN_SPD_TAAMIN" );
            FAPI_INF("Set ATTR_CEN_SPD_TAAMIN 0x%X ", l_spd_byte1);

            // TRCDMIN = 25
            l_spd_byte1 = l_spd[TRCDMIN];
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TRCDMIN, i_dimm, l_spd_byte1),
                      "Failed to set ATTR_CEN_SPD_TRCDMIN" );
            FAPI_INF("Set ATTR_CEN_SPD_TRCDMIN 0x%X ", l_spd_byte1);

            // TRPMIN = 26
            l_spd_byte1 = l_spd[TRPMIN];
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TRPMIN, i_dimm, l_spd_byte1),
                      "Failed to set ATTR_CEN_SPD_TRPMIN" );
            FAPI_INF("Set ATTR_CEN_SPD_TRPMIN 0x%X ", l_spd_byte1);

            // TRAS_TRCMIN_HIGH = 27,
            // TRASMIN_LOW = 28
            l_spd_byte1 = l_spd[TRAS_TRCMIN_HIGH];
            l_spd_byte2 = l_spd[TRASMIN_LOW];
            l_work_word = ((l_spd_byte1 & 0xF0) << 4) | l_spd_byte2;
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TRASMIN, i_dimm, l_work_word),
                      "Failed to set ATTR_CEN_SPD_TRASMIN" );
            FAPI_INF("Set ATTR_CEN_SPD_TRASMIN 0x%X ", l_work_word);

            // TRCMIN_LOW = 29,
            l_spd_byte2 = l_spd[TRCMIN_LOW];
            l_work_word = ((l_spd_byte1 & 0xF) << 8) | l_spd_byte2;
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TRCMIN, i_dimm, l_work_word),
                      "Failed to set ATTR_CEN_SPD_TRCMIN" );
            FAPI_INF("Set ATTR_CEN_SPD_TRCMIN 0x%X ", l_work_word);

            // TRFC1MIN_DDR4_LOW = 30
            // TRFC1MIN_DDR4_HIGH = 31
            l_spd_byte1 = l_spd[TRFC1MIN_DDR4_HIGH];
            l_spd_byte2 = l_spd[TRFC1MIN_DDR4_LOW];
            l_work_word = (l_spd_byte1 << 8) | l_spd_byte2;
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TRFC1MIN_DDR4, i_dimm, l_work_word),
                      "Failed to set ATTR_CEN_SPD_TRFC1MIN_DDR4" );
            FAPI_INF("Set ATTR_CEN_SPD_TRFC1MIN_DDR4 0x%X ", l_work_word);

            // TRFC2MIN_DDR4_LOW = 32,
            // TRFC2MIN_DDR4_HIGH = 33,
            l_spd_byte1 = l_spd[TRFC2MIN_DDR4_HIGH];
            l_spd_byte2 = l_spd[TRFC2MIN_DDR4_LOW];
            l_work_word = (l_spd_byte1 << 8) | l_spd_byte2;
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TRFC2MIN_DDR4, i_dimm, l_work_word),
                      "Failed to set ATTR_CEN_SPD_TRFC2MIN_DDR4" );
            FAPI_INF("Set ATTR_CEN_SPD_TRFC2MIN_DDR4 0x%X ", l_work_word);

            // TRFC4MIN_DDR4_LOW = 34,
            // TRFC4MIN_DDR4_HIGH = 35,
            l_spd_byte1 = l_spd[TRFC4MIN_DDR4_HIGH];
            l_spd_byte2 = l_spd[TRFC4MIN_DDR4_LOW];
            l_work_word = (l_spd_byte1 << 8) | l_spd_byte2;
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TRFC4MIN_DDR4, i_dimm, l_work_word),
                      "Failed to set ATTR_CEN_SPD_TRFC4MIN_DDR4" );
            FAPI_INF("Set ATTR_CEN_SPD_TRFC4MIN_DDR4 0x%X ", l_work_word);

            // TFAWMIN_HIGH = 36
            // TFAWMIN_LOW = 37,
            l_spd_byte1 = l_spd[TFAWMIN_HIGH];
            l_spd_byte2 = l_spd[TFAWMIN_LOW];
            l_work_word = (l_spd_byte1 << 8) | l_spd_byte2;
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TFAWMIN, i_dimm, l_work_word),
                      "Failed to set ATTR_CEN_SPD_TFAWMIN" );
            FAPI_INF("Set ATTR_CEN_SPD_TFAWMIN 0x%X ", l_work_word);

            // TRRDSMIN_DDR4 = 38
            l_spd_byte1 = l_spd[TRRDSMIN_DDR4];
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TRRDSMIN_DDR4, i_dimm, l_spd_byte1),
                      "Failed to set ATTR_CEN_SPD_TRRDSMIN_DDR4" );
            FAPI_INF("Set ATTR_CEN_SPD_TRRDSMIN_DDR4 0x%X ", l_spd_byte1);

            // TRRDLMIN_DDR4 = 39
            l_spd_byte1 = l_spd[TRRDLMIN_DDR4];
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TRRDLMIN_DDR4, i_dimm, l_spd_byte1),
                      "Failed to set ATTR_CEN_SPD_TRRDLMIN_DDR4" );
            FAPI_INF("Set ATTR_CEN_SPD_TRRDLMIN_DDR4 0x%X ", l_spd_byte1);

            // TCCDLMIN_DDR4 = 40,ATTR_CEN_SPD_TCCDLMIN_DDR4
            l_spd_byte1 = l_spd[TCCDLMIN_DDR4];
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_TCCDLMIN_DDR4, i_dimm, l_spd_byte1),
                      "Failed to set ATTR_CEN_SPD_TCCDLMIN_DDR4" );
            FAPI_INF("Set ATTR_CEN_SPD_TCCDLMIN_DDR4 0x%X ", l_spd_byte1);

            // FINE_OFFSET_TRCMIN = 120
            l_spd_byte1 = l_spd[FINE_OFFSET_TRCMIN];
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_FINE_OFFSET_TRCMIN, i_dimm, l_spd_byte1),
                      "Failed to set ATTR_CEN_SPD_FINE_OFFSET_TRCMIN" );
            FAPI_INF("Set ATTR_CEN_SPD_FINE_OFFSET_TRCMIN 0x%X ", l_spd_byte1);

            // FINE_OFFSET_TRPMIN = 121
            l_spd_byte1 = l_spd[FINE_OFFSET_TRPMIN];
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_FINE_OFFSET_TRPMIN, i_dimm, l_spd_byte1),
                      "Failed to set ATTR_CEN_SPD_FINE_OFFSET_TRPMIN" );
            FAPI_INF("Set ATTR_CEN_SPD_FINE_OFFSET_TRPMIN 0x%X ", l_spd_byte1);

            // FINE_OFFSET_TRCDMIN = 122
            l_spd_byte1 = l_spd[FINE_OFFSET_TRCDMIN];
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_FINE_OFFSET_TRCDMIN, i_dimm, l_spd_byte1),
                      "Failed to set ATTR_CEN_SPD_FINE_OFFSET_TRCDMIN" );
            FAPI_INF("Set ATTR_CEN_SPD_FINE_OFFSET_TRCDMIN 0x%X ", l_spd_byte1);

            // FINE_OFFSET_TAAMIN =  123
            l_spd_byte1 = l_spd[FINE_OFFSET_TAAMIN];
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_FINE_OFFSET_TAAMIN, i_dimm, l_spd_byte1),
                      "Failed to set ATTR_CEN_SPD_FINE_OFFSET_TAAMIN" );
            FAPI_INF("Set ATTR_CEN_SPD_FINE_OFFSET_TAAMIN 0x%X ", l_spd_byte1);

            // FINE_OFFSET_TCKMAX_DDR4 = 124
            l_spd_byte1 = l_spd[FINE_OFFSET_TCKMAX_DDR4];
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_FINE_OFFSET_TCKMAX_DDR4, i_dimm, l_spd_byte1),
                      "Failed to set ATTR_CEN_SPD_FINE_OFFSET_TCKMAX_DDR4" );
            FAPI_INF("Set ATTR_CEN_SPD_FINE_OFFSET_TCKMAX_DDR4 0x%X ", l_spd_byte1);

            // FINE_OFFSET_TCKMIN = 125
            l_spd_byte1 = l_spd[FINE_OFFSET_TCKMIN];
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_FINE_OFFSET_TCKMIN, i_dimm, l_spd_byte1),
                      "Failed to set ATTR_CEN_SPD_FINE_OFFSET_TCKMIN" );
            FAPI_INF("Set ATTR_CEN_SPD_FINE_OFFSET_TCKMIN 0x%X ", l_spd_byte1);

            //ADDR_MAP_REG_TO_DRAM = 136
            l_spd_byte1 = l_spd[ADDR_MAP_REG_TO_DRAM];
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_ADDR_MAP_REG_TO_DRAM, i_dimm, l_spd_byte1),
                     "Failed to set ATTR_CEN_SPD_ADDR_MAP_REG_TO_DRAM");
            FAPI_INF("Set ATTR_CEN_SPD_ADDR_MAP_REG_TO_DRAM 0x%X ", l_spd_byte1);

            //MODULE_ID_MODULE_MANUFACTURERS_JEDEC_ID_CODE_LOW = 320
            //MODULE_ID_MODULE_MANUFACTURERS_JEDEC_ID_CODE_HIGH = 321
            l_spd_byte1 = l_spd[MODULE_ID_MODULE_MANUFACTURERS_JEDEC_ID_CODE_HIGH];
            l_spd_byte2 = l_spd[MODULE_ID_MODULE_MANUFACTURERS_JEDEC_ID_CODE_LOW];
            l_work_word = (l_spd_byte1 << 8) | l_spd_byte2;
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_MODULE_ID_MODULE_MANUFACTURERS_JEDEC_ID_CODE, i_dimm, l_work_word),
                     "Failed to set ATTR_CEN_SPD_MODULE_ID_MODULE_MANUFACTURERS_JEDEC_ID_CODE");
            FAPI_INF("Set ATTR_CEN_SPD_MODULE_ID_MODULE_MANUFACTURERS_JEDEC_ID_CODE 0x%X ", l_spd_byte1);

            //MODULE_ID_MODULE_MANUFACTURING_LOCATION = 322
            l_spd_byte1 = l_spd[MODULE_ID_MODULE_MANUFACTURING_LOCATION];
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_MODULE_ID_MODULE_MANUFACTURING_LOCATION, i_dimm, l_spd_byte1),
                     "Failed to set ATTR_CEN_SPD_MODULE_ID_MODULE_MANUFACTURING_LOCATION");
            FAPI_INF("Set ATTR_CEN_SPD_MODULE_ID_MODULE_MANUFACTURING_LOCATION 0x%X ", l_spd_byte1);

            //MODULE_ID_MODULE_MANUFACTURING_DATE_YEAR = 323
            //MODULE_ID_MODULE_MANUFACTURING_DATE_WEEK = 324 (LSB)
            l_spd_byte1 = l_spd[MODULE_ID_MODULE_MANUFACTURING_DATE_YEAR];
            l_spd_byte2 = l_spd[MODULE_ID_MODULE_MANUFACTURING_DATE_WEEK];
            l_work_word = (l_spd_byte1 << 8) | l_spd_byte2;
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_MODULE_ID_MODULE_MANUFACTURING_DATE, i_dimm, l_work_word),
                     "Failed to set ATTR_CEN_SPD_MODULE_ID_MODULE_MANUFACTURING_DATE");
            FAPI_INF("Set ATTR_CEN_SPD_MODULE_ID_MODULE_MANUFACTURING_DATE 0x%X ", l_work_word);

            //MODULE_ID_MODULE_SERIAL_NUMBER_BYTE1 = 325 (LSB)
            //MODULE_ID_MODULE_SERIAL_NUMBER_BYTE2 = 326
            //MODULE_ID_MODULE_SERIAL_NUMBER_BYTE3 = 327
            //MODULE_ID_MODULE_SERIAL_NUMBER_BYTE4 = 328
            l_spd_byte1 = l_spd[MODULE_ID_MODULE_SERIAL_NUMBER_BYTE1];
            l_spd_byte2 = l_spd[MODULE_ID_MODULE_SERIAL_NUMBER_BYTE2];
            l_spd_byte3 = l_spd[MODULE_ID_MODULE_SERIAL_NUMBER_BYTE3];
            l_spd_byte4 = l_spd[MODULE_ID_MODULE_SERIAL_NUMBER_BYTE4];
            l_work_word = (l_spd_byte4 << 24) | (l_spd_byte3 << 16) | (l_spd_byte2 << 8) | l_spd_byte1;
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_MODULE_ID_MODULE_SERIAL_NUMBER, i_dimm, l_work_word),
                     "Failed to set ATTR_CEN_SPD_MODULE_ID_MODULE_SERIAL_NUMBER");
            FAPI_INF("Set ATTR_CEN_SPD_MODULE_ID_MODULE_SERIAL_NUMBER 0x%X ", l_work_word);

            //MODULE_PART_NUMBER = 329:348
            for (uint16_t l_byte = 0; l_byte < MODULE_PART_NUMBER_LENGTH_IN_BYTES; l_byte++)
            {
                l_module_pn[l_byte] = l_spd[l_byte + MODULE_PART_NUMBER];
            }

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_MODULE_PART_NUMBER, i_dimm, l_module_pn),
                     "Failed to set ATTR_CEN_SPD_MODULE_PART_NUMBER");
            FAPI_INF("Set ATTR_CEN_SPD_MODULE_PART_NUMBER 0x%X ", l_module_pn[0]);


            //MODULE_REVISION_CODE = 349
            l_spd_byte1 = l_spd[MODULE_REVISION_CODE];
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_MODULE_REVISION_CODE_DDR4, i_dimm, l_spd_byte1),
                     "Failed to set ATTR_CEN_SPD_MODULE_REVISION_CODE_DDR4");
            FAPI_INF("Set ATTR_CEN_SPD_MODULE_REVISION_CODE_DDR4 0x%X ", l_spd_byte1);


            //DRAM_MANUFACTURER_JEDEC_ID_CODE_LSB = 350
            //DRAM_MANUFACTURER_JEDEC_ID_CODE_MSB = 351
            l_spd_byte1 = l_spd[DRAM_MANUFACTURER_JEDEC_ID_CODE_LSB];
            l_spd_byte2 = l_spd[DRAM_MANUFACTURER_JEDEC_ID_CODE_MSB];
            l_work_word = (l_spd_byte2 << 8) | l_spd_byte1;
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_DRAM_MANUFACTURER_JEDEC_ID_CODE, i_dimm, l_work_word),
                     "Failed to set ATTR_CEN_SPD_DRAM_MANUFACTURER_JEDEC_ID_CODE");
            FAPI_INF("Set ATTR_CEN_SPD_DRAM_MANUFACTURER_JEDEC_ID_CODE 0x%X ", l_work_word);

            //DRAM_STEPPING_DDR4 = 352
            l_spd_byte1 = l_spd[DRAM_STEPPING_DDR4];
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_DRAM_STEPPING_DDR4, i_dimm, l_spd_byte1),
                     "Failed to set ATTR_CEN_SPD_DRAM_STEPPING_DDR4");
            FAPI_INF("Set ATTR_CEN_SPD_DRAM_STEPPING_DDR4 0x%X ", l_spd_byte1);

            //CRC_MNFG_SEC_DDR4_LSB = 382
            //CRC_MNFG_SEC_DDR4_MSB = 383
            l_spd_byte1 = l_spd[CRC_MNFG_SEC_DDR4_LSB];
            l_spd_byte2 = l_spd[CRC_MNFG_SEC_DDR4_MSB];
            l_work_word = (l_spd_byte2 << 8) | l_spd_byte1;
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_CRC_MNFG_SEC_DDR4, i_dimm, l_work_word),
                     "Failed to set ATTR_CEN_SPD_CRC_MNFG_SEC_DDR4");
            FAPI_INF("Set ATTR_CEN_SPD_CRC_MNFG_SEC_DDR4 0x%X ", l_work_word);

            // Reset ATTR_CEN_SPD_BAD_DQ_DATA
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_CEN_SPD_BAD_DQ_DATA, i_dimm, l_dqData),
                      "Failed to set ATTR_CEN_SPD_BAD_DQ_DATA" );
            FAPI_INF("Set ATTR_CEN_SPD_BAD_DQ_DATA 0x%X ", l_dqData);

        }
        else
        {
            FAPI_INF("DDR3 detected, skipping SPD collection.  Contact lwmulkey@us.ibm.com for more info.");
        }
    }
fapi_try_exit:
    FAPI_INF("End");
    return fapi2::current_err;
}
