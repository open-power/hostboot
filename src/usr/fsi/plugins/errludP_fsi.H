/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fsi/plugins/errludP_fsi.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
#ifndef ERRL_UDP_FSI_H
#define ERRL_UDP_FSI_H

/**
 *  @file errludP_fsi.H
 *
 *  Defines the ErrlUserDetailsParser classes that parse FSI FFDC
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

namespace FSI
{

/**
 * @class UdParserPresence
 *
 * Parses UdPresence
 */
class UdParserPresence : public ERRORLOG::ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    UdParserPresence() {}

    /**
     *  @brief Destructor
     */
    virtual ~UdParserPresence() {}

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
        i_parser.PrintHeading("FSI Presence");

        //***** Memory Layout *****
        // 4 bytes  : Slave HUID
        // 4 bytes  : Master HUID
        // 1 byte   : FSI_MASTER_TYPE
        // 1 byte   : port
        // 1 byte   : cascade
        // 2 bytes  : flags
        // 4 bytes  : linkid (node+proc+type+port)
        // 2 bytes  : Size of iv_slaves[]
        // 8 bytes  : slave enable Index
        // X bytes  : iv_slaves[]

        i_parser.PrintNumber("Slave","%.8lX",TO_UINT32(l_databuf));
        l_databuf += sizeof(uint32_t);
        i_parser.PrintNumber("Master","%.8lX",TO_UINT32(l_databuf));
        l_databuf += sizeof(uint32_t);
        i_parser.PrintNumber("Type","%.2lX",TO_UINT8(l_databuf));
        l_databuf += sizeof(uint8_t);
        i_parser.PrintNumber("Port","%.2lX",TO_UINT8(l_databuf));
        l_databuf += sizeof(uint8_t);
        i_parser.PrintNumber("Cascade","%.2lX",TO_UINT8(l_databuf));
        l_databuf += sizeof(uint8_t);
        i_parser.PrintNumber("Flags","%.4lX",TO_UINT16(l_databuf));
        l_databuf += sizeof(uint16_t);
        size_t slave_size = TO_UINT16(l_databuf);
        l_databuf += sizeof(uint16_t);
        uint64_t index = TO_UINT64(l_databuf);
        l_databuf += sizeof(uint64_t);
        i_parser.PrintHeading("Detected Slaves");
        char label[12];
        for( size_t mport = 0; mport < slave_size; mport++ )
        {
            if( mport == index )
            {
                sprintf( label, " *Master%d*", mport );
            }
            else
            {
                sprintf( label, " Master%d", mport );
            }

            i_parser.PrintNumber(label,"%.2lX",TO_UINT8(l_databuf));
            l_databuf += sizeof(uint8_t);
        }


    }

private:
    // Disabled
    UdParserPresence(const UdParserPresence&);
    UdParserPresence & operator=(const UdParserPresence&);
};


/**
 * @class UdParserOperation
 *
 * Parses UdOperation
 */
class UdParserOperation : public ERRORLOG::ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    UdParserOperation() {}

    /**
     *  @brief Destructor
     */
    virtual ~UdParserOperation() {}

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

        //***** Memory Layout *****
        // 4 bytes  : Target HUID
        // 8 bytes  : FSI Address
        // 1 byte   : 1=read, 0=write
        uint32_t targ = TO_UINT32(l_databuf);
        l_databuf += sizeof(uint32_t);
        uint64_t addr = TO_UINT64(l_databuf);
        l_databuf += sizeof(uint64_t);
        uint8_t op = TO_UINT8(l_databuf);
        l_databuf += sizeof(uint8_t);

        if( op == 1 )
        {
            i_parser.PrintHeading("FSI Read");
        }
        else if( op == 0 )
        {
            i_parser.PrintHeading("FSI Write");
        }
        else
        {
            i_parser.PrintHeading("Unknown FSI Operation");
        }

        // Print out the memory addresses
        i_parser.PrintNumber("Op Target","%.8lX",targ);
        i_parser.PrintNumber("Address","%.8lX",(uint32_t)addr);//@todo: RTC:81826
    }

private:
    // Disabled
    UdParserOperation(const UdParserOperation&);
    UdParserOperation & operator=(const UdParserOperation&);
};


}

#endif
