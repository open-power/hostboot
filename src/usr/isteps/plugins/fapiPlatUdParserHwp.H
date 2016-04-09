/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/plugins/fapiPlatUdParserHwp.H $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
#ifndef FAPIPLATUDPARSERHWP_H
#define FAPIPLATUDPARSERHWP_H

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
#include "errluserdetails.H"
//TODO-RTC:151336 #include "platHwpErrParser.H"

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
        //TODO-RTC:151336 fapi2::parseHwpRc(i_parser, i_pBuffer, i_buflen);
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

