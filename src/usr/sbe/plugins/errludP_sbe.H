/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbe/plugins/errludP_sbe.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2023                        */
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
#ifndef ERRL_UDP_SBE_H
#define ERRL_UDP_SBE_H

/**
 *  @file errludP_sbe.H
 *
 *  Defines the ErrlUserDetailsParser classes that parse SBE FFDC
 */

#include "errluserdetails.H"

namespace SBE
{

/**
 * @class UdParserSbeNoFormat
 *
 */
class UdParserSbeNoFormat : public ERRORLOG::ErrlUserDetailsParser
{
  public:
    /**
     *  @brief Constructor
     */
    UdParserSbeNoFormat() {}

    /**
     *  @brief Destructor
     */
    virtual ~UdParserSbeNoFormat() {}

    /**
     *  @brief Parses string user detail data from an error log
     *
     *  @param  i_version Version of the data
     *  @param  i_parse   ErrlUsrParser object for outputting information
     *  @param  i_pBuffer Pointer to buffer containing detail data
     *  @param  i_buflen  Length of the buffer
     */
    virtual void parse(errlver_t       i_version,
                       ErrlUsrParser & i_parser,
                       void          * i_pBuffer,
                       const uint32_t  i_buflen) const
    {
        i_parser.PrintHeading("SBE Unformatted Data");
        if (i_version >= 0)
        {
            i_parser.PrintHexDump(i_pBuffer, i_buflen);
        }
    }

  private:
    // Disabled
    UdParserSbeNoFormat(const UdParserSbeNoFormat&);
    UdParserSbeNoFormat & operator=(const UdParserSbeNoFormat&);
};

/**
 * @class UdParserSbeMessageCommand
 *
 */
class UdParserSbeMessageCommand : public ERRORLOG::ErrlUserDetailsParser
{
  public:
    /**
     *  @brief Constructor
     */
    UdParserSbeMessageCommand() {}

    /**
     *  @brief Destructor
     */
    virtual ~UdParserSbeMessageCommand() {}

    /**
     *  @brief Parses string user detail data from an error log
     *
     *  @param  i_version Version of the data
     *  @param  i_parse   ErrlUsrParser object for outputting information
     *  @param  i_pBuffer Pointer to buffer containing detail data
     *  @param  i_buflen  Length of the buffer
     */
    virtual void parse(errlver_t       i_version,
                       ErrlUsrParser & i_parser,
                       void          * i_pBuffer,
                       const uint32_t  i_buflen) const
    {

        i_parser.PrintHeading("SBE Message Command Details");
        if (i_version >= 1)
        {
            sbeMessage_t* l_databuf = static_cast<sbeMessage_t*>(i_pBuffer);
            i_parser.PrintNumber("SBE Header Version","0x%.8X",
                    l_databuf->sbeHdr.version);
            i_parser.PrintNumber("SBE Message Size","0x%.8X",
                    l_databuf->sbeHdr.size);
            i_parser.PrintNumber("Sequence ID","0x%.8X",
                    l_databuf->sbeHdr.seqId);
            i_parser.PrintNumber("Command Header Version","0x%.8X",
                    l_databuf->cmdHdr.version);
            i_parser.PrintNumber("Status of Processing","0x%.8X",
                    l_databuf->cmdHdr.status);
            i_parser.PrintNumber("Data Offset","0x%.8X",
                    l_databuf->cmdHdr.dataOffset);
            i_parser.PrintNumber("Data Size","0x%.8X",
                    l_databuf->cmdHdr.dataSize);
            i_parser.PrintNumber("Pass-through Command","0x%.8X",
                    l_databuf->cmdHdr.command);
        }
    }

  private:
    // These are taken from src/include/usr/sbeio/runtime/sbe_msg_passing.H and are used for version 1 of the parser.
    // Notably, the data section of the struct is omitted as it's not used here. See UdParserSbeMessageData for more
    // info.
    // SBE Header at start of SBE Message
    typedef struct sbeHeader
    {
        uint32_t version;        // SBE header version
        uint32_t size;           // Message size (Pass-through cmd or rsp)
        // Size includes SBE and Command Headers
        uint32_t seqId;          // Sequence ID
    } sbeHeader_t;

    // Command Header following SBE Header in SBE Message
    typedef struct cmdHeader
    {
        uint32_t version;        // Command header version
        uint32_t status;         // Status of processing (rsp only)
        uint32_t dataOffset;     // Data offset (cmd or rsp)
        // Offset is from beginning of Command Header
        uint32_t dataSize;       // Data size (cmd or rsp)
        // Size does NOT include ANY Header fields
        uint32_t command;        // Pass-through command
    } cmdHeader_t;

    // SBE Message (Pass-through command or response)
    typedef struct sbeMessage
    {
        sbeHeader_t sbeHdr;              // SBE header
        cmdHeader_t cmdHdr;              // Command header
    } sbeMessage_t;

    // Disabled
    UdParserSbeMessageCommand(const UdParserSbeMessageCommand&);
    UdParserSbeMessageCommand & operator=(const UdParserSbeMessageCommand&);
};

/**
 * @class UdParserSbeMessageData
 *
 */
class UdParserSbeMessageData : public ERRORLOG::ErrlUserDetailsParser
{
  public:
    /**
     *  @brief Constructor
     */
    UdParserSbeMessageData() {}

    /**
     *  @brief Destructor
     */
    virtual ~UdParserSbeMessageData() {}

    /**
     *  @brief Parses string user detail data from an error log
     *
     *  @param  i_version Version of the data
     *  @param  i_parse   ErrlUsrParser object for outputting information
     *  @param  i_pBuffer Pointer to buffer containing detail data
     *  @param  i_buflen  Length of the buffer
     */
    virtual void parse(errlver_t       i_version,
                       ErrlUsrParser & i_parser,
                       void          * i_pBuffer,
                       const uint32_t  i_buflen) const
    {
        // For this parser the version given to the parser is acting as a unique key to trace back
        // from which SBE message header this data originates. By cross-referencing the version in the
        // PEL with the code, readers should be able to tell which message this was for. In an error
        // there isn't any other trustworthy data to use and we don't want the data section grouped
        // with the rest of the header as it could be large enough to be discarded by the error log for
        // space reasons.
        i_parser.PrintHeading("SBE Message Data - See ver+code for hdr");
        if (i_version >= 1)
        {
            i_parser.PrintHexDump(i_pBuffer, i_buflen);
        }
    }

  private:
    // Disabled
    UdParserSbeMessageData(const UdParserSbeMessageData&);
    UdParserSbeMessageData & operator=(const UdParserSbeMessageData&);
};
} // end SBE namespace

#endif
