/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/plugins/errludstring.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
#ifndef ERRL_UDSTRING_H
#define ERRL_UDSTRING_H

/**
 *  @file errludstring.H
 *
 *  Defines the ErrlUserDetailsParserString class that parser string FFDC
 *  user detail in an error log
 */

#include "errluserdetails.H"
#include <string.h>

namespace ERRORLOG
{

/**
 * @class ErrlUserDetailsString
 *
 * Parses String user detail in an error log
 */
class ErrlUserDetailsParserString : public ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    ErrlUserDetailsParserString() {}

    /**
     *  @brief Destructor
     */
    virtual ~ErrlUserDetailsParserString() {}

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
        const char *outputString = static_cast<const char *>(i_pBuffer);
        for (uint32_t i = 0; i < i_buflen;)
        {
            if (strlen(outputString)) // skip NULLs
            {
                i_parser.PrintString("String data", outputString);
            }
            i += strlen(outputString) + 1;
            outputString += strlen(outputString) + 1;
        }
    }

private:
    // Disabled
    ErrlUserDetailsParserString(const ErrlUserDetailsParserString &);
    ErrlUserDetailsParserString & operator=(
        const ErrlUserDetailsParserString &);
};

}

#endif

