/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/plugins/errludP_vpd.H $                           */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2014                   */
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


}

#endif
