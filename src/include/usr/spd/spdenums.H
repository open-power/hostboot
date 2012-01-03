//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/spd/spdenums.H $
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
/**
 * @file spdenums.H
 *
 * @brief Enums for the SPD fields to be requested.
 *
 */
#ifndef __SPDENUMS_H
#define __SPDENUMS_H

namespace SPD
{

/**
* @brief Enumerations for fields that can be accessed in the SPD
*/
enum
{
    SPD_FIRST_KEYWORD                   = 0x00,
    CRC_EXCLUDE                         = SPD_FIRST_KEYWORD,
    SPD_BYTES_TOTAL                     = 0x01,
    SPD_BYTES_USED                      = 0x02,
    SPD_MAJOR_REVISION                  = 0x03,
    SPD_MINOR_REVISION                  = 0x04,
    BASIC_MEMORY_TYPE                   = 0x05,
    MODULE_TYPE                         = 0x06,
    BANK_ADDRESS_BITS                   = 0x07,
    DENSITY                             = 0x08,
    ROW_ADDRESS                         = 0x09,
    COL_ADDRESS                         = 0x0a,
    MODULE_NOMINAL_VOLTAGE              = 0x0b,
    MODULE_RANKS                        = 0x0c,
    MODULE_DRAM_WIDTH                   = 0x0d,
    ECC_BITS                            = 0x0e,
    MODULE_MEMORY_BUS_WIDTH             = 0x0f,
    FTB_DIVIDEND                        = 0x10,
    FTB_DIVISOR                         = 0x11,
    MTB_DIVIDEND                        = 0x12,
    MTB_DIVISOR                         = 0x13,
    TCK_MIN                             = 0x14,
    CAS_LATENCIES_SUPPORTED             = 0x15,
    MIN_CAS_LATENCY                     = 0x16,
    TWR_MIN                             = 0x17,
    TRCD_MIN                            = 0x18,
    TRRD_MIN                            = 0x19,
    TRP_MIN                             = 0x1a,
    TRC_MIN                             = 0x1b,
    TRAS_MIN                            = 0x1c,
    TRFC_MIN                            = 0x1d,
    TWTR_MIN                            = 0x1e,
    TRTP_MIN                            = 0x1f,
    TFAW_MIN                            = 0x20,
    DLL_OFF                             = 0x21,
    RZQ_7                               = 0x22,
    RZQ_6                               = 0x23,
    PASR                                = 0x24,
    ODTS                                = 0x25,
    ASR                                 = 0x26,
    ETR_1X                              = 0x27,
    ETR                                 = 0x28,
    THERMAL_SENSOR_PRESENT              = 0x29,
    THERMAL_SENSOR_ACCURACY             = 0x2a,
    SDRAM_DEVICE_TYPE_NONSTD            = 0x2b,
    SDRAM_DEVICE_TYPE                   = 0x2c,
    MODULE_TYPE_SPECIFIC_SECTION        = 0x2d,
    MODULE_MANUFACTURER_ID              = 0x2e,
    MODULE_MANUFACTURING_LOCATION       = 0x2f,
    MODULE_MANUFACTURING_DATE           = 0x30,
    MODULE_SERIAL_NUMBER                = 0x31,
    MODULE_CRC                          = 0x32,
    MODULE_PART_NUMBER                  = 0x33,
    MODULE_REVISION_CODE                = 0x34,
    DRAM_MANUFACTURER_ID                = 0x35,
    MANUFACTURER_SPECIFIC_DATA          = 0x36,
    TCKMIN_FINE_OFFSET                  = 0x37,
    TAAMIN_FINE_OFFSET                  = 0x38,
    TRCDMIN_FINE_OFFSET                 = 0x39,
    TRPMIN_FINE_OFFSET                  = 0x3a,
    TRPCMIN_FINE_OFFSET                 = 0x3b,
    MODULE_THERMAL_SENSOR               = 0x3c,
    SDRAM_OPTIONAL_FEATURES             = 0x3d,
    SDRAM_THERMAL_REFRESH_OPTIONS       = 0x3e,

    // This keyword should be last in the list
    SPD_LAST_KEYWORD,

    // Invalid Keyword
    INVALID_SPD_KEYWORD                 = 0xFFFF,
};

};  // end SPD

#endif
