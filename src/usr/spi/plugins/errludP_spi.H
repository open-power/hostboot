/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/spi/plugins/errludP_spi.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
#ifndef ERRL_UDP_SPI_H
#define ERRL_UDP_SPI_H

/**
 *  @file errludP_spi.H
 *
 *  Defines the ErrlUserDetailsParser classes that parse SPI FFDC
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

namespace SPI
{

/**
 * @class UdParserSpiEepromParameters
 *
 * Parses UdSpiEepromParameters
 */
class UdParserSpiEepromParameters : public ERRORLOG::ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    UdParserSpiEepromParameters() {}

    /**
     *  @brief Destructor
     */
    virtual ~UdParserSpiEepromParameters() {}

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
        i_parser.PrintHeading("SPI EEPROM Parameters");

        // Keep this backwards compatible
        if (i_version >= SPI_UDT_VERSION_1 )
        {

            //***** Memory Layout *****
            // 1 byte   : Op Type (DeviceFW::OperationType)
            // 4 bytes  : Controller Target HUID
            // 8 bytes  : Access Type (DeviceFW::AccessType)
            // 1 byte   : Engine
            // 8 bytes  : Offset
            // 8 bytes  : Length of In/Out Buffer
            // 8 bytes  : Adjusted Offset (to align request)
            // 8 bytes  : Adjusted Length of internal Buffer (to align request)
            // 1 byte   : Start index in adjusted buffer where requested data starts
            // 1 byte   : 1 : Adjusted Buffer used, 0: Adjusted Buffer unused

            uint8_t op = TO_UINT8(l_databuf);
            // Keep this check in sync with DeviceFW::OperationType values
            if( op == 0 )
            {
                i_parser.PrintHeading("SPI Read");
            }
            else if( op == 1 )
            {
                i_parser.PrintHeading("SPI Write");
            }
            else
            {
                i_parser.PrintHeading("Unknown SPI Operation");
            }
            i_parser.PrintNumber("Op Type Value","%.2lX", op);
            l_databuf += sizeof(uint8_t);

            i_parser.PrintNumber("Controller Target HUID","%.8lX",TO_UINT32(l_databuf));
            l_databuf += sizeof(uint32_t);

            i_parser.PrintNumber("Access Type","%.16llX",TO_UINT64(l_databuf));
            l_databuf += sizeof(uint64_t);

            i_parser.PrintNumber("Engine","%.2lX",TO_UINT8(l_databuf));
            l_databuf += sizeof(uint8_t);

            i_parser.PrintNumber("Offset","%.16llX",TO_UINT64(l_databuf));
            l_databuf += sizeof(uint64_t);

            i_parser.PrintNumber("Length I/O Buff","%.16llX",TO_UINT64(l_databuf));
            l_databuf += sizeof(uint64_t);

            i_parser.PrintNumber("Adjusted Offset","%.16llX",TO_UINT64(l_databuf));
            l_databuf += sizeof(uint64_t);

            i_parser.PrintNumber("Adjusted Length","%.16llX",TO_UINT64(l_databuf));
            l_databuf += sizeof(uint64_t);

            i_parser.PrintNumber("Start Index","%.2lX",TO_UINT8(l_databuf));
            l_databuf += sizeof(uint8_t);

            i_parser.PrintNumber("Adjusted Buffer Used","%.2lX",
                                 TO_UINT8(l_databuf));
            l_databuf += sizeof(uint8_t);
        }
        else
        {
            i_parser.PrintHeading("Unknown Version - hexdump:");
            i_parser.PrintNumber("Parser Version", "0x%X", i_version);
            i_parser.PrintHexDump(i_pBuffer, i_buflen);
        }
    }

private:
    // Disabled
    UdParserSpiEepromParameters(const UdParserSpiEepromParameters&);
    UdParserSpiEepromParameters & operator=(const UdParserSpiEepromParameters&);
};

/**
 * @class UdParserSpiTpmParameters
 *
 * Parses UdSpiTpmParameters
 */
class UdParserSpiTpmParameters : public ERRORLOG::ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    UdParserSpiTpmParameters() {}

    /**
     *  @brief Destructor
     */
    virtual ~UdParserSpiTpmParameters() {}

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
        i_parser.PrintHeading("SPI TPM Parameters");

        // maintain backwards compatibility but allow for new versions
        if ( i_version >= SPI_UDT_VERSION_1 )
        {
            //***** Memory Layout *****
            // 1 byte   : Op Type (DeviceFW::OperationType)
            // 4 bytes  : Controller Target HUID
            // 8 bytes  : Access Type (DeviceFW::AccessType)
            // 1 byte   : Engine
            // 8 bytes  : Offset
            // 4 bytes  : Locality
            // 4 bytes  : TPM HUID

            uint8_t op = TO_UINT8(l_databuf);
            l_databuf += sizeof(uint8_t);

            // Keep this in sync with DeviceFW::OperationType
            if( op == 0 )
            {
                i_parser.PrintHeading("SPI Read");
            }
            else if( op == 1 )
            {
                i_parser.PrintHeading("SPI Write");
            }
            else
            {
                i_parser.PrintHeading("Unknown SPI Operation");
            }
            i_parser.PrintNumber("Op Type Value","%.2lX", op);


            i_parser.PrintNumber("Controller Target HUID","%.8lX",TO_UINT32(l_databuf));
            l_databuf += sizeof(uint32_t);

            i_parser.PrintNumber("Access Type","%.16llX",TO_UINT64(l_databuf));
            l_databuf += sizeof(uint64_t);

            i_parser.PrintNumber("Engine","%.2lX",TO_UINT8(l_databuf));
            l_databuf += sizeof(uint8_t);

            i_parser.PrintNumber("Offset","%.16llX",TO_UINT64(l_databuf));
            l_databuf += sizeof(uint64_t);

            i_parser.PrintNumber("Locality","%.8lX",TO_UINT32(l_databuf));
            l_databuf += sizeof(uint32_t);

            i_parser.PrintNumber("TPM HUID","%.8lX",TO_UINT32(l_databuf));
            l_databuf += sizeof(uint32_t);
        }
        else
        {
            i_parser.PrintHeading("Unsupported Version - hexdump:");
            i_parser.PrintNumber("Parser Version", "0x%X", i_version);

            i_parser.PrintHexDump(i_pBuffer, i_buflen);
        }
    }

private:
    // Disabled
    UdParserSpiTpmParameters(const UdParserSpiTpmParameters&);
    UdParserSpiTpmParameters & operator=(const UdParserSpiTpmParameters&);
};

} // end SPI namespace

#endif
