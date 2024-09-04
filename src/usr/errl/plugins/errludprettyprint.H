/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/plugins/errludprettyprint.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2024                             */
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

#ifndef ERRL_UDPRETTYPRINTER_H
#define ERRL_UDPRETTYPRINTER_H
/**
 *  @file errludprettyprint.H
 *
 */

#include "errludprettyprint.H"
#include <string.h>

namespace ERRORLOG
{
class ErrlUserDetailsParserPrettyPrintk : public ErrlUserDetailsParser

{
public:
    /**
     * @brief Constructor
    */
    ErrlUserDetailsParserPrettyPrintk(){}

    /**
     * @brief Destructor
    */
    virtual ~ErrlUserDetailsParserPrettyPrintk(){}

    /**
     *  @brief Parses and converts binary data collected from the printk buffer(0x07) to ascii charcters.
     * Final convreted strings are printed to an error log.
     *
     *  @param  i_version Version of the data
     *  @param  i_parse   ErrlUsrParser object for outputting information
     *  @param  i_pBuffer Pointer to buffer containing detail data
     *  @param  i_buflen  Length of the buffer
    */

    virtual void parse(errlver_t i_version,
                      ErrlUsrParser & i_parser,
                      void * i_pBuffer,
                      const uint32_t  i_buflen) const
    {
        // local variables
        const char *pBuf = static_cast<const char *>(i_pBuffer);
        const size_t len = static_cast<size_t>(i_buflen);     // setting up pointers for looping



        for (uint32_t i =0; i < len;)
        {
            i_parser.PrintString( "Printk User Data", pBuf);
            i += strlen(pBuf)+1;
            pBuf += strlen(pBuf) +1;
        }
    }
private:
    //disabled
    ErrlUserDetailsParserPrettyPrintk(const ErrlUserDetailsParserPrettyPrintk &);
    ErrlUserDetailsParserPrettyPrintk & operator =(
        const ErrlUserDetailsParserPrettyPrintk &);
};
}

#endif
