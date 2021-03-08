/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/common/plugins/errludP_secure.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2021                        */
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
#include <utilmem.H>

/**
 * Some macros to manipulate data types cleanly
 */
#define TO_UINT8(ptr)   (*(reinterpret_cast<uint8_t*>(ptr)))
#define TO_UINT16(ptr)  (ntohs(*(reinterpret_cast<uint16_t*>(ptr))))
#define TO_UINT32(ptr)  (ntohl(*(reinterpret_cast<uint32_t*>(ptr))))
#define TO_UINT64(ptr)  (ntohll(*(reinterpret_cast<uint64_t*>(ptr))))

namespace SECUREBOOT
{
/**
 * Enum defining MAGIC NUMBER used below
 */
enum {
    UDPARSER_SIZEOF_SHA512_t           = 64,
    UDPARSER_SIZEOF_MAX_VERIFY_IDS     = 50,
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

        //***** Version 1 Memory Layout *****
        // 4 bytes  : Target HUID
        // 1 byte   : SBE SEEPROM (Primary or Backup)
        // 64 bytes : SHA512_t of Target HW Key Hash

        // **** Version 2 Memory Layout ****
        // Append this to the end of Version 1:
        // 1 byte   : Minimum FW Secure Version

        if (i_version >= 1)
        {
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
        if (i_version >= 2)
        {
            i_parser.PrintNumber("SBE FW Secure Version 0x","%.2lX",TO_UINT8(l_databuf));
            l_databuf += sizeof(uint8_t);
        }

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

        // **** Version 2 Memory Layout ****
        // Append this to the end of Version 1:
        // 1 byte   : Minimum FW Secure Version

        // **** Version 3 Memory Layout ****
        // Append this to the end of Version 2:
        // 4 bytes  : Measurement Seeprom Version

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
        if (i_version >= 2)
        {
            i_parser.PrintNumber("Minimum FW Secure Version","0x%.2X",
                                 l_databuf->minSecureVersion);
        }
        if (i_version >= 3)
        {
            i_parser.PrintNumber("Measurement Seeprom Version","0x%.8X",
                                 l_databuf->measurementSeepromVersion);
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
        uint8_t minSecureVersion;
        uint32_t measurementSeepromVersion;
    };
};

/**
 * @class UdParserVerifyInfo
 *
 * Parses UdSecureVerifyInfo
 */
class UdParserVerifyInfo : public ERRORLOG::ErrlUserDetailsParser
{
  public:
    /**
     *  @brief Constructor
     */
    UdParserVerifyInfo() {}

    /**
     *  @brief Destructor
     */
    virtual ~UdParserVerifyInfo() {}

    /**
     *  @brief Parses verify container user detail data from an error log
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
        // 9 bytes Max : Component ID (8 byte string + NULL) use strlen
        // 8 bytes     : Protected Payload Size
        // 4 bytes     : Number of IDs
        // 4*N bytes   : IDs (PNOR id or LidID) multiplied by number of ids
        // 64 bytes    : Measured Hash
        // 64 bytes    : Expected Hash

        // **** Version 2 Memory Layout ****
        // Append this to the end of Version 1:
        // 1 byte      : Minimum FW Secure Version
        // 1 byte      : Input Secure Version
        // 1 byte      : Container Secure Version

        char* l_databuf = static_cast<char*>(i_pBuffer);
        bool l_parseError = false;

        do {
        i_parser.PrintHeading("Secure Verify Info");
        if (i_version >= 1)
        {
            // Component ID
            i_parser.PrintString("Component ID", l_databuf);
            // Skip string plus 1 byte for null termination
            l_databuf += strlen(l_databuf)+1;

            // Number of IDs
            uint64_t l_protectedSize = TO_UINT64(l_databuf);
            i_parser.PrintNumberUint64("Protected Payload Size","0x%016llX",
                                        l_protectedSize);
            l_databuf += sizeof(l_protectedSize);

            // Number of IDs
            uint32_t l_numIds = TO_UINT32(l_databuf);
            i_parser.PrintNumber("Number of IDs","%d", l_numIds);
            l_databuf += sizeof(l_numIds);

            // IDs
            i_parser.PrintHeading("ID(s)");
            for (uint32_t i = 0; i < l_numIds; ++i)
            {
                i_parser.PrintNumber("ID","0x%08lX", TO_UINT32(l_databuf));
                l_databuf += sizeof(uint32_t);
                // In case of bad format, don't go past max size
                if(i >= UDPARSER_SIZEOF_MAX_VERIFY_IDS)
                {
                    l_parseError = true;
                    break;
                }
            }
            // In case of bad format, don't continue to parse section
            if(l_parseError)
            {
                break;
            }

            // Measured Hash
            i_parser.PrintHeading("Measured Hash");
            i_parser.PrintHexDump(l_databuf, UDPARSER_SIZEOF_SHA512_t);
            l_databuf += UDPARSER_SIZEOF_SHA512_t;

            /// Expected Hash
            i_parser.PrintHeading("Expected Hash");
            i_parser.PrintHexDump(l_databuf, UDPARSER_SIZEOF_SHA512_t);
            l_databuf += UDPARSER_SIZEOF_SHA512_t;

        }
        if (i_version >= 2)
        {
            i_parser.PrintNumber("Minimum FW Secure Version 0x","%.2lX",TO_UINT8(l_databuf));
            l_databuf += sizeof(uint8_t);

            i_parser.PrintNumber("Input Secure Version 0x","%.2lX",TO_UINT8(l_databuf));
            l_databuf += sizeof(uint8_t);

            i_parser.PrintNumber("Container Secure Version 0x","%.2lX",TO_UINT8(l_databuf));
            l_databuf += sizeof(uint8_t);
        }

        } while(0);

    }

  private:
    // Disabled
    UdParserVerifyInfo(const UdParserVerifyInfo&);
    UdParserVerifyInfo & operator=(const UdParserVerifyInfo&);
};

/**
 * @class UdParserNodeCommInfo
 *
 * Parses UdSecureNodeCommInfo
 */
class UdParserNodeCommInfo : public ERRORLOG::ErrlUserDetailsParser
{
  public:
    /**
     *  @brief Constructor
     */
    UdParserNodeCommInfo() {}

    /**
     *  @brief Destructor
     */
    virtual ~UdParserNodeCommInfo() {}

    /**
     *  @brief Parses information from Node Communications operation
     *         user detail data from an error log
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

        //***** Node Comm SECURE_UDT_VERSION_1 Memory Layout *****
        // 4 bytes  : Target HUID
        // 8 bytes  : Length of In/Out Buffer
        // 8 bytes  : Access Type (DeviceFW::AccessType)
        // 1 byte   : Op Type (DeviceFW::OperationType)
        // 1 byte   : Mode (XBUS or ABUS)
        // 1 byte   : LinkId
        // 1 byte   : MboxId

        //***** Node Comm SECURE_UDT_VERSION_2 Memory Layout *****
        // 4 bytes  : Target HUID
        // 8 bytes  : Length of In/Out Buffer
        // 8 bytes  : Access Type (DeviceFW::AccessType)
        // 1 byte   : Op Type (DeviceFW::OperationType)
        // 1 byte   : LinkId
        // 1 byte   : MboxId

        char* l_databuf = static_cast<char*>(i_pBuffer);

        do
        {
        i_parser.PrintHeading("Secure Node Comm Info");

        i_parser.PrintNumber("Target HUID 0x","%.8lX",TO_UINT32(l_databuf));
        l_databuf += sizeof(uint32_t);
        i_parser.PrintNumber("Length I/O Buff 0x","%.16lX",TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);
        i_parser.PrintNumber("Access Type 0x","%.16lX",TO_UINT64(l_databuf));
        l_databuf += sizeof(uint64_t);

        uint8_t op = TO_UINT8(l_databuf);
        if( op == 0 )
        {
            i_parser.PrintHeading("Node Comm Read");
        }
        else if( op == 1 )
        {
            i_parser.PrintHeading("Node Comm Write");
        }
        else
        {
            i_parser.PrintHeading("Unknown Node Comm Operation");
        }
        i_parser.PrintNumber("Op Type Value 0x","%.2lX",TO_UINT8(l_databuf));
        l_databuf += sizeof(uint8_t);

        // Mode was removed in SECURE_UDT_VERSION_2
        if(i_version < SECURE_UDT_VERSION_2)
        {
            op = TO_UINT8(l_databuf);
            if( op == 0 )
            {
                i_parser.PrintHeading("Node Comm Mode: XBUS");
            }
            else if( op == 1 )
            {
                i_parser.PrintHeading("Node Comm Mode: ABUS");
            }
            else
            {
                i_parser.PrintHeading("INVALID Node Comm Mode");
            }
            i_parser.PrintNumber("MODE 0x","%.2lX",TO_UINT8(l_databuf));
            l_databuf += sizeof(uint8_t);
        }

        i_parser.PrintNumber("LinkId 0x","%.2lX",TO_UINT8(l_databuf));
        l_databuf += sizeof(uint8_t);
        i_parser.PrintNumber("MboxId 0x","%.2lX",TO_UINT8(l_databuf));
        l_databuf += sizeof(uint8_t);

        } while(0);
    }

  private:
    // Disabled
    UdParserNodeCommInfo(const UdParserNodeCommInfo&);
    UdParserNodeCommInfo & operator=(const UdParserNodeCommInfo&);
};

} // end SECUREBOOT namespace

#endif
