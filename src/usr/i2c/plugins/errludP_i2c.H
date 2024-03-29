/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/plugins/errludP_i2c.H $                           */
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
#ifndef ERRL_UDP_I2C_H
#define ERRL_UDP_I2C_H

/**
 *  @file errludP_i2c.H
 *
 *  Defines the ErrlUserDetailsParser classes that parse I2C and EEPROM FFDC
 */

#include "errluserdetails.H"
#include <string.h>

/**
 * Some macros to manipulate data types cleanly
 */
#define TO_UINT8(ptr)   (*(reinterpret_cast<uint8_t*>(ptr)))
#define TO_UINT16(ptr)  (ntohs(*(reinterpret_cast<uint16_t*>(ptr))))
#define TO_UINT32(ptr)  (ntohl(*(reinterpret_cast<uint32_t*>(ptr))))
#define TO_UINT64(ptr)  (ntohll(*(reinterpret_cast<uint64_t*>(ptr))))

namespace I2C
{

/**
 * @class UdParserI2CParms
 *
 * Parses UdI2CParms
 */
class UdParserI2CParms : public ERRORLOG::ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    UdParserI2CParms() {}

    /**
     *  @brief Destructor
     */
    virtual ~UdParserI2CParms() {}

    /**
     *  @brief Parses string user detail data from an error log
     *
     *  @param  i_version Version of the data
     *  @param  i_parse   ErrlUsrParser object for outputting information
     *  @param  i_pBuffer Pointer to buffer containing detail data
     *  @param  i_buflen  Length of the buffer
     */
    virtual void parse(errlver_t i_version,
                       ErrlUsrParser & i_parser,
                       void * i_pBuffer,
                       const uint32_t i_buflen) const
    {
        char* l_databuf = static_cast<char*>(i_pBuffer);
        i_parser.PrintHeading("I2C Parameters");

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
        // 8 bytes  : Polling Interval in ns
        // 8 bytes  : Timeout Count;
        // 1 byte   : I2C MUX Bus Selector
        // N bytes  : I2C MUX path in string form

        uint8_t op = TO_UINT8(l_databuf);
        l_databuf += sizeof(uint8_t);

        if( op == 0 )
        {
            i_parser.PrintHeading("I2C Read");
        }
        else if( op == 1 )
        {
            i_parser.PrintHeading("I2C Write");
        }
        else
        {
            i_parser.PrintHeading("Unknown I2C Operation");
        }

        i_parser.PrintNumber("Op Type Value","%.2lX",TO_UINT8(l_databuf));
        l_databuf += sizeof(uint8_t);
        i_parser.PrintNumber("Target HUID","%.8lX",TO_UINT32(l_databuf));
        l_databuf += sizeof(uint32_t);
        i_parser.PrintNumber("Length I/O Buff","%.16lX",TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);
        i_parser.PrintNumber("Access Type","%.16lX",TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);
        i_parser.PrintNumber("Port","%.2lX",TO_UINT8(l_databuf));
        l_databuf += sizeof(uint8_t);
        i_parser.PrintNumber("Engine","%.2lX",TO_UINT8(l_databuf));
        l_databuf += sizeof(uint8_t);
        i_parser.PrintNumber("Device Address","%.16lX",TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);
        i_parser.PrintNumber("Flag: skip_mode_setup","%.2lX",
                             TO_UINT8(l_databuf));
        l_databuf += sizeof(uint8_t);
        i_parser.PrintNumber("Flag: with_stop","%.2lX",TO_UINT8(l_databuf));
        l_databuf += sizeof(uint8_t);
        i_parser.PrintNumber("Flag: read_not_write","%.2lX",
                             TO_UINT8(l_databuf));
        l_databuf += sizeof(uint8_t);
        i_parser.PrintNumber("Bus Speed (kbits/sec)","%.16lX",
                              TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);
        i_parser.PrintNumber("Bit Rate Divisor","%.4lX",TO_UINT16(l_databuf));
        l_databuf += sizeof(uint16_t);
        i_parser.PrintNumber("Polling Interval (ns)","%.16lX",
                              TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);
        i_parser.PrintNumber("Timeout Count","%.16lX",TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);

        if (i_version >= 2 )
        {
            i_parser.PrintNumber("I2C Mux Selector","%.2lX",TO_UINT8(l_databuf));
            l_databuf += sizeof(uint8_t);
            i_parser.PrintString("I2C Mux Path", l_databuf);
            // Increment past the NULL terminated string + 1 (null terminator)
            l_databuf += strlen(l_databuf) + 1;

        }
    }

private:
    // Disabled
    UdParserI2CParms(const UdParserI2CParms&);
    UdParserI2CParms & operator=(const UdParserI2CParms&);
};

} // end I2C namespace

namespace EEPROM
{

/**
 * @class UdParserEepromI2cParms
 *
 * Parses UdEepromI2cParms
 */
class UdParserEepromI2cParms : public ERRORLOG::ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    UdParserEepromI2cParms() {}

    /**
     *  @brief Destructor
     */
    virtual ~UdParserEepromI2cParms() {}

    /**
     *  @brief Parses string user detail data from an error log
     *
     *  @param  i_version Version of the data
     *  @param  i_parse   ErrlUsrParser object for outputting information
     *  @param  i_pBuffer Pointer to buffer containing detail data
     *  @param  i_buflen  Length of the buffer
     */
    virtual void parse(errlver_t i_version,
                       ErrlUsrParser & i_parser,
                       void * i_pBuffer,
                       const uint32_t i_buflen) const
    {
        char* l_databuf = static_cast<char*>(i_pBuffer);
        i_parser.PrintHeading("EEPROM Parameters");

        //***** Memory Layout *****
        // 1 byte   : Op Type Description
        // 1 byte   : Op Type (DeviceFW::OperationType)
        // 1 byte   : Eeprom access method
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
        // 8 bytes  : Chip Count
        // 8 bytes  : Write Cycle Time
        // 1 byte   : I2C MUX Bus Selector
        // N bytes  : I2C MUX path in string form

        uint8_t op = TO_UINT8(l_databuf);
        l_databuf += sizeof(uint8_t);

        if( op == 0 )
        {
            i_parser.PrintHeading("EEPROM Read");
        }
        else if( op == 1 )
        {
            i_parser.PrintHeading("EEPROM Write");
        }
        else
        {
            i_parser.PrintHeading("Unknown EEPROM Operation");
        }

        i_parser.PrintNumber("Op Type Value","%.2lX",TO_UINT8(l_databuf));
        l_databuf += sizeof(uint8_t);

        if (i_version >= 4 )
        {
            uint8_t opMethod = TO_UINT8(l_databuf);
            if (opMethod == 1)
            {
                i_parser.PrintNumber("EEPROM ACCESS: I2C", "%.2lX", opMethod);
            }
            else if (opMethod == 2)
            {
                i_parser.PrintNumber("EEPROM ACCESS: SPI", "%.2lX", opMethod);
            }
            else
            {
                i_parser.PrintNumber("EEPROM ACCESS: Unknown", "%.2lX", opMethod);
            }
            l_databuf += sizeof(uint8_t);
        }

        i_parser.PrintNumber("Target HUID","%.8lX",TO_UINT32(l_databuf));
        l_databuf += sizeof(uint32_t);
        i_parser.PrintNumber("Length I/O Buff","%.16lX",TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);
        i_parser.PrintNumber("Chip","%.16lX",TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);
        i_parser.PrintNumber("Offset","%.16lX",TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);
        i_parser.PrintNumber("Port","%.16lX",TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);
        i_parser.PrintNumber("Engine","%.16lX",TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);
        i_parser.PrintNumber("Device Address","%.16lX",TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);
        i_parser.PrintNumber("Address Size","%.2lX",TO_UINT8(l_databuf));
        l_databuf += sizeof(uint8_t);
        i_parser.PrintNumber("Write Page Size","%.16lX",TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);
        i_parser.PrintNumber("Device Size (in KB)","%.16lX",
                             TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);
        if(i_version >= 2)
        {
            i_parser.PrintNumber("Chip Count","%.16lX",
                                 TO_UINT64(l_databuf));
            l_databuf += sizeof(uint64_t);
        }
        i_parser.PrintNumber("Write Cycle Time","%.16lX",TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);

        if (i_version >= 3 )
        {
            i_parser.PrintNumber("I2C Mux Selector","%.2lX",TO_UINT8(l_databuf));
            l_databuf += sizeof(uint8_t);
            i_parser.PrintString("I2C Mux Path", l_databuf);
            // Increment past the NULL terminated string + 1 (null terminator)
            l_databuf += (strlen(l_databuf) + 1);
        }
    }

private:
    // Disabled
    UdParserEepromI2cParms(const UdParserEepromI2cParms&);
    UdParserEepromI2cParms & operator=(const UdParserEepromI2cParms&);
};

/**
 * @class UdParserEepromSpiParms
 *
 * Parses UdParserEepromSpiParms
 */
class UdParserEepromSpiParms : public ERRORLOG::ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    UdParserEepromSpiParms() {}

    /**
     *  @brief Destructor
     */
    virtual ~UdParserEepromSpiParms() {}

    /**
     *  @brief Parses string user detail data from an error log
     *
     *  @param  i_version Version of the data
     *  @param  i_parse   ErrlUsrParser object for outputting information
     *  @param  i_pBuffer Pointer to buffer containing detail data
     *  @param  i_buflen  Length of the buffer
     */
    virtual void parse(errlver_t i_version,
                       ErrlUsrParser & i_parser,
                       void * i_pBuffer,
                       const uint32_t i_buflen) const
    {
        char* l_databuf = static_cast<char*>(i_pBuffer);
        i_parser.PrintHeading("EEPROM Parameters");

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
        uint8_t op = TO_UINT8(l_databuf);
        l_databuf += sizeof(uint8_t);

        if( op == 0 )
        {
            i_parser.PrintHeading("EEPROM Read");
        }
        else if( op == 1 )
        {
            i_parser.PrintHeading("EEPROM Write");
        }
        else
        {
            i_parser.PrintHeading("Unknown EEPROM Operation");
        }
        i_parser.PrintNumber("Op Type Value","%.2lX",op);

        uint8_t opMethod = TO_UINT8(l_databuf);
        if (opMethod == 1)
        {
            i_parser.PrintNumber("EEPROM ACCESS: I2C", "%.2lX", opMethod);
        }
        else if (opMethod == 2)
        {
            i_parser.PrintNumber("EEPROM ACCESS: SPI", "%.2lX", opMethod);
        }
        else
        {
            i_parser.PrintNumber("EEPROM ACCESS: Unknown", "%.2lX", opMethod);
        }
        l_databuf += sizeof(uint8_t);

        i_parser.PrintNumber("Target HUID","%.8lX",TO_UINT32(l_databuf));
        l_databuf += sizeof(uint32_t);
        i_parser.PrintNumber("Length I/O Buff","%.16lX",TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);
        i_parser.PrintNumber("eepromRole","%.16lX",TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);
        i_parser.PrintNumber("Offset","%.16lX",TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);
        i_parser.PrintNumber("Device Size (in KB)","%.16lX", TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);
        i_parser.PrintNumber("Start of device data (in KB)","%.16lX",TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);
        i_parser.PrintNumber("SPI Engine","%.2lX",TO_UINT8(l_databuf));
        i_parser.PrintString("SPI Master Path", l_databuf);
        // Increment past the NULL terminated string + 1 (null terminator)
        l_databuf += (strlen(l_databuf) + 1);
    }

private:
    // Disabled
    UdParserEepromSpiParms(const UdParserEepromSpiParms&);
    UdParserEepromSpiParms & operator=(const UdParserEepromSpiParms&);
};

} // end EEPROM NAMESPACE

#endif
