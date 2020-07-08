/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/errlud_i2c.C $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2020                        */
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
/**
 *  @file errlud_i2c.C
 *
 *  @brief Implementation of classes to log i2c FFDC
 */
#include <string.h>     // strlen
#include "errlud_i2c.H"
#include <i2c/i2creasoncodes.H>
#include <eeprom/eepromddreasoncodes.H>
#include <devicefw/driverif.H>
#include <i2c/i2c.H>

namespace I2C
{

//------------------------------------------------------------------------------
//  I2C User Details
//------------------------------------------------------------------------------
UdI2CParms::UdI2CParms( uint8_t i_opType,
                        TARGETING::Target * i_target,
                        uint64_t i_buflen,
                        int64_t i_accessType,
                        misc_args_t i_args  )
{
    // Set up Ud instance variables
    iv_CompId = I2C_COMP_ID;
    iv_Version = 2;
    iv_SubSection = I2C_UDT_PARAMETERS;

    //***** Memory Layout *****
    // 1 byte   : Op Type Description
    // 1 byte   : Op Type (DeviceFW::OperationType)
    // 4 bytes  : Target HUID
    // 8 bytes  : Length of In/Out Buffer
    // 8 bytes  : Access Type (DeviceFW::AccessType)
    // 1 byte   : Port
    // 1 byte   : Engine
    // 8 bytes  : Device Address
    // 1 byte   : Flag: skip_mode_setup;
    // 1 byte   : Flag: with_stop;
    // 1 byte   : Flag: read_not_write;
    // 8 bytes  : Bus Speed (kbits/sec)
    // 2 bytes  : Bit Rate Divisor
    // 8 bytes  : Timeout Interval
    // 8 bytes  : Timeout Count;
    // 1 byte   : I2C MUX Bus Selector
    // N bytes  : I2C MUX path in string form

    // Cache the MUX path in string form for reference and easy access
    char* l_muxPath{nullptr};
    size_t l_muxPathSize = 0;
    if (i_args.i2cMuxPath)
    {
        l_muxPath = i_args.i2cMuxPath->toString();
        if (l_muxPath != nullptr)
        {
            l_muxPathSize = strlen(l_muxPath);
        }
    }
    char * l_pBuf = reinterpret_cast<char *>(
                          reallocUsrBuf(sizeof(uint8_t)*2
                                        +sizeof(uint32_t)
                                        +sizeof(uint64_t)*2
                                        +sizeof(uint8_t)*2
                                        +sizeof(uint64_t)
                                        +sizeof(uint8_t)*3
                                        +sizeof(uint64_t)
                                        +sizeof(uint16_t)
                                        +sizeof(uint64_t)*2
                                        +sizeof(uint8_t)
                                        +l_muxPathSize + 1) );
    uint64_t tmp64 = 0;
    uint32_t tmp32 = 0;
    uint16_t tmp16 = 0;
    uint8_t tmp8 = 0;

    if( i_opType == DeviceFW::READ )
    {
        tmp8 = 0;
    }
    else if( i_opType == DeviceFW::WRITE )
    {
        tmp8 = 1;
    }
    else
    {
        tmp8 = 2;
    }
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    tmp8 = i_opType;
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    tmp32 = TARGETING::get_huid(i_target);
    memcpy(l_pBuf, &tmp32, sizeof(tmp32));
    l_pBuf += sizeof(tmp32);

    tmp64 = i_buflen;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_accessType;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp8 = i_args.port;
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    tmp8 = i_args.engine;
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    tmp64 = i_args.devAddr;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp8 = i_args.skip_mode_setup;
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    tmp8 = i_args.with_stop;
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    tmp8 = i_args.read_not_write;
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    tmp64 = i_args.bus_speed;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp16 = i_args.bit_rate_divisor;
    memcpy(l_pBuf, &tmp16, sizeof(tmp16));
    l_pBuf += sizeof(tmp16);

    tmp64 = i_args.polling_interval_ns;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_args.timeout_count;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    // Begin Version 2 Data
    tmp8 = i_args.i2cMuxBusSelector;
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    if (l_muxPathSize > 0)
    {
        memcpy(l_pBuf, l_muxPath, l_muxPathSize);
        l_pBuf += l_muxPathSize;
    }
    *l_pBuf = '\0';   // add a terminator for ease of parsing
    ++l_pBuf;

    free(l_muxPath);
    l_muxPath = nullptr;
}

//------------------------------------------------------------------------------
UdI2CParms::~UdI2CParms()
{
}

} // end I2C namespace

namespace EEPROM
{


//------------------------------------------------------------------------------
//  EEPROM User Details
//------------------------------------------------------------------------------
UdEepromI2cParms::UdEepromI2cParms( uint8_t i_opType,
                                    TARGETING::Target * i_target,
                                    uint64_t i_buflen,
                                    eeprom_addr_t i_i2cInfo )
{
    // Set up Ud instance variables
    iv_CompId = EEPROM_COMP_ID;
    iv_Version = 4;
    iv_SubSection = EEPROM_UDT_I2C_PARAMETERS;

    //***** Memory Layout *****
    // 1 byte   : Op Type Description
    // 1 byte   : Op Type (DeviceFW::OperationType)
    // 1 byte   : Eeprom access type
    // 4 bytes  : Target HUID
    // 8 bytes  : Length of In/Out Buffer
    // 8 bytes  : eepromRole
    // 8 bytes  : Offset
    // 8 bytes  : Port
    // 8 bytes  : Engine
    // 8 bytes  : Device Address
    // 1 byte   : Address Size
    // 8 bytes  : Write Page Size
    // 8 bytes  : Device Size (in KB)
    // 8 bytes  : Chip Count
    // 8 bytes  : Write Cycle Time
    // 1 byte   : I2C MUX Bus Selector
    // N bytes  : I2C MUX path in string form

    // Cache the MUX path in string form for reference and easy access

    char *l_muxPath;
    if ( i_i2cInfo.accessMethod ==
         EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_I2C )
    {
        l_muxPath = i_i2cInfo.accessAddr.i2c_addr.i2cMuxPath.toString();
    }
    else
    {
        l_muxPath = (char*) malloc(1);
        l_muxPath[0] = '\0';
    }

    char * l_pBuf = reinterpret_cast<char *>(
                          reallocUsrBuf(sizeof(uint8_t)*3
                                        +sizeof(uint32_t)
                                        +sizeof(uint64_t)*6
                                        +sizeof(uint8_t)
                                        +sizeof(uint64_t)*4
                                        +sizeof(uint8_t)
                                        +(strlen(l_muxPath) +1) ) );

    uint64_t tmp64 = 0;
    uint32_t tmp32 = 0;
    uint8_t tmp8 = 0;

    if( i_opType == DeviceFW::READ )
    {
        tmp8 = 0;
    }
    else if( i_opType == DeviceFW::WRITE )
    {
        tmp8 = 1;
    }
    else
    {
        tmp8 = 2;
    }
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    tmp8 = i_opType;
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    ////////////////////////
    // version 4 data
    tmp8 = static_cast<uint8_t>(i_i2cInfo.accessMethod);
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);
    ////////////////////////

    tmp32 = TARGETING::get_huid(i_target);
    memcpy(l_pBuf, &tmp32, sizeof(tmp32));
    l_pBuf += sizeof(tmp32);

    tmp64 = i_buflen;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_i2cInfo.eepromRole;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_i2cInfo.offset;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_i2cInfo.accessAddr.i2c_addr.port;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_i2cInfo.accessAddr.i2c_addr.engine;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_i2cInfo.accessAddr.i2c_addr.devAddr;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp8 = static_cast<uint8_t>(i_i2cInfo.accessAddr.i2c_addr.addrSize);
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    tmp64 = i_i2cInfo.accessAddr.i2c_addr.writePageSize;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_i2cInfo.devSize_KB;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_i2cInfo.accessAddr.i2c_addr.chipCount;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_i2cInfo.accessAddr.i2c_addr.writeCycleTime;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    // Begin Version 3 Data
    tmp8 = i_i2cInfo.accessAddr.i2c_addr.i2cMuxBusSelector;
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    memcpy(l_pBuf, l_muxPath, strlen(l_muxPath));
    l_pBuf += strlen(l_muxPath);
    *l_pBuf = '\0';   // add a terminator for ease of parsing
    ++l_pBuf;

    free(l_muxPath);
    l_muxPath = nullptr;
}


UdEepromI2cParms::~UdEepromI2cParms()
{
}


//------------------------------------------------------------------------------
UdEepromSpiParms::UdEepromSpiParms( uint8_t i_opType,
                                    TARGETING::Target * i_target,
                                    uint64_t i_buflen,
                                    eeprom_addr_t i_spiInfo )
{
    // Set up Ud instance variables
    iv_CompId = EEPROM_COMP_ID;
    iv_Version = 1;
    iv_SubSection = EEPROM_UDT_SPI_PARAMETERS;

    //***** Memory Layout *****
    // 1 byte   : Op Type (DeviceFW::OperationType)
    // 1 byte   : Eeprom access method
    // 4 bytes  : Target HUID
    // 8 bytes  : Length of In/Out Buffer
    // 8 bytes  : eepromRole
    // 8 bytes  : Offset
    // 8 bytes  : devSize_KB
    // 8 bytes  : roleOffset_KB
    // 1 byte   : SPI engine
    // N bytes  : SPI master path
    // Cache the SPI path in string form for reference and easy access

    char *l_masterPath;
    if ( i_spiInfo.accessMethod ==
         EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_SPI )
    {
        l_masterPath = i_spiInfo.accessAddr.spi_addr.spiMasterPath.toString();
    }
    else
    {
        l_masterPath = (char*) malloc(1);
        l_masterPath[0] = '\0';
    }

    char * l_pBuf = reinterpret_cast<char *>(
                          reallocUsrBuf(sizeof(uint8_t)*2
                                        +sizeof(uint32_t)
                                        +sizeof(uint64_t)*5
                                        +sizeof(uint8_t)
                                        +(strlen(l_masterPath)+1) ) );

    uint64_t tmp64 = 0;
    uint32_t tmp32 = 0;
    uint8_t tmp8 = 0;

    tmp8 = i_opType;
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    tmp8 = static_cast<uint8_t>(i_spiInfo.accessMethod);
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    tmp32 = TARGETING::get_huid(i_target);
    memcpy(l_pBuf, &tmp32, sizeof(tmp32));
    l_pBuf += sizeof(tmp32);

    tmp64 = i_buflen;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_spiInfo.eepromRole;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_spiInfo.offset;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_spiInfo.devSize_KB;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_spiInfo.accessAddr.spi_addr.roleOffset_KB;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp8 = i_spiInfo.accessAddr.spi_addr.engine;
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    memcpy(l_pBuf, l_masterPath, strlen(l_masterPath));
    l_pBuf += strlen(l_masterPath);
    *l_pBuf = '\0';   // add a terminator for ease of parsing
    ++l_pBuf;

    free(l_masterPath);
    l_masterPath = nullptr;
}

UdEepromSpiParms::~UdEepromSpiParms()
{
}

} // end EEPROM namespace
