/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/i2c/eepromCache_const.H $                     */
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
#ifndef EEPROM_CACHE_CONST_H
#define __EEPROM_CACHE_CONST_H

constexpr uint8_t MAX_EEPROMS_VERSION_1 = 50;
constexpr uint8_t INVALID_EEPROM_INDEX  = 0xFF;
constexpr uint32_t UNSET_INTERNAL_OFFSET_VALUE = 0xFFFFFFFF;
constexpr uint32_t UNSET_END_OF_CACHE_VALUE = UNSET_INTERNAL_OFFSET_VALUE;

enum EECACHE_VERSION
{
    EECACHE_VERSION_UNSET   = 0xFF,
    EECACHE_VERSION_1       = 0x01,
    EECACHE_VERSION_LATEST  = EECACHE_VERSION_1,
};

enum EEPROM_ATTRIBUTE_MASK : uint8_t
{
  HAS_EEPROM_NV_INFO           = 0x01,
  HAS_EEPROM_SBE_BACKUP_INFO   = 0x02,
  HAS_EEPROM_SBE_PRIMARY_INFO  = 0x04,
  HAS_EEPROM_VPD_BACKUP_INFO   = 0x08,
  HAS_EEPROM_VPD_PRIMARY_INFO  = 0x10,
};


struct eepromRecordHeader
{
    uint32_t target_huid;
    uint8_t  port;
    uint8_t  engine;
    uint8_t  devAddr;
    uint32_t mux_huid;
    uint8_t  mux_select;
    uint32_t record_size;
    uint32_t internal_offset;
    uint8_t  record_valid;
} PACKED ;
                                                                    //record_size      // internal_offset //record_valid
constexpr size_t RECORD_COMPARE_SIZE = sizeof(eepromRecordHeader) - sizeof(uint32_t) - sizeof(uint32_t) - sizeof(uint8_t);

struct eecacheSectionHeader
{
    uint8_t version;
    uint32_t end_of_cache;
    eepromRecordHeader recordHeaders[MAX_EEPROMS_VERSION_1];
} PACKED ;


#endif