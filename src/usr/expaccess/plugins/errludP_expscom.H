/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/expaccess/plugins/errludP_expscom.H $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
#ifndef ERRL_UDP_EXPSCOM_H
#define ERRL_UDP_EXPSCOM_H

/**
 *  @file errludP_expscom.H
 *  Defines the ErrlUserDetailsParser classes that parse EXPSCOM FFDC
 */

#include "errluserdetails.H"
#include <string.h>

#define TO_UINT16(ptr)  (ntohs(*(reinterpret_cast<uint16_t*>(ptr))))
#define TO_UINT32(ptr)  (ntohl(*(reinterpret_cast<uint32_t*>(ptr))))

namespace EXPSCOM
{

/**
 * @brief Header data of every explorer error log section
 */
typedef struct __attribute__((packed))
{
    uint16_t packet_num;      // ordering byte (0 = first packet)
    uint32_t offset_exp_log;  // offset where data portion started in full explorer log
    uint16_t error_data_size; // size of data portion following header
} explog_section_header_t;

/**
 * @class UdParserExpActiveErrorLog
 *
 * Parses user-data sections for Explorer's Active logs
 */
class UdParserExpActiveLog : public ERRORLOG::ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    UdParserExpActiveLog() {}

    /**
     *  @brief Destructor
     */
    virtual ~UdParserExpActiveLog() {}

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
        explog_section_header_t * pHeader = reinterpret_cast<explog_section_header_t *>(i_pBuffer);
        i_parser.PrintHeading("Explorer Active (RAM) Log Data");
        i_parser.PrintNumber("Order packet", "%d", TO_UINT16(&(pHeader->packet_num)));
        i_parser.PrintNumber("Data starting offset", "0x%.8lX", TO_UINT32(&(pHeader->offset_exp_log)));
        i_parser.PrintNumber("Size of data section", "0x%.4lX", TO_UINT16(&(pHeader->error_data_size)));
        i_parser.PrintBlank();
        uint16_t errorDataSize = TO_UINT16(&(pHeader->error_data_size));
        if (errorDataSize <= (i_buflen - sizeof(explog_section_header_t)))
        {
            char * l_trace_error_data = static_cast<char*>(i_pBuffer) + sizeof(explog_section_header_t);
            i_parser.PrintHexDump(l_trace_error_data, errorDataSize);
        }
        else
        {
            i_parser.PrintHeading("ERROR DATA MISSING -- printing entire section in hex");
            i_parser.PrintNumber("Expected data size", "0x%.4lX", i_buflen - sizeof(explog_section_header_t));
            i_parser.PrintHexDump(i_pBuffer, i_buflen);
        }

    }

    // Disabled
    UdParserExpActiveLog(const UdParserExpActiveLog&) = delete;
    UdParserExpActiveLog & operator=(const UdParserExpActiveLog&) = delete;
};

/**
 * @class UdParserExpSavedErrorLogA
 *
 * Parses user-data sections for Explorer's Saved logs for image A side
 */
class UdParserExpSavedLogA : public ERRORLOG::ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    UdParserExpSavedLogA() {}

    /**
     *  @brief Destructor
     */
    virtual ~UdParserExpSavedLogA() {}

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
        explog_section_header_t * pHeader = reinterpret_cast<explog_section_header_t *>(i_pBuffer);
        i_parser.PrintHeading("Explorer Saved (SPI flash) Log Data - Image A");
        i_parser.PrintNumber("Order packet", "%d", TO_UINT16(&(pHeader->packet_num)));
        i_parser.PrintNumber("Data starting offset", "0x%.8lX", TO_UINT32(&(pHeader->offset_exp_log)));
        i_parser.PrintNumber("Size of data section", "0x%.4lX", TO_UINT16(&(pHeader->error_data_size)));
        i_parser.PrintBlank();
        uint16_t errorDataSize = TO_UINT16(&pHeader->error_data_size);
        if (errorDataSize <= (i_buflen - sizeof(explog_section_header_t)))
        {
            char * l_trace_error_data = static_cast<char*>(i_pBuffer) + sizeof(explog_section_header_t);
            i_parser.PrintHexDump(l_trace_error_data, errorDataSize);
        }
        else
        {
            i_parser.PrintHeading("ERROR DATA MISSING -- printing entire section in hex");
            i_parser.PrintNumber("Expected data size", "0x%.4lX", i_buflen - sizeof(explog_section_header_t));
            i_parser.PrintHexDump(i_pBuffer, i_buflen);
        }
    }

    // Disabled
    UdParserExpSavedLogA(const UdParserExpSavedLogA&) = delete;
    UdParserExpSavedLogA & operator=(const UdParserExpSavedLogA&) = delete;
};

/**
 * @class UdParserExpSavedErrorLogB
 *
 * Parses user-data sections for Explorer's Saved logs for image B side
 */
class UdParserExpSavedLogB : public ERRORLOG::ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    UdParserExpSavedLogB() {}

    /**
     *  @brief Destructor
     */
    virtual ~UdParserExpSavedLogB() {}

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
        explog_section_header_t * pHeader = reinterpret_cast<explog_section_header_t *>(i_pBuffer);
        i_parser.PrintHeading("Explorer Saved (SPI flash) Log Data - Image B");
        i_parser.PrintNumber("Order packet", "%d", TO_UINT16(&(pHeader->packet_num)));
        i_parser.PrintNumber("Data starting offset", "0x%.8lX", TO_UINT32(&(pHeader->offset_exp_log)));
        i_parser.PrintNumber("Size of data section", "0x%.4lX", TO_UINT16(&(pHeader->error_data_size)));
        i_parser.PrintBlank();
        uint16_t errorDataSize = TO_UINT16(&pHeader->error_data_size);
        if (errorDataSize <= (i_buflen - sizeof(explog_section_header_t)))
        {
            char * l_trace_error_data = static_cast<char*>(i_pBuffer) + sizeof(explog_section_header_t);
            i_parser.PrintHexDump(l_trace_error_data, errorDataSize);
        }
        else
        {
            i_parser.PrintHeading("ERROR DATA MISSING -- printing entire section in hex");
            i_parser.PrintNumber("Expected data size", "0x%.4lX", i_buflen - sizeof(explog_section_header_t));
            i_parser.PrintHexDump(i_pBuffer, i_buflen);
        }
    }

    // Disabled
    UdParserExpSavedLogB(const UdParserExpSavedLogB&) = delete;
    UdParserExpSavedLogB & operator=(const UdParserExpSavedLogB&) = delete;
};

} // end EXPSCOM namespace

#endif
