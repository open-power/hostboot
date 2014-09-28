/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/plugins/errludP_vpd.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
#ifndef ERRL_UDP_VPD_H
#define ERRL_UDP_VPD_H

/**
 *  @file errludP_vpd.H
 *
 *  Defines the ErrlUserDetailsParser classes that parse VPD FFDC
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

namespace VPD
{

/**
 * @class UdParserVpdParms
 *
 * Parses UdParserVpdParms
 */
class UdParserVpdParms : public ERRORLOG::ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    UdParserVpdParms() {}

    /**
     *  @brief Destructor
     */
    virtual ~UdParserVpdParms() {}

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
        i_parser.PrintHeading("VPD Parameters");

        //***** Memory Layout *****
        // 1 byte   : Read / Not-Write
        // 4 bytes  : Target HUID
        // 8 bytes  : Length of In/Out Buffer
        // 8 bytes  : Record
        // 8 bytes  : Keyword

        uint8_t op = TO_UINT8(l_databuf);
        l_databuf += sizeof(uint8_t);
        if( op == 1 )
        {
            i_parser.PrintHeading("VPD Read");
        }
        else if( op == 0 )
        {
            i_parser.PrintHeading("VPD Write");
        }
        else
        {
            i_parser.PrintHeading("Unknown VPD Operation");
        }

        i_parser.PrintNumber("Target","%.8lX",TO_UINT32(l_databuf));
        l_databuf += sizeof(uint32_t);
        i_parser.PrintNumber("Length of I/O Buffer","%.16lX",
                             TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);
        i_parser.PrintNumber("Record","%.16lX",TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);
        i_parser.PrintNumber("Keyword","%.16lX",TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);

    }

private:
    // Disabled
    UdParserVpdParms(const UdParserVpdParms&);
    UdParserVpdParms & operator=(const UdParserVpdParms&);
};


/**
 * @class UdParserConfigParms
 *
 * Parses UdParserConfigParms
 */
class UdParserConfigParms : public ERRORLOG::ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    UdParserConfigParms() {}

    /**
     *  @brief Destructor
     */
    virtual ~UdParserConfigParms() {}

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
        i_parser.PrintHeading("VPD Config Parameters");

        //***** Memory Layout *****
        // 4 bytes  : Target HUID
        // 8 bytes  : Record
        // 8 bytes  : Keyword
        // 8 bytes  : Location
        // 8 bytes  : Read PNOR Config
        // 8 bytes  : Read HW Config
        // 8 bytes  : Write PNOR Config
        // 8 bytes  : Write HW Config

        i_parser.PrintNumber("Target","%.8lX",TO_UINT32(l_databuf));
        l_databuf += sizeof(uint32_t);
        i_parser.PrintNumber("Record","%.16lX",TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);
        i_parser.PrintNumber("Keyword","%.16lX",TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);
        i_parser.PrintNumber("Location","%.16lX",TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);
        i_parser.PrintNumber("Read PNOR Config","%.16lX",TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);
        i_parser.PrintNumber("Read HW Config","%.16lX",TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);
        i_parser.PrintNumber("Write PNOR Config","%.16lX",TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);
        i_parser.PrintNumber("Write HW Config","%.16lX",TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);

    }

private:
    // Disabled
    UdParserConfigParms(const UdParserConfigParms&);
    UdParserConfigParms & operator=(const UdParserConfigParms&);
};


}

#endif
