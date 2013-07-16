/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/runtime/plugins/errludP_hdat.H $                      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
#ifndef ERRL_UDP_NACA_H
#define ERRL_UDP_NACA_H

/**
 *  @file errludstring.H
 *
 *  Defines the ErrlUserDetailsParserString class that parser string FFDC
 *  user detail in an error log
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

namespace RUNTIME
{

/**
 * @class UdParserNaca
 *
 * Parses NACA user detail in an error log
 */
class UdParserNaca : public ERRORLOG::ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    UdParserNaca() {}

    /**
     *  @brief Destructor
     */
    virtual ~UdParserNaca() {}

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
        i_parser.PrintHeading("NACA");
        i_parser.PrintBlank();

        // Dump the whole thing first
        i_parser.PrintHexDump(i_pBuffer,i_buflen);
        i_parser.PrintBlank();

        char* tmp = NULL;
        // 0x0000 Spira-H offset (if non-zero)
        if( i_buflen >= 8 )
        {
            tmp = static_cast<char *>(i_pBuffer) + 0x0000;
            i_parser.PrintNumber("SPIRA-H","%.16llX",TO_UINT64(tmp));
        }
        // 0x0030 Legacy SPIRA offset
        if( i_buflen >= 0x0038 )
        {
            tmp = static_cast<char *>(i_pBuffer) + 0x0030;
            i_parser.PrintNumber("Legacy Spira","%.16llX",TO_UINT64(tmp));
        }
        // 0x00A0 Actual Legacy SPIRA size in bytes
        if( i_buflen >= 0x00A4 )
        {
            tmp = static_cast<char *>(i_pBuffer) + 0x00A0;
            i_parser.PrintNumber("Legacy SPIRA size","%.8X",TO_UINT32(tmp));
        }
        // 0x01B7 PHYP supports PCIA format
        if( i_buflen >= 0x01B8 )
        {
            tmp = static_cast<char *>(i_pBuffer) + 0x01B7;
            i_parser.PrintNumber("Legacy Spira","%.16llX",TO_UINT8(tmp));
        }
    }

private:
    // Disabled
    UdParserNaca(const UdParserNaca&);
    UdParserNaca & operator=(const UdParserNaca&);
};

/**
 * @class UdParserTuple
 *
 * Parses Tuple user detail in an error log
 */
class UdParserTuple : public ERRORLOG::ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    UdParserTuple() {}

    /**
     *  @brief Destructor
     */
    virtual ~UdParserTuple() {}

    /**
     * @brief Helper function to do parsing
     *
     *  @param  i_parser  ErrlUsrParser object for outputting information
     *  @param  i_pBuffer Pointer to buffer containing detail data
     */
    static void parse( ErrlUsrParser & i_parser,
                       void * i_pBuffer )
    {
        char* tmp = NULL;

        // 0x0000  Absolute address to a structure
        tmp = static_cast<char *>(i_pBuffer) + 0x0000;
        i_parser.PrintNumber("Address","%.16llX",TO_UINT64(tmp));

        // 0x0008  Allocated count
        tmp = static_cast<char *>(i_pBuffer) + 0x0008;
        i_parser.PrintNumber("Allocated Count","%.4X",TO_UINT16(tmp));

        // 0x000A  Actual count
        tmp = static_cast<char *>(i_pBuffer) + 0x000A;
        i_parser.PrintNumber("Actual Count","%.4X",TO_UINT16(tmp));

        // 0x000C  Allocated size in bytes
        tmp = static_cast<char *>(i_pBuffer) + 0x000C;
        i_parser.PrintNumber("Allocated Size","%.8X",TO_UINT32(tmp));

        // 0x0010  Actual size in bytes
        tmp = static_cast<char *>(i_pBuffer) + 0x0010;
        i_parser.PrintNumber("Actual Size","%.8X",TO_UINT32(tmp));

    }

    /**
     *  @brief Parses string user detail data from an error log
     *
     *  @param  i_version Version of the data
     *  @param  i_parser  ErrlUsrParser object for outputting information
     *  @param  i_pBuffer Pointer to buffer containing detail data
     *  @param  i_buflen  Length of the buffer
     */
    virtual void parse(errlver_t i_version,
                       ErrlUsrParser & i_parser,
                       void * i_pBuffer,
                       const uint32_t i_buflen) const
    {
        i_parser.PrintHeading("Tuple");
        i_parser.PrintBlank();

        // Dump the whole thing first
        i_parser.PrintHexDump(i_pBuffer,i_buflen);
        i_parser.PrintBlank();

        if( i_buflen >= 0x0020 )
        {
            UdParserTuple::parse( i_parser, i_pBuffer );
        }
    }

private:
    // Disabled
    UdParserTuple(const UdParserTuple&);
    UdParserTuple & operator=(const UdParserTuple &);
};

/**
 * @class UdParserSpira
 *
 * Parses SPIRA user detail in an error log
 */
class UdParserSpira : public ERRORLOG::ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    UdParserSpira() {}

    /**
     *  @brief Destructor
     */
    virtual ~UdParserSpira() {}

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
        i_parser.PrintHeading("SPIRA");
        i_parser.PrintBlank();

        // Dump the whole thing first
        i_parser.PrintHexDump(i_pBuffer,i_buflen);
        i_parser.PrintBlank();

        char* tmp = NULL;
        //** 0x0000 Common HDIF header
        // 0x0002 Structure eye catcher
        if( i_buflen >= 0x0008 )
        {
            tmp = static_cast<char *>(i_pBuffer) + 0x0002;
            char tmp1[7];
            tmp1[6] = '\0';
            memcpy( tmp1, tmp, 6 );
            i_parser.PrintString("Eyecatcher",tmp1);
        }
        // 0x000A Structure version
        if( i_buflen >= 0x000C )
        {
            tmp = static_cast<char *>(i_pBuffer) + 0x000A;
            i_parser.PrintNumber("Version","%.8X",TO_UINT32(tmp));
        }

        //** 0x0030 Info on 5-tuple array
        // 0x0004 Number of array entries
        uint32_t num_tuples = 0;
        if( i_buflen >= 0x0038 )
        {
            tmp = static_cast<char *>(i_pBuffer) + 0x0034;
            num_tuples = TO_UINT32(tmp);
            i_parser.PrintNumber("Num Tuples","%.8X",num_tuples);
        }

        //** 0x0040 5-tuple arrays
        for( uint32_t tuple = 0;
             tuple < num_tuples;
             tuple++ )
        {
            i_parser.PrintNumber("  Tuple#","%d",tuple);
            void* tuple_ptr = static_cast<char *>(i_pBuffer)
              + 0x0040 + (tuple * 0x20);
            if( i_buflen < (0x0040 + (tuple * 0x20)) )
            {
                break;
            }

            UdParserTuple::parse( i_parser, tuple_ptr );
        }
    }

private:
    // Disabled
    UdParserSpira(const UdParserSpira&);
    UdParserSpira & operator=(const UdParserSpira&);
};


}

#endif

