//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/hwpf/plat/fapiPlatUdParserHwp.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
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

namespace fapi
{

/**
 * @class PlatUserDetailsParserHwpTarget
 *
 * Parses HWP target string user detail in an error log.
 */
class PlatUserDetailsParserHwpTarget : public ERRORLOG::ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    PlatUserDetailsParserHwpTarget() {}

    /**
     *  @brief Destructor
     */
    virtual ~PlatUserDetailsParserHwpTarget() {}

    /**
     *  @brief Parses HWP target string user detail in an error log.
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
        i_parser.PrintString("Target ecmd string", static_cast<char *>(i_pBuffer));
    }

private:
    // Disabled
    PlatUserDetailsParserHwpTarget(const PlatUserDetailsParserHwpTarget &);
    PlatUserDetailsParserHwpTarget & operator=(
        const PlatUserDetailsParserHwpTarget &);
};

/**
 * @class PlatUserDetailsParserHwpEcmddbb
 *
 * Parses HWP ecmdDataBufferBase user detail in an error log.
*/
class PlatUserDetailsParserHwpEcmddbb : public ERRORLOG::ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    PlatUserDetailsParserHwpEcmddbb() {}

    /**
     *  @brief Destructor
     */
    virtual ~PlatUserDetailsParserHwpEcmddbb() {}

    /**
     *  @brief Parses HWP ecmdDataBufferBase user detail in an error log.
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
        i_parser.PrintString("ecmd data buffer data", NULL);
        i_parser.PrintHexDump(i_pBuffer, i_buflen);
    }

private:
    // Disabled
    PlatUserDetailsParserHwpEcmddbb(const PlatUserDetailsParserHwpEcmddbb &);
    PlatUserDetailsParserHwpEcmddbb & operator=(
        const PlatUserDetailsParserHwpEcmddbb &);
};

/**
 * @class PlatUserDetailsParserHwpData
 *
 * Parses HWP raw data user detail in an error log.
*/
class PlatUserDetailsParserHwpData : public ERRORLOG::ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    PlatUserDetailsParserHwpData() {}

    /**
     *  @brief Destructor
     */
    virtual ~PlatUserDetailsParserHwpData() {}

    /**
     *  @brief Parses HWP raw data user detail in an error log.
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
        i_parser.PrintString("HWP FFDC data", NULL);
        i_parser.PrintHexDump(i_pBuffer, i_buflen);
    }

private:
    // Disabled
    PlatUserDetailsParserHwpData(const PlatUserDetailsParserHwpData &);
    PlatUserDetailsParserHwpData & operator=(
        const PlatUserDetailsParserHwpData &);
};

}

#endif
#endif

