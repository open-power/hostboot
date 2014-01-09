/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/errlud_i2c.C $                                    */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/**
 *  @file errlud_fsi.C
 *
 *  @brief Implementation of classes to log FSI FFDC
 */
#include "errlud_i2c.H"
#include <i2c/i2creasoncodes.H>
#include <i2c/eepromddreasoncodes.H>
#include <devicefw/driverif.H>
#include "eepromdd.H"
#include "i2c.H"

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
    iv_Version = 1;
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


    char * l_pBuf = reinterpret_cast<char *>(
                          reallocUsrBuf(sizeof(uint8_t)*2
                                        +sizeof(uint32_t)
                                        +sizeof(uint64_t)*2
                                        +sizeof(uint8_t)*2
                                        +sizeof(uint64_t)
                                        +sizeof(uint8_t)*3
                                        +sizeof(uint64_t)
                                        +sizeof(uint16_t)
                                        +sizeof(uint64_t)*2 ) );
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

    tmp64 = i_args.timeout_interval;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_args.timeout_count;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

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
UdEepromParms::UdEepromParms( uint8_t i_opType,
                              TARGETING::Target * i_target,
                              uint64_t i_buflen,
                              eeprom_addr_t i_i2cInfo )
{
    // Set up Ud instance variables
    iv_CompId = EEPROM_COMP_ID;
    iv_Version = 1;
    iv_SubSection = EEPROM_UDT_PARAMETERS;

    //***** Memory Layout *****
    // 1 byte   : Op Type Description
    // 1 byte   : Op Type (DeviceFW::OperationType)
    // 4 bytes  : Target HUID
    // 8 bytes  : Length of In/Out Buffer
    // 8 bytes  : Chip
    // 8 bytes  : Offset
    // 8 bytes  : Port
    // 8 bytes  : Engine
    // 8 bytes  : Device Address
    // 1 byte   : Address Size
    // 8 bytes  : Write Page Size
    // 8 bytes  : Device Size (in KB)
    // 8 bytes  : Write Cycle Time

    char * l_pBuf = reinterpret_cast<char *>(
                          reallocUsrBuf(sizeof(uint8_t)*2
                                        +sizeof(uint32_t)
                                        +sizeof(uint64_t)*6
                                        +sizeof(uint8_t)
                                        +sizeof(uint64_t)*3 ));

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

    tmp32 = TARGETING::get_huid(i_target);
    memcpy(l_pBuf, &tmp32, sizeof(tmp32));
    l_pBuf += sizeof(tmp32);

    tmp64 = i_buflen;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_i2cInfo.chip;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_i2cInfo.offset;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_i2cInfo.port;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_i2cInfo.engine;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_i2cInfo.devAddr;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp8 = static_cast<uint8_t>(i_i2cInfo.addrSize);
    memcpy(l_pBuf, &tmp8, sizeof(tmp8));
    l_pBuf += sizeof(tmp8);

    tmp64 = i_i2cInfo.writePageSize;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_i2cInfo.devSize_KB;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

    tmp64 = i_i2cInfo.writeCycleTime;
    memcpy(l_pBuf, &tmp64, sizeof(tmp64));
    l_pBuf += sizeof(tmp64);

}

//------------------------------------------------------------------------------
UdEepromParms::~UdEepromParms()
{

}

} // end EEPROM namespace
