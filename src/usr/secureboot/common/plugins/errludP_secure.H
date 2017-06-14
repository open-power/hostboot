/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/common/plugins/errludP_secure.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
#ifndef ERRL_UDP_SECURE_H
#define ERRL_UDP_SECURE_H

/**
 *  @file errludP_secure.H
 *
 *  Defines the ErrlUserDetailsParser classes that parse SECURE FFDC
 */

#include "errluserdetails.H"
#include <string.h>

/**
 * Some macros to manipulate data types cleanly
 */
#define TO_UINT8(ptr)   (*(reinterpret_cast<uint8_t*>(ptr)))
#define TO_UINT32(ptr)  (ntohl(*(reinterpret_cast<uint32_t*>(ptr))))

namespace SECUREBOOT
{
/**
 * Enum defining MAGIC NUMBER used below
 */
enum {
    UDPARSER_SIZEOF_SHA512_t           = 64,
};

/**
 * @class UdParserSystemHwKeyHash
 *
 * Parses UdSystemHwKeyHash
 */
class UdParserSystemHwKeyHash : public ERRORLOG::ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    UdParserSystemHwKeyHash() {}

    /**
     *  @brief Destructor
     */
    virtual ~UdParserSystemHwKeyHash() {}

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
        const char* l_databuf = static_cast<char*>(i_pBuffer);
        i_parser.PrintHeading("System HW Key Hash");

        //***** Memory Layout *****
        // 64 bytes : SHA512_t of System HW Key Hash

        i_parser.PrintHexDump(l_databuf, UDPARSER_SIZEOF_SHA512_t);
        l_databuf += UDPARSER_SIZEOF_SHA512_t;
    }

private:
    // Disabled
    UdParserSystemHwKeyHash(const UdParserSystemHwKeyHash&);
    UdParserSystemHwKeyHash & operator=(const UdParserSystemHwKeyHash&);
};


/**
 * @class UdParserTargetHwKeyHash
 *
 * Parses UdTargetHwKeyHash
 */
class UdParserTargetHwKeyHash : public ERRORLOG::ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    UdParserTargetHwKeyHash() {}

    /**
     *  @brief Destructor
     */
    virtual ~UdParserTargetHwKeyHash() {}

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
        i_parser.PrintHeading("Target HW Key Hash");

        //***** Memory Layout *****
        // 4 bytes  : Target HUID
        // 1 byte   : SBE SEEPROM (Primary or Backup)
        // 64 bytes : SHA512_t of Target HW Key Hash

        i_parser.PrintNumber("Target HUID","%.8lX",TO_UINT32(l_databuf));
        l_databuf += sizeof(uint32_t);

        uint8_t side = TO_UINT8(l_databuf);
        l_databuf += sizeof(uint8_t);

        if( side == 0 )
        {
            i_parser.PrintNumber("SBE_PRIMARY","%.2X",side);
        }
        else if( side == 1 )
        {
            i_parser.PrintNumber("SBE_BACKUP","%.2X",side);
        }
        else
        {
            i_parser.PrintNumber("Unknown SBE","%.2X",side);
        }

        i_parser.PrintHexDump(l_databuf, UDPARSER_SIZEOF_SHA512_t);
        l_databuf += UDPARSER_SIZEOF_SHA512_t;
    }

private:
    // Disabled
    UdParserTargetHwKeyHash(const UdParserTargetHwKeyHash&);
    UdParserTargetHwKeyHash & operator=(const UdParserTargetHwKeyHash&);
};

/**
 * @class UdParserSecuritySettings
 *
 * Parses UdSecuritySettings
 */
class UdParserSecuritySettings : public ERRORLOG::ErrlUserDetailsParser
{
  public:
    /**
     *  @brief Constructor
     */
    UdParserSecuritySettings() {}

    /**
     *  @brief Destructor
     */
    virtual ~UdParserSecuritySettings() {}

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
        //***** Version 1 Memory Layout *****
        // 1 byte   : Secure Access Bit
        // 1 byte   : Security Override
        // 1 byte   : Allow Attribute Overrides

        detailsLayout* l_databuf = static_cast<detailsLayout*>(i_pBuffer);

        i_parser.PrintHeading("Security Settings");
        if (i_version >= 1)
        {
            i_parser.PrintNumber("Secure Access Bit","0x%.2X",
                                 l_databuf->secAccessBit);
            i_parser.PrintNumber("Security Override","0x%.2X",
                                 l_databuf->secOverride);
            i_parser.PrintNumber("Allow Attribute Overrides","0x%.2X",
                                 l_databuf->allowAttrOverride);
        }
    }

  private:
    // Disabled
    UdParserSecuritySettings(const UdParserSecuritySettings&);
    UdParserSecuritySettings & operator=(const UdParserSecuritySettings&);

    // Errl User Details layout
    struct detailsLayout
    {
        uint8_t secAccessBit;
        uint8_t secOverride;
        uint8_t allowAttrOverride;
    };
};



} // end SECUREBOOT namespace

#endif
