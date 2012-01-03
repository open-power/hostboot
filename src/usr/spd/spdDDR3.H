//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/spd/spdDDR3.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#ifndef __SPDDDR3_H
#define __SPDDDR3_H

/**
 * @file spdDDR3.H
 *
 * @brief Provides the enumerations for the DDR 3 fields to read.
 *
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include "spd.H"

namespace SPD
{

/**
 * @brief Pre-defined lookup table for DDR3 keywords and the
 *      information needed to read that data from the SPD data.
 */
KeywordData ddr3Data[] =
{
    // ----------------------------------------------------------------------------------
    // Bit order for each byte is [7:0] as defined by the JEDEC spec (little endian)
    //
    // Special cases listed below will be handled out of the normal table lookup
    // handler code.
    // ----------------------------------------------------------------------------------
    // Keyword                              offset  size    Use     Bitmsk  Shift
    //                                                      Bitmsk          Number
    // ----------------------------------------------------------------------------------
    { CRC_EXCLUDE,                          0x00,   0x01,   true,   0x80,   0x07, false },
    { SPD_BYTES_TOTAL,                      0x00,   0x01,   true,   0x70,   0x04, false },
    { SPD_BYTES_USED,                       0x00,   0x01,   true,   0x0F,   0x00, false },
    { SPD_MAJOR_REVISION,                   0x01,   0x01,   true,   0xF0,   0x04, false },
    { SPD_MINOR_REVISION,                   0x01,   0x01,   true,   0x0F,   0x00, false },
    { BASIC_MEMORY_TYPE,                    0x02,   0x01,   false,  0x00,   0x00, false },
    { MODULE_TYPE,                          0x03,   0x01,   true,   0x0F,   0x00, false },
    { BANK_ADDRESS_BITS,                    0x04,   0x01,   true,   0x70,   0x04, false },
    { DENSITY,                              0x04,   0x01,   true,   0x0F,   0x00, false },
    { ROW_ADDRESS,                          0x05,   0x01,   true,   0x38,   0x03, false },
    { COL_ADDRESS,                          0x05,   0x01,   true,   0x07,   0x00, false },
    { MODULE_NOMINAL_VOLTAGE,               0x06,   0x01,   true,   0x07,   0x00, false },
    { MODULE_RANKS,                         0x07,   0x01,   true,   0x38,   0x03, false },
    { MODULE_DRAM_WIDTH,                    0x07,   0x01,   true,   0x07,   0x00, false },
    { ECC_BITS,                             0x08,   0x01,   true,   0x18,   0x03, false },
    { MODULE_MEMORY_BUS_WIDTH,              0x08,   0x01,   true,   0x07,   0x00, false },
    { FTB_DIVIDEND,                         0x09,   0x01,   true,   0xF0,   0x04, false },
    { FTB_DIVISOR,                          0x09,   0x01,   true,   0x0F,   0x00, false },
    { MTB_DIVIDEND,                         0x0a,   0x01,   false,  0x00,   0x00, false },
    { MTB_DIVISOR,                          0x0b,   0x01,   false,  0x00,   0x00, false },
    { TCK_MIN,                              0x0c,   0x01,   false,  0x00,   0x00, false },
    { CAS_LATENCIES_SUPPORTED,              0x0f,   0x02,   true,   0x7F,   0x00, true  },
    { MIN_CAS_LATENCY,                      0x10,   0x01,   false,  0x00,   0x00, false },
    { TWR_MIN,                              0x11,   0x01,   false,  0x00,   0x00, false },
    { TRCD_MIN,                             0x12,   0x01,   false,  0x00,   0x00, false },
    { TRRD_MIN,                             0x13,   0x01,   false,  0x00,   0x00, false },
    { TRP_MIN,                              0x14,   0x01,   false,  0x00,   0x00, false },
    { TRC_MIN,                              0x15,   0x02,   true,   0xF0,   0x04, true  },
    { TRAS_MIN,                             0x15,   0x02,   true,   0x0F,   0x00, true  },
    { TRFC_MIN,                             0x19,   0x02,   false,  0x00,   0x00, true  },
    { TWTR_MIN,                             0x1a,   0x01,   false,  0x00,   0x00, false },
    { TRTP_MIN,                             0x1b,   0x01,   false,  0x00,   0x00, false },
    { TFAW_MIN,                             0x1c,   0x02,   true,   0x0F,   0x00, true  },
    { DLL_OFF,                              0x1e,   0x01,   true,   0x80,   0x07, false },
    { RZQ_7,                                0x1e,   0x01,   true,   0x02,   0x01, false },
    { RZQ_6,                                0x1e,   0x01,   true,   0x01,   0x00, false },
    { SDRAM_OPTIONAL_FEATURES,              0x1e,   0x01,   false,  0x00,   0x00, false },
    { PASR,                                 0x1f,   0x01,   true,   0x80,   0x07, false },
    { ODTS,                                 0x1f,   0x01,   true,   0x08,   0x03, false },
    { ASR,                                  0x1f,   0x01,   true,   0x04,   0x02, false },
    { ETR_1X,                               0x1f,   0x01,   true,   0x02,   0x01, false },
    { ETR,                                  0x1f,   0x01,   true,   0x01,   0x00, false },
    { SDRAM_THERMAL_REFRESH_OPTIONS,        0x1f,   0x01,   false,  0x00,   0x00, false },
    { THERMAL_SENSOR_PRESENT,               0x20,   0x01,   true,   0x80,   0x07, false },
    { THERMAL_SENSOR_ACCURACY,              0x20,   0x01,   true,   0x7F,   0x00, false },
    { MODULE_THERMAL_SENSOR,                0x20,   0x01,   false,  0x00,   0x00, false },
    { SDRAM_DEVICE_TYPE_NONSTD,             0x21,   0x01,   true,   0x80,   0x07, false },
    { SDRAM_DEVICE_TYPE,                    0x21,   0x01,   true,   0x7F,   0x00, false },
    { TCKMIN_FINE_OFFSET,                   0x22,   0x01,   false,  0x00,   0x00, false },
    { TAAMIN_FINE_OFFSET,                   0x23,   0x01,   false,  0x00,   0x00, false },
    { TRCDMIN_FINE_OFFSET,                  0x24,   0x01,   false,  0x00,   0x00, false },
    { TRPMIN_FINE_OFFSET,                   0x25,   0x01,   false,  0x00,   0x00, false },
    { TRPCMIN_FINE_OFFSET,                  0x26,   0x01,   false,  0x00,   0x00, false },
    { MODULE_TYPE_SPECIFIC_SECTION,         0x3c,   0x39,   false,  0x00,   0x00, false },
    { MODULE_MANUFACTURER_ID,               0x76,   0x02,   false,  0x00,   0x00, true  },
    { MODULE_MANUFACTURING_LOCATION,        0x77,   0x01,   false,  0x00,   0x00, false },
    { MODULE_MANUFACTURING_DATE,            0x78,   0x02,   false,  0x00,   0x00, false },
    { MODULE_SERIAL_NUMBER,                 0x7a,   0x04,   false,  0x00,   0x00, false },
    { MODULE_CRC,                           0x7e,   0x02,   false,  0x00,   0x00, false },
    { MODULE_PART_NUMBER,                   0x80,   0x12,   false,  0x00,   0x00, false },
    { MODULE_REVISION_CODE,                 0x92,   0x02,   false,  0x00,   0x00, false },
    { DRAM_MANUFACTURER_ID,                 0x95,   0x02,   false,  0x00,   0x00, true  },
    { MANUFACTURER_SPECIFIC_DATA,           0x96,   0x1a,   false,  0x00,   0x00, false },
    { DIMM_BAD_DQ_DATA,                     0xb0,   0x50,   false,  0x00,   0x00, false },
    // ----------------------------------------------------------------------------------
};


}; // end SPD namespace

#endif  // __SPDDDR3_H
