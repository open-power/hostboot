/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/i2c/eeprom_const.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
#ifndef __EEPROM_CONST_H
#define __EEPROM_CONST_H

#include <devicefw/driverif.H>
#include <targeting/common/entitypath.H>
#include <string.h>

namespace EEPROM
{

// Hardware OP related consts
constexpr uint16_t EEPROM_PAGE_SIZE = 0x100;
constexpr uint8_t  EEPROM_DEVADDR_INC = 2;
constexpr uint8_t MAX_BYTE_ADDR = 2;
constexpr uint8_t EEPROM_MAX_RETRIES = 2;

// EECACHE OP related consts
constexpr uint8_t  INVALID_EEPROM_INDEX  = 0xFF;
constexpr uint32_t UNSET_INTERNAL_OFFSET_VALUE = 0xFFFFFFFF;
constexpr uint32_t UNSET_END_OF_CACHE_VALUE = UNSET_INTERNAL_OFFSET_VALUE;
constexpr uint8_t  NUM_BYTE_UNIQUE_ID = 12;
constexpr uint8_t  MAX_EEPROMS_VERSION_1 = 50;

/**
 * @brief Enumerations to link EEPROM types to EEPROM's chip number behind
 *        a device
*/
enum EEPROM_ROLE
{
  VPD_PRIMARY   = 0,
  VPD_BACKUP    = 1,
  SBE_PRIMARY   = 2,
  SBE_BACKUP    = 3,
  LAST_CHIP_TYPE,
  // Useful Enums
  INVALID_CHIP_TYPE = LAST_CHIP_TYPE,
  FIRST_CHIP_TYPE = VPD_PRIMARY
};

/**
 * @brief Enumerations to help direct if we want to perform a given op on
 *        the eeprom cache in pnor or the actual hardware. Or if the user
 *        wants the driver to determine if reading from cache is possible, and
 *        if not fall back to doing the op on HW (AUTOSELECT)
*/
enum EEPROM_SOURCE
{
    AUTOSELECT = 0x0000,
    CACHE      = 0x0001,
    HARDWARE   = 0x0002,
};

/**
* @brief Enumerations to describe the type of devices to be accessed.
*/
typedef enum
{
    ZERO_BYTE_ADDR             = 0,
    ONE_BYTE_ADDR_PAGESELECT   = 1,  // page select
    TWO_BYTE_ADDR              = 2,
    ONE_BYTE_ADDR              = 3,
    LAST_DEVICE_TYPE
} eeprom_addr_size_t;

/**
* @brief Enumerations to describe version of the eepromRecordHeader
*        and eecacheSectionHeader structs
*/
enum EECACHE_VERSION
{
    EECACHE_VERSION_UNSET = 0xFF,
    EECACHE_VERSION_1     = 0x01,
    // Useful Enum
    EECACHE_VERSION_LATEST = EECACHE_VERSION_1,
};

/**
* @brief Handy union of two structs which represents the layout
*        of bits to describe a record in the EECACHE ToC. The
*        EECACHE ToC will have room for multiple of these record
*        headers.
*
*        completeRecord is the standard way to access data in the union.
*
*        uniqueRecord is useful if you want to quickly compare the "unique"
*        bits of a header entry which includes the target_huid, port, engine,
*        devAddr, mux_huid, and mux_select.
*
*/
union eepromRecordHeader
{
    struct completeRecord
    {
        uint32_t i2c_master_huid;   // HUID of i2c Master
        uint8_t  port;              // I2C Port
        uint8_t  engine;            // I2C Engine
        uint8_t  devAddr;           // I2C Device Address
        uint8_t  mux_select;        // Some I2C devices are behind a mux, this says
                                    // what setting on the mux is required
        uint32_t cache_copy_size;   // Size of data saved in cache (in KB)
        uint32_t internal_offset;   // offset from start of EECACHE section where cached
                                    // data exists
        uint8_t  cached_copy_valid; // if == 0 , cached data is invalid
    } PACKED completeRecord;

    struct uniqueRecord
    {
        uint8_t uniqueID [NUM_BYTE_UNIQUE_ID];
        uint8_t metaData [sizeof(completeRecord) - NUM_BYTE_UNIQUE_ID];
    } PACKED uniqueRecord;

    inline bool operator<(const eepromRecordHeader& rhs) const{
      return memcmp(this->uniqueRecord.uniqueID, rhs.uniqueRecord.uniqueID, NUM_BYTE_UNIQUE_ID) < 0;
    }

    // Default ctor
    eepromRecordHeader()
    {
        memset(this, 0, sizeof(eepromRecordHeader));
    };

} PACKED;

/**
* @brief Struct which represents the Table of Contents (ToC) for
*        the EECACHE section in pnor
*
*/
struct eecacheSectionHeader
{
    uint8_t version;         // EECACHE_VERSION
    uint32_t end_of_cache;   // End point of the last cache entry
    eepromRecordHeader recordHeaders[MAX_EEPROMS_VERSION_1];
} PACKED ;

/**
 * @brief Structure of common parameters describing a unqiue eeprom.
 *        This is used all over the eeprom code, often functions will
 *        fill in information they know and pass on the struct.
 *
 *        Some functions require fields to be filled in prior to being
 *        passed to said function.
 */
struct eeprom_addr_t
{
    uint64_t port;
    uint64_t engine;
    uint64_t devAddr;
    int64_t  eepromRole;
    uint64_t offset;
    eeprom_addr_size_t addrSize;
    TARGETING::EntityPath i2cMasterPath;
    uint64_t writePageSize;  // in bytes
    uint64_t devSize_KB;     // in kilobytes
    uint64_t chipCount;      // number of chips making up eeprom device
    uint64_t writeCycleTime;  // in milliseconds
    uint8_t i2cMuxBusSelector;
    TARGETING::EntityPath i2cMuxPath;

    /**
     *  @brief Construct a default eeprom_addr_t
     */
    eeprom_addr_t()
        : port(0),
          engine(0),
          devAddr(0),
          eepromRole(INVALID_CHIP_TYPE),
          offset(0),
          addrSize(LAST_DEVICE_TYPE),
          i2cMasterPath(TARGETING::EntityPath::PATH_NA),
          writePageSize(0),
          devSize_KB(0),
          chipCount(0),
          writeCycleTime(0),
          i2cMuxBusSelector(I2C_MUX::NOT_APPLICABLE),
          i2cMuxPath(TARGETING::EntityPath::PATH_NA)
    {
    }
};


/**
 * @brief Define a set of information about all EEPROMs in the
 *        system (primarily used to populate HDAT)
 */
struct EepromInfo_t
{
    TARGETING::Target* i2cMaster; //< I2C Master chip
    uint64_t engine; //< I2C engine (relative to master chip)
    uint64_t port; //< I2C port (relative to engine)
    uint64_t busFreq; //< Bus speed in Hz
    uint64_t devAddr; //< I2C device address (relative to port)
    uint64_t sizeKB; //< Total eeprom size in KB
    uint64_t chipCount; //< Number of chips making up eeprom device
    uint64_t addrBytes; //< Number of bytes required for addressing
    EEPROM_ROLE device; //< Identifies role of eeprom
    TARGETING::Target* assocTarg; //< Target associated with this device

    EepromInfo_t()
      : i2cMaster(nullptr),
        engine(0),
        port(0),
        busFreq(0),
        devAddr(0),
        sizeKB(0),
        chipCount(0),
        addrBytes(0),
        device(INVALID_CHIP_TYPE),
        assocTarg(nullptr)
    {
    }
};

}
#endif