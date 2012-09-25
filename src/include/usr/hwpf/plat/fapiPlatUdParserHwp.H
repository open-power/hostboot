/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/plat/fapiPlatUdParserHwp.H $             */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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
#ifndef FAPIPLATUDPARSERHWP_H
#define FAPIPLATUDPARSERHWP_H

#ifdef PARSER

/**
 *  @file fapiPlatUdParserHwp.H
 *
 *  Defines ErrlUserDetailsParser subclasses to parse the different types of HWP
 *  FFDC added as user detail data to an error log.
 *
 *  Note that there are no corresponding ErrlUserDetails subclasses to create
 *  the user detail data because it is created by the platform neutral
 *  fapi::ReturnCode
 */
#include <errl/errluserdetails.H>
#include <fapiPlatHwpErrParser.H>

namespace fapi
{

/**
 * @class PlatUserDetailsParserHwpRcValue
 *
 * Parses the HWP RcValue in an error log.
 */
class PlatUserDetailsParserHwpRcValue : public ERRORLOG::ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    PlatUserDetailsParserHwpRcValue() {}

    /**
     *  @brief Destructor
     */
    virtual ~PlatUserDetailsParserHwpRcValue() {}

    /**
     *  @brief Parses the HWP RcValue in an error log.
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
        // Call a FAPI generated function to parse the return code
        fapiParseHwpRc(i_parser, i_pBuffer, i_buflen);
    }

private:
    // Disabled
    PlatUserDetailsParserHwpRcValue(const PlatUserDetailsParserHwpRcValue &);
    PlatUserDetailsParserHwpRcValue & operator=(
        const PlatUserDetailsParserHwpRcValue &);
};

/**
 * @class PlatUserDetailsParserHwpTarget
 *
 * Parses HWP FFDC in an error log.
 */
class PlatUserDetailsParserHwpFfdc : public ERRORLOG::ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    PlatUserDetailsParserHwpFfdc() {}

    /**
     *  @brief Destructor
     */
    virtual ~PlatUserDetailsParserHwpFfdc() {}

    /**
     *  @brief Parses HWP FFDC in an error log.
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
        // Call a FAPI generated function to parse the FFDC
        fapiParseHwpFfdc(i_parser, i_pBuffer, i_buflen);
    }

private:
    // Disabled
    PlatUserDetailsParserHwpFfdc(const PlatUserDetailsParserHwpFfdc &);
    PlatUserDetailsParserHwpFfdc & operator=(
        const PlatUserDetailsParserHwpFfdc &);
};

}

#endif
#endif

