/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/plugins/errludstring.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2017                        */
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

    // Parser isn't compiled with c++11 in all environments, and therefore
    // "delete" of unused interfaces (like below) is not supported, nor are
    // functions with move semantics

    // Disable compiler provided default functions
    ErrlUserDetailsParserString(
        const ErrlUserDetailsParserString &);
    ErrlUserDetailsParserString & operator=(
        const ErrlUserDetailsParserString &);

};

/**
 * @class ErrlUserDetailsParserStringSet
 *
 * Parses string set user details from an error log
 */
class ErrlUserDetailsParserStringSet : public ErrlUserDetailsParser
{

  public:

    /**
     *  @brief Constructor
     */
    ErrlUserDetailsParserStringSet()
    {
    }

    /**
     *  @brief Destructor
     */
    virtual ~ErrlUserDetailsParserStringSet()
    {
    }

    /**
     *  @brief Parses string set user details data from an error log
     *
     *  @param  i_version Version of the data
     *  @param  i_parse   ErrlUsrParser object for outputting information
     *  @param  i_pBuffer Pointer to buffer containing detail data
     *  @param  i_buflen  Length of the buffer
     */
    virtual void parse(
              errlver_t      i_version,
              ErrlUsrParser& i_parser,
              void*          i_pBuffer,
        const uint32_t       i_buflen) const
    {
        // [Input Buffer Memory Layout]
        //
        // The input buffer contains N sequentially packed pairs of variable
        // length, NULL terminated strings, where each string pair is also
        // sequentially packed and the sum of the lengths of all such pairs
        // exactly equals the input buffer length.  Each string pair is
        // formatted as below, beginning from either the start of the buffer or
        // the end of the previous string pair:
        //
        // Offset  Size  Description
        // =====================================================================
        // 0       Y     NULL terminated description string describing the
        //               significance of the string to follow, Y=strlen(this
        //               string) + length (1) of NULL terminator.
        // Y       Z     NULL terminated FFDC string, where Z=strlen(this
        //               string) + length (1) of NULL terminator.

        const char* pBuf = static_cast<const char*>(i_pBuffer);
        const size_t len = static_cast<size_t>(i_buflen);
        const char* pBufEnd = pBuf + len;
        while(pBuf < pBufEnd)
        {
            const size_t descriptionStringSize = strlen(pBuf) + 1;
            const char* const pDescriptionString = pBuf;
            pBuf += descriptionStringSize;

            const size_t stringSize = strlen(pBuf) + 1;
            const char* const pString = pBuf;
            pBuf += stringSize;

            i_parser.PrintString(pDescriptionString,pString);
        }
    }

  private:

    // Parser isn't compiled with c++11 in all environments, and therefore
    // "delete" of unused interfaces (like below) is not supported, nor are
    // functions with move semantics

    // Disable compiler provided default functions
    ErrlUserDetailsParserStringSet(
        const ErrlUserDetailsParserStringSet&);
    ErrlUserDetailsParserStringSet & operator=(
        const ErrlUserDetailsParserStringSet&);
};

} // End ERRLOG namespace

#endif

